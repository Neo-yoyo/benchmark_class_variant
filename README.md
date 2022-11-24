Исследование проиpводительности класса `variant` (точнее метода `visit` для извлечения объектов из варианта)
Для исследования производительности выбраны следующие реализации класса `variant`:
1. std::variant 
2. boost::variant 
3. [boost::variant2](https://github.com/boostorg/variant2)
4. [MPark.Variant](https://github.com/mpark/variant)
5. [Mapbox Variant](https://github.com/mapbox/variant/tree/master)
6. [Eggs.Variant](https://github.com/eggs-cpp/variant)
7. [variant lite](https://github.com/martinmoene/variant-lite)


Для проведения бенчмарка использовался [`Catch2 BENCHMARK`](https://github.com/catchorg/Catch2/blob/devel/docs/benchmarks.md).
Тест очень прост: создаем три структуры с разноименными типами данных, для всех структур реализуется одноименных метод. 
Далее создаем объект каждой указанной выше библиотеки `variant` с тремя этими структурами. Создаем вектор, в который помещаем `variant` 
для удобства извлечения объектов, помещенных внутрь `variant`.
Используем метод `visit` для извлечения объевтов из `variant`.

Посмотрим результаты (было выполнено 5 замеров timerun_1 - timerun_5):

|    Variant     | timerun_1, ns |timerun_2, ns | timerun_3, ns|timerun_4, ns |timerun_5, ns |
| -------------- | ------------- | ------------ | ------------ | ------------ | ------------ |
| std::variant   | 15.3737       | 21.3076      | 13.646       | 13.8479      | 13.6256      |
| boost::variant | 15.0735       | __12.2537__  | 18.3459      | 17.7152      | 11.1639      |
| boost::variant2| 15.269        | 13.3999      | 13.7811      | __11.5957__  | 17.0516      |
| MPark.Variant  | 17.839        | 20.621       | __13.5341__  | 15.2693      | 13.4423      |
| Mapbox Variant | __14.3585__   | __10.9626__  | __8.65044__  | __8.39386__  | __9.52733__  | 
| Eggs.Variant   | 14.4445       | 16.7204      | 16.662       | 13.876       | __10.7472__  |
| Variant-lite   | __14.2645__   | 113.127      | 16.6354      | 17.2676      | 12.6374      |


Для каждого замера выделены два варианта с наилучшим временным показателем.
Как видно из таблицы, во всех случаях самым быстрым является реализация метода `visit` у библиотеки [`Mapbox Variant`](https://github.com/mapbox/variant/tree/master).
Возможно стоит подробнее изучить [`mapbox::util::apply_visitor()`](https://github.com/mapbox/variant/blob/f87fcbda9daf13fba47a6a889696b0ad23fc098d/include/mapbox/variant.hpp#L923).
Для остальных варинтов временной показатель нестабилен: наблюдаются колебания производительности.
Наибольшие колебания характерны для [`variant lite`](https://github.com/martinmoene/variant-lite)/


Для разнообразия провели бенчмарк с помощью [Google benchmark](https://github.com/google/benchmark)
Результаты (было выполнено 5 замеров time_1 - time_5):

|    Variant     | time_1, ns | time_2, ns | time_3, ns | time_4, ns | time_5, ns |
| -------------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| std::variant   | 4420       | 4412       | 4429       | 4330       | 4247       |
| boost::variant | __3077__   | __3042__   | __3050__   | __2940__   | __2933__   |
| boost::variant2| 3095       | 3379       | 3364       | 3270       | 3236       |
| MPark.Variant  | 4959       | 5135       | 5142       | 5137       | 5048       |
| Mapbox Variant | __2478__   | __2536__   | __2530__   | __2487__   | __2479__   |
| Eggs.Variant   | 3300       | 3369       | 3360       | 3315       | 3294       |
| Variant-lite   | 4012       | 4256       | 4387       | 4457       | 4296       |


Для каждого замера выделены два варианта с наилучшим временным показателем.
В данном исследовании также во всех случаях самым быстрым является реализация метода `visit` у библиотеки [`Mapbox Variant`](https://github.com/mapbox/variant/tree/master).
На втором мемте во всех пяти замерах boost::variant.
У обоих библиотек используется метод `apply_visitor()`. 




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
Исследуем производительность собственно метода `visit` для извлечения объевтов из `variant`.


Провели бенчмарк с помощью [Google benchmark](https://github.com/google/benchmark)
Результаты (было выполнено 5 замеров time_1 - time_5):

|    Variant     | time_1, ns | time_2, ns | time_3, ns | time_4, ns | time_5, ns |
| -------------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| std::variant   | 13.7       | 13.7       | 13.2       | 12.6       | 13.3       |
| boost::variant | __9.67__   | 10.0       | 9.71       | __8.32__   | 10.4       |
| boost::variant2| 10.4       | __8.12__   | __8.34__   | 10.4       | __9.86__   |
| MPark.Variant  | 10.6       | 9.49       | 9.68       | 9.42       | 10.2       |
| Mapbox Variant | __8.15__   | __8.19__   | __8.37__   | __8.72__   | __8.03__   |
| Eggs.Variant   | 12.2       | 11.4       | 12.2       | 11.9       | 12.0       |
| Variant-lite   | 13.1       | 13.2       | 13.2       | 13.1       | 13.9       |


Для каждого замера выделены два варианта с наилучшим временным показателем.
Наименьшие колебания и стабильно высокая производительность у библиотеки [`Mapbox Variant`](https://github.com/mapbox/variant/tree/master).
Также у библиотеки [boost::variant2](https://github.com/boostorg/variant2), но здесь наблюдаются бОльшие колебания.



Бенчмарк с использованием [`Catch2 BENCHMARK`](https://github.com/catchorg/Catch2/blob/devel/docs/benchmarks.md).
Посмотрим результаты (было выполнено 5 замеров timerun_1 - timerun_5):

|    Variant     | timerun_1, ns |timerun_2, ns | timerun_3, ns|timerun_4, ns |timerun_5, ns |
| -------------- | ------------- | ------------ | ------------ | ------------ | ------------ |
| std::variant   | 14.9942       | 15.0361      | 15.3433      | 15.514       | 15.0081      |
| boost::variant | 15.1825       | 15.1672      | 14.5298      | 15.1045      | 15.1137      |
| boost::variant2| __12.3487__   | __13.0017__  | __12.6393__  | __12.968__   | __12.5561__  |
| MPark.Variant  | 14.0816       | 13.8473      | 13.8739      | 13.9692      | 14.4875      |
| Mapbox Variant | __12.2017__   | __13.0904__  | __11.9863__  | __12.1251__  | __11.8957__  | 
| Eggs.Variant   | 14.597        | 14.6185      | 13.6148      | 13.9347      | 13.9558      |
| Variant-lite   | 15.499        | 16.7373      | 15.4877      | 15.1458      | 15.9116      |

Для каждого замера выделены два варианта с наилучшим временным показателем.
Как видно из таблицы, во большенстве случаев самым быстрым является реализация метода `visit` у библиотеки [`Mapbox Variant`](https://github.com/mapbox/variant/tree/master).
На втором месте [boost::variant2](https://github.com/boostorg/variant2) 

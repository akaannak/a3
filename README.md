# Анализ INTROSORT
## ID посылки: 349064981
## Github: https://github.com/akaannak/a3
### arraygenerator.hpp - генерация тестовых массивов.
### introsort.hpp - гибридный QUICK+HEAP+INSERTION SORT
### purequicksort.hpp - чистый рекурсивный QuickSort
### plot_random.png - график для случайных массивов
### plot_reverse.png - график для обратных (убывающих) массивов
### plot_almost.png - график для почти отсортированных массивов
### plots.py - построение графиков
### results_quick_pure.csv pезультаты чистого QuickSort
### results_intro.csv - результаты Introsort
### sorttester - бинарник
### sorttester.cpp - главный файл

# Немного о CSV-файлах
- results_quick_pure.csv
Содержит время работы стандартного рекурсивного QuickSort
Формат данных:
N — размер массива
random — время сортировки случайного массива
reverse — время сортировки массива, упорядоченного в обратном порядке
almost — почти отсортированный (несколько случайных перестановок)

- results_intro.csv
Содержит замеры гибридного алгоритма Introsort = QuickSort + HeapSort + InsertionSort
Формат данных аналогичный.

# Сравнительный анализ
## Random
<img width="2400" height="1200" alt="plot_random" src="https://github.com/user-attachments/assets/a9c83620-6b14-46f9-b2d1-6ab73ec49f2a" />

- оба алгоритма растут линейно O(N log N).
- Introsort немного медленнее на очень маленьких N
- после ~30 000 элементов время Introsort стабильно ниже, чем у QuickSort

Вывод: На случайных данных Introsort показывает более стабильную и предсказуемую работу. Чистый QuickSort слегка быстрее на маленьких N, но проигрывает на больших.

## Reverse
<img width="2400" height="1200" alt="plot_reverse" src="https://github.com/user-attachments/assets/1173b251-55db-46e0-a91d-f20cbcc87528" />

- чистый QuickSort превращается в O(N²)
- Introsort остаётся в диапазоне до 1500 мс

Вывод: На худшем входе Introsort полностью превосходит стандартный QuickSort. Он избегает квадратичного времени благодаря переходу на HeapSort.

## Almost sorted
<img width="2400" height="1200" alt="plot_almost" src="https://github.com/user-attachments/assets/a4a38670-d6cd-4e6c-bb8a-4e17f0d770b6" />

- чистый QuickSort снова показывает всплески из-за плохих разбиений
- Introsort работает ровно

Вывод: Даже почти отсортированные массивы могут вызвать худший случай QuickSort.

## Общий вывод
Стандартный QuickSort подходит только для случайных данных. Introsort же стабилен для всех типов входов. Он гарантирует время не хуже O(N log N), но немного медленнее на малых размерах.

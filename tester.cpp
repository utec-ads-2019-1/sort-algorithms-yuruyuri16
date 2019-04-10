#include "tester.h"
#include <iterator>

void integersBubble(void *elements, int first, int second)
{
    int *array;

    array = (int *)elements;
    if (array[first] > array[second])
    {
        swap(array[first], array[second]);
    }
}

void integersSelect(void *elements, int first, int second)
{
    int *array;
    int min_index;
    int j;

    array = (int *)elements;
    min_index = first;
    for (j = first + 1; j < second; j++)
    {
        if (array[j] < array[min_index])
        {
            min_index = j;
        }
    }
    swap(array[min_index], array[first]);
}

void integersInsert(void *elements, int first, int second)
{
    int *array;
    int x;
    int j;

    array = (int *)elements;
    x = array[first];
    j = first - 1;

    while (j >= 0 && array[j] > x)
    {
        array[j + 1] = array[j];
        j = j - 1;
    }
    array[j + 1] = x;
}

/*void integersShell(void *elements, int first, int second)
{
    int *array;
    int i;
    int currentval;
    int pos;

    array = (int *)elements;
    for (i = first + second; i < std::size(array); i = i + second)
    {
        currentval = array[i];
        pos = i;
        while (pos >= second && array[pos - second] > currentval)
        {
            array[pos] = array[pos - second];
            pos = pos - second;
        }
        array[pos] = currentval;
    }
}*/

Sort *Tester::getSort(Algorithm sort, void *array, size_t size)
{
    switch (sort)
    {
    case bubblesort:
        return new BubbleSort(array, size);
    case selectsort:
        return new SelectSort(array, size);
    case insertsort:
        return new InsertSort(array, size);
    //case shellsort:
      //  return new ShellSort(array, size);
    // case quicksort: return new QuickSort(array, size);
    // case mergesort: return new MergeSort(array, size);
    default:
        throw invalid_argument("Not a valid sort");
    }
}

fptr Tester::getCompare(Algorithm sort)
{
    switch (sort)
    {
    case bubblesort:
        return &integersBubble;
    case selectsort:
        return &integersSelect;
    case insertsort:
        return &integersInsert;
    //case shellsort:
     //   return &integersShell;
    default:
        throw invalid_argument("Not a valid comparer");
    }
}

void Tester::integerSorts(int *array, size_t size)
{
    Sort *sort;
    int temp[size];

    Algorithm algorithm[] = {bubblesort, selectsort, insertsort, /*shellsort , quicksort, mergesort*/};
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++)
    {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        sort->execute(getCompare(algorithm[i]));
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}

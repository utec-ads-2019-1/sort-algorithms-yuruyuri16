#ifndef SHELL_H
#define SHELL_H

#include "sort.h"
#include <cmath>

class ShellSort : public Sort
{
  public:
    ShellSort(void *elements, size_t size) : Sort(elements, size) {}

    void execute(void (*compare)(void *, int, int))
    {
        int gap;
        int i;

        gap = size / 2;

        while (gap > 0)
        {
            for (i = 0; i < gap; ++i)
            {
                compare(elements, i, gap);
            }
            gap = gap / 2;
        }
    }

    inline string name() { return "ShellSort"; }
};

#endif
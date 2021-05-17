#include "push_swap.h"

int already_here(int j, int i, t_stack stack)
{
    int k;

    k = -1;
    while (++k < i)
    {
        if (stack.iso[k] == j)
            return (1);
    }
    return (0);
}

void    isomorphism(t_stack *stack)
{
    int i;
    int j;
    int min;
    int min_index;

    i = -1;
    while (++i < stack->size)
    {
        min = stack->a[i];
        j = i - 1;
        while (++j < stack->size)
        {
            if (!already_here(j, i, *stack) && stack->a[j] < min)
            {
                min = stack->a[j];
                min_index = i;
            }
            stack->iso[i] = min_index;
        }

    }
}
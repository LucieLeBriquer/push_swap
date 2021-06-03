#include "push_swap.h"

void    isomorphism(t_stack *stack)
{
    int i;
    int j;
    int above;

    i = -1;
    while (++i < stack->size)
    {
        above = 0;
        j = -1;
        while (++j < stack->size)
        {
            if (stack->a[j] < stack->a[i])
                above++;
        }
        stack->copy[i] = stack->a[i];
        stack->a[i] = above;
    }
}
#include <stdio.h>



void    ft_ft(int *nbr) 
{
    *nbr = 42;
}

int main(void)
{
    int a;
    a = 3;

    ft_ft(&a);
    printf("a = %i", a);
    return a;

}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putnbr(int n)
{
    if(n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    if (n <= 9)
    {
        n += '0';
        write(1, &n, 1);
    }
}

void print_queen(int *array, int n)
{
    int i = 0;
    while (i < n)
    {
        ft_putnbr(array[i]);
        if (i + 1 != n) 
            write(1, " ", 1);
        i++;
    }
    write(1, "\n", 1);      
}


int is_valid(int *array, int linha, int coluna)
{
    int coluna_antiga = 0;
    int dist_col = 0, dist_lin = 0;
    while (coluna_antiga != coluna)
    {
        if (linha == array[coluna_antiga])
            return 0;
        dist_col = coluna - coluna_antiga;
        dist_lin = linha - array[coluna_antiga];
        if (dist_lin < 0)
            dist_lin *= -1;
        if (dist_lin == dist_col)
            return 0;
        coluna_antiga++;
    }
    return 1;
}


void n_queen(int *array, int linha, int coluna, int n)
{
    if (coluna == n)
    {
        print_queen(array, n);
        return; 
    }
    linha = 0;
    while (linha < n)
    {
        if (is_valid(array, linha, coluna))
        {
            array[coluna] = linha;
            n_queen(array, linha, coluna + 1, n);
        }
        linha++;
    }
    
    
}

int main (int ac, char **av)
{
    if (ac != 2)
        return 0;
    int *array = malloc(atoi(av[1]) * sizeof(int)), i = 0;
    int n = atoi(av[1]);
    while(i < n)
    {
        array[i] = -1;
        n--;
        i++;
    }
    n = atoi(av[1]);
    n_queen(array, 0, 0, n);
}
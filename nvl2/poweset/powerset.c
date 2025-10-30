
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int ac, char **av)
{
    int alvo = atoi(av[1]);
    int *array;
    int i = 0;
    int tam = ac - 2;
    array = malloc(tam * sizeof(int));
    int *aux_array = malloc(tam*sizeof(int));
    while (i < tam)
    {
        array[i] = av[i + 2];
        i++;
    }
    

}
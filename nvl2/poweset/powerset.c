
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



void print_arr(int *aux_array, int tam)
{
    int i = 0;
    while (i < tam)
    {
        printf("%d", aux_array[i]);
        if (i == tam -1 )
            printf("\n");
        else
            printf(" ");
        i++;
    }
    
}

void powerset(int alvo, int *array, int tam_array, int *aux_array, int aux_tam,int indice, int soma)
{
    if (indice == tam_array)
    {   
        if (alvo == soma)
        {
            print_arr(aux_array, aux_tam);
            return ;
        }
        return ;
    }
    aux_array[aux_tam] = array[indice];
    powerset(alvo, array, tam_array, aux_array, aux_tam + 1, indice + 1, soma + array[indice]);
    powerset(alvo, array, tam_array, aux_array, aux_tam, indice + 1, soma);
}

int main(int ac, char **av)
{
    int alvo = atoi(av[1]);
    int *array;
    int i = 0;
    int tam = ac - 2;
    array = malloc(tam * sizeof(int));
    int *aux_array = malloc(tam*sizeof(int));
    if (alvo == 0)
        printf("\n");
    while (i < tam)
    {
        array[i] = atoi(av[i + 2]);
        i++;
    }
    powerset(alvo, array, tam, aux_array, 0, 0, 0);
}
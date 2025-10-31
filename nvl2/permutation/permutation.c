#include <stdio.h>
#include <stdlib.h>

int len(char *s)
{
    if(!s)
        return 0;
    int i = 0;
    while (s[i])
        i++;
    return i;
}

void sort_string(char *str, int n)
{
    int i = 0, j = 0;
    char tmp;
   
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (str[j] > str[j+1])
            {
                tmp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tmp;
            }
        }
}


int main(int ac, char **av)
{
    if (ac != 2) return 1;
    char *test = av[1];
    printf("%s\n", test);
    int tam;
    sort_string(test, tam =(len(test)));
    printf("%s", test);
}
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
\


#define BUFFER_SIZE 1024


char *join (char *s1, char *s2)
{
    char *result;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i = 0, j = 0;

    result = malloc(len1 + len2 + 1);
    if (!s1)
        len1 = 0;

    while (s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';

    return result;
}

char *my_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    return NULL;
}

char *read_line(int fd, char *line)
{
    char buffer[BUFFER_SIZE];
    int ret_read;

    if(!line)
        line = malloc(1);

    while ((ret_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (ret_read < 0)
        {
            free(line);
            return NULL;
        }
        buffer[ret_read] = '\0';
        line = join(line, buffer);
        if (my_strchr(buffer, '\n'))
            break;
    }
    return line;
}

char *get_line(char *line)
{
    char *get_line;
    int i = 0;

    while (line[i] != '\n' && line[i] != '\0')
        i++;
    if(line[i] == '\n')
        get_line = malloc(i + 2);
    else
        get_line = malloc(i + 1);
    i = 0;
    while(line[i])
    {
        get_line[i] = line[i];
        i++;
    }
    if (line[i] == '\n')
        get_line[i] = '\n';
    return get_line;
}

char *rest_line(char *line)
{
    int i = 0;
    char *temp;
    char *rest;


    while (line[i] != '\n' && line[i])
        i++;
    if (line[i] == '\0')
    {
        free(line);
        return NULL;
    }
    temp = line + i + 1;
    rest = strdup(temp);
    free(line);
    return rest;
}



char *get_next_line(int fd)
{
    static char *line;
    char *return_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    line = read_line(fd, line);
    if(!line)
        return NULL;
    return_line = get_line(line);
    line = rest_line(line);
}
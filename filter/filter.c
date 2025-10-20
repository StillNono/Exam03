#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

int ft_strstr(char *str, char *compare)
{
	int i = 0;
	int j = 0;

	//len_compare = ft_strlen(compare);
	while (str[i] )
	{
		while (str[i + j] == compare[j] && str[i + j])
		{
			if (compare[j + 1] == '\0')
				return i;
			j++;
		}
		i++;
	}

	return -1;
}
//trasnformar tudo dda string enquanto for igual ao compare em *

void transform(char *str, int len)
{
	int i = 0;
	while (i < len)
	{
		str[i] = '*';
		i++;
	}
}

char *super_strstr(char *str, char *compare)
{
	int offset = 0;
	int found_index;
	int compare_len = ft_strlen(compare);

	if (compare_len == 0)
		return str;

	while ((found_index = ft_strstr(&str[offset], compare)) != -1)
	{
		int real_index = offset + found_index;
		transform(&str[real_index], compare_len);
		offset = real_index + compare_len;
	}
	return str;
}

char *join(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int len1 = 0;
	int len2 = 0;

	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);

	char *result = malloc(sizeof(char) * (len1 + len2 + 1));
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

char *filter(void)
{
	char buffer[1024], *result;
	int bytes;
	char *temp_result;
	result = malloc(1);

	result[0] = '\0';

	while((bytes = read(0, buffer, 1024 -1)) > 0)
	{
		buffer[bytes] = '\0';
		temp_result = join(result, buffer);
		free(result);
		result = temp_result;
		if (!result)
		{
			perror("Failed to allocate memory");
			exit(EXIT_FAILURE);
		}
	}
	if (*result == '\0')
	{
		result = malloc(1);
		if (result) result[0] = '\0';
	}
	return result;
}

int main (int argc, char **argv)
{
	if (argc != 2)
		return (0);

	char *s, *s_final;
	s = filter();
	//printf("%s\n", s);
	s_final = super_strstr(s,argv[1]);
	printf("%s", s_final);
	free(s);
	//free(s_final);
	return 0;
}

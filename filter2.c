/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:40:46 by ancarlos          #+#    #+#             */
/*   Updated: 2025/10/20 16:33:34 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int ft_strstr(char *s1, char *compare)
{
	int i = 0, j = 0;
	printf("erro strstr\n");
	while (s1[i])
	{
		while (s1[i + j] == compare[j] && s1[i + j])
		{
			if (compare[j + 1] == '\0')
				return i;
			j++;
		}
		i++;
	}
	return -1;
}

int len(char *str)
{
	int i = 0;
	printf("erro len\n");
	while (str[i])
	{
		i++;
	}
	return i;
}

void transforme(char *str, int len)
{
	int i = 0;
	while (str[i] && i < len)
	{
		str[i] = '*';
		i++;
	}

}

char *super_strstr(char *str, char *compare)
{
	int offset = 0, found_index = 0, len_compare = 0;
	len_compare = len(compare);
	printf("erro super\n");
	while ((found_index = ft_strstr(&str[offset],compare)) != -1)
	{
		offset += found_index;
		transforme(&str[offset],len_compare);
		offset += len_compare;
	}
	return str;
}


char *join(char *s1, char *s2)
{
	int len1 = 0,  len2 = 0;
	int i = 0, j = 0;
	char *str_ret;

	if (!s1)
		len1 = 0;
	else
		len1 = strlen(s1);
	len2 = strlen(s2);
	str_ret = malloc(len1 + len2 + 1);
	printf("erro join\n");
	while (i < len1)
	{
		str_ret[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		str_ret[i + j] = s2[j];
		j++;
	}
	free(s1);
	str_ret[i + j] = '\0';
	return str_ret;
}

char *filter (void)
{
	char buffer[1024], *result;
	int	bytes = 0;
	char	*temp_result;

	result = malloc(1);
	while ((bytes = read(0, buffer, 1023)) > 0)
	{
		buffer[bytes] = '\0';
		temp_result = join(result, buffer);
		//free(result);
		if (!temp_result)
		{
			perror("Erro to alocate memory");
			exit(1);
		}
		if (*result == '\0')
		{
			result = malloc(1);
			if (result) result[0] = '\0';
		}
	}
	printf("\naaa%s", result);
	return temp_result;
}

int main(int ac, char **av)
{
	printf("a\n");
	if (ac != 2)
		return 0;
	char *str, *s_final;
	str = filter();
	s_final = super_strstr(str, av[1]);
	printf("%s", str);
	//free(str);
	return 0;
}

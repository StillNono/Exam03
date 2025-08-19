#include <stdio.h>


int ft_strstr(char *str, char *compare)
{
	int i = 0;
	int j = 0;
	int count = 0;

	//len_compare = ft_strlen(compare);
	while (str[i] )
	{
		if (str[i] == compare[j] && compare[j])
		{
			j++;
			if (count == 0)
				count = i;
		}
		else
		{
			if (!compare[j])
				return count;
			j = 0;
			count = 0;
		}
		i++;
	}

	return -1;
}
//trasnformar tudo dda string enquanto for igual ao compare em *
void transform(char *str, char *compare)
{
	int i = 0;
	int j = 0;

	while (str[i])
	{
		if (str[i] == compare[j] && compare[j])
		{
			str[i] = '*';
			j++;
		}
		else
			j = 0;
		i++;
	}
}

char *super_strstr(char *str, char *compare)
{
	int i_ptr= 0;
	while(i_ptr != -1)
	{
		i_ptr = ft_strstr(&str[i_ptr], compare);
		transform(&str[i_ptr], compare);
	}
	return str;
}

int main (int argc, char **argv)
{
	if(argc != 3)
		return (0);

	char *s;
	s = super_strstr(argv[1],argv[2]);
	printf("%s", s);

}

#include "minishell.h"

void ft(char **test)
{
	// char *t = ft_calloc(1 , s);
	for (int i = 0; i < 6; i++)
		test[i] = "hmara";
	// return test;
}

int main()
{
	char **test = calloc(6 , sizeof(char *));
	// char *t = ft_calloc(1 , s);
	ft(test);
		for (int i = 0; i < 6; i++)
			printf("{%s}\n", test[i]);
	// i = 0;
	// tmp = NULL;
	// test = getcwd(NULL, 0);
	// printf("pwd = [%s]\n" , test);

	// system("leaks a.out");
}

#include "minishell.h"
int main()
{
	char *test;

	// i = 0;
	// tmp = NULL;
	test = getcwd(NULL, 0);
	printf("pwd = [%s]\n" , test);
	// system("leaks a.out");
}

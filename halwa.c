#include "minishell.h"
int main()
{
	char *s = NULL;
	s = malloc(4);
	printf("{%s}", s);
	printf("{%s}", s);
	free(s);
	s = NULL;
	printf("{%s}", s);

	system("leaks a.out");
}

#include "minishell.h"
int main()
{
	char *s = NULL;
	s = malloc(4);
	// s[0] = '1';
	// s[1] = '2';
	// s[2] = 'h';
	// s[3] = '4';
	//printf("{%s}", s);
	printf("{befor => %s}\n", s);
	free(s);
	s = NULL;
	printf("{after => %s}\n", s);

	system("leaks a.out");
}

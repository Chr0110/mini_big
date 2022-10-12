#include "../minishell.h"

int	ft_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		if ((*s != c && len == 0) || (*s != c && *(s - 1) == c))
			len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		end;
	int		index;
	int		start;

	end = 0;
	start = 0;
	index = 0;
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (ft_len(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (index < ft_len(s, c))
	{
		while (s[end] == c && s[end])
			end++;
		start = end;
		while (s[end] != c && s[end])
			end++;
		ptr[index] = ft_substr(s, start, end - start);
		index++;
	}
	ptr[index] = NULL;
	return (ptr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
	}
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (ptr);
	while (s[start] && i < len && start <= ft_strlen(s))
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}

// char	*ft_strdupp(char *s1)
// {
// 	char	*ptr;
// 	int		i;

// 	i = 0;
// 	ptr = malloc((ft_strlen(s1) + 1) * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		ptr[i] = s1[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int ft_strcmp(char *s1, char *s2)
{
	int i;
	i = 0;
	while(s1[i]&&s2[i]&&s1[i]==s2[i])
		i++;
	return s2[i] - s1[i];
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*ss1;
// 	unsigned char	*ss2;

// 	i = 0;
// 	ss1 = (unsigned char *)s1;
// 	ss2 = (unsigned char *)s2;
// 	while ((ss1[i] || ss2[i]) && i < n)
// 	{
// 		if (ss1[i] != ss2[i])
// 			return (ss1[i] - ss2[i]);
// 		i++;
// 	}
// 	return (0);
// }

void	ft_free(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, " ", 1);
	return ;
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_isalpha(int c)
{
	if (!((c >= 'A' && c <= 'Z' ) || (c >= 'a' && c <= 'z')))
		return (0);
	return (1);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *) malloc((ft_strlen (s1) + ft_strlen (s2) + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	else
		ft_strcpy (ptr, s1);
	ft_strcat (ptr, s2);
	return (ptr);
}
char	*ft_strcat(char	*s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
char	*ft_strcpy(char	*dst,	char	*src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
int	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return 0;
		s++;
	}
	if (c == '\0')
	{
		return 1;
	}
	return 1;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	char	*big;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		big = (char *)haystack + i;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				if (needle[j + 1] == '\0')
					return (big);
				j++;
			}
			big = 0;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	int		j;
	char	*big;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		big = (char *)haystack + i;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + j] == needle[j])
			{
				if (needle[j + 1] == '\0')
					return (big);
				j++;
			}
			big = 0;
		}
		i++;
	}
	return (NULL);
}

static int	ft_lenght(int n)
{
	long	len;
	long	num;

	len = 0;
	num = n;
	if (n < 0)
	{
		num = num * (-1);
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_zero(char *p)
{
	p = NULL;
	p = malloc(2 * sizeof(char));
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long int	num;
	long int	len;

	ptr = NULL;
	len = ft_lenght(n);
	if (n == 0)
		return (ft_zero(ptr));
	ptr = malloc ((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	num = n;
	if (n < 0)
	{
		ptr[0] = '-';
		num = num * (-1);
	}
	while (len-- > 0 && num > 0)
	{
		ptr[len] = num % 10 + '0';
		num = num / 10;
	}
	return (ptr);
}
void	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		return ;
	}
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int	count_list(t_b_l *lst)
{
	t_b_l *sv;
    int len = 0;

	sv = lst;
    if(!lst)
    	return 0;
    while(lst)
    {
        len++;
        lst = lst->next;
    }
	lst = sv;
    return len;
}

// int	count_lil(t_p_l *lst)
// {
// 	t_p_l *sv;
//     int len = 0;

// 	sv = lst;
//     if(!lst)
//     	return 0;
//     while(lst)
//     {
//         len++;
//         lst = lst->next;
//     }
// 	lst = sv;
//     return len;
// }
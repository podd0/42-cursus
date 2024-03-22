#include <ctype.h>
#include <stdio.h>
#include "/home/andrea/42/libft/libft.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>


// static size_t	ft_strnlen(const char *s, size_t n)
// {
// 	char	*t;

// 	t = (char *)ft_memchr(s, 0, n);
// 	if (t == NULL)
// 		return (n);
// 	return (t - s);
// }

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	for(int i = 0; i< 255; i++)
	{
		assert((ft_isalpha(i) && 1) ==  (isalpha(i) && 1));
		assert((ft_isdigit(i) && 1) ==  (isdigit(i) && 1));
		assert((ft_isalnum(i) && 1) ==  (isalnum(i) && 1));
		assert((ft_isprint(i) && 1) ==  (isprint(i) && 1));
		assert((ft_isascii(i) && 1) ==  (isascii(i) && 1));
		assert(ft_toupper(i) == toupper(i));
		assert(ft_tolower(i) == tolower(i));
	}

	#ifdef __APPLE__
	char big[100], small[100];
	char big2[100], small2[100];
	char big3[100];
	while(1)
	{
		fgets(big, 100, stdin);
		fgets(small, 100, stdin);



		big[ft_strnlen(big, 100)-1] = '\0';
		small[ft_strnlen(small, 100)-1] = '\0';
		int x = strlcpy(big2, big, 100);
		int y = ft_strlcpy(big3, big, 100);
		assert(strcmp(big3, big2) == 0);
		assert(x == y);
		assert(ft_strncmp(big, big2, 100) == 0);
		assert(ft_strncmp(small, small2, 100) == 0);
		x = ft_strlcat(big, small, 100);
		y = strlcat(big2, small2, 100);
		assert(x == y);
		assert(strncmp(big2, big, 100) == 0);
	}
	#endif

	int x = 0;
	puts("test for itoa");
	while(x != 6969)
	{
		scanf("%d", &x);
		puts(ft_itoa(x));
		fflush(stdout);
	}
	
	ft_putendl_fd("test test test", 1);
	printf("all ok\n");
}
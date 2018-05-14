#include "libft.h"

char	*ft_strncpynp(char *dst, const char *src, size_t len)
{
	int i;
	int a;

	i = 0;
	a = len;

	while (i < a)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

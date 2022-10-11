#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize - 1 && src[i] && dstsize)
	{
		dst[i] = (char)src[i];
		i++;
	}
	if (dstsize)
		dst[i] = 0;
	return (ft_strlen(src));
}

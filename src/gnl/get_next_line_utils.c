#include "../../include/pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(s1) + 1;
	s = malloc(len * sizeof(char));
	if (!s)
		return (NULL);
	while (++i < len)
		s[i] = s1[i];
	return (s);
}

char	*gnl_ft_strjoin(char const *s1, char const *s2, int flag)
{
	char	*str;
	int		i;
	size_t	s1_length;
	size_t	s2_length;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	i = -1;
	str = malloc(s1_length + s2_length + 1);
	if (!str)
		return (NULL);
	while (++i < (int)s1_length)
		str[i] = s1[i];
	i = -1;
	while (++i < (int)s2_length)
		str[i + s1_length] = s2[i];
	str[i + s1_length] = 0;
	if (flag == 1 || flag == 3)
		free((char *)s2);
	if (flag == 2 || flag == 3)
		free((char *)s1);
	return (str);
}

int	get_newline_pos(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != 0)
		if (buffer[i++] == '\n')
			return (i);
	return (i);
}

int	has_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != 0)
		if (buffer[i++] == '\n')
			return (1);
	return (0);
}

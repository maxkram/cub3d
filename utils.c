#include "./cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	x;

	x = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (x < count * size)
	{
		str[x] = 0;
		x++;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

#include "./cub3d.h"

// void ft_error(const char *message, int exit_status) {
//     printf("Error: %s\n", message);
//     exit(exit_status);
// }

int	test_cub(char *map)
{
	size_t	i;

	i = ft_strlen(map);
	if (i <= 4)
		return (1);
	if (map[i - 1] == 'b' && map[i - 2] == 'u' && map[i - 3] == 'c' && map[i - 4] == '.')
		return (0);
	return (1);
}

t_game	*init_game(char *arg, t_parse *parse)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	init_struct(game, arg, parse);
	printf("Creating the data structure\n");
	return (game);
}

int main(int ac, char **av)
{
	t_parse *parse;

	if (ac != 2)
	{
		printf("Error\n");
		return (0);
	}
}
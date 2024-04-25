#include "./cub3d.h"

int	free_struct(t_parse *parse)
{
	if (parse->texture_ea != NULL)
		free(parse->texture_ea);
	if (parse->texture_no != NULL)
		free(parse->texture_no);
	if (parse->texture_so != NULL)
		free(parse->texture_so);
	if (parse->texture_we != NULL)
		free(parse->texture_we);
	if (parse->value_rgb_c != NULL)
		free(parse->value_rgb_c);
	if (parse->value_rgb_f != NULL)
		free(parse->value_rgb_f);
	free(parse);
	return (1);
}

bool	start_parsing(int ac, char **av, t_parse *parse)
{
	int	error_files;
	int	fd;

	fd = 0;
	if (ac != 2)
		return (error(error_arg));
	fd = open(av[1], O_RDONLY);
	if (fd < 2)
		return (error(wrong_file));
	error_files = check_file(fd, av[1], parse);
	if (error_files != no_problem)
		return (error(error_files));
	error_files = check_file_rgb(open(av[1], O_RDONLY), parse);
	if (error_files != no_problem)
		return (error(error_files));
	error_files = check_wrong_line(open(av[1], O_RDONLY));
	if (error_files != no_problem)
		return (error(error_files));
	error_files = check_map(open(av[1], O_RDONLY), parse, av[1]);
	if (error_files != no_problem)
		return (error(error_files));
	return (true);
}
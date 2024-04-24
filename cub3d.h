#ifndef CUB3D_H
#define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "parsing.h"
# include "./MLX42.h"

typedef struct game
{
    void    *mlx_ptr;
}   t_game;

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);

#endif
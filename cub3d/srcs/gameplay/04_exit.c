/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:21:46 by kpourcel          #+#    #+#             */
/*   Updated: 2025/01/14 15:42:31 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	free_texture(t_game *game)
{
	if (!game || !game->texture)
		return ;
	free(game->texture);
	game->texture = NULL;
}

void	free_other_resources(t_game *game)
{
	if (game->dda)
	{
		free(game->dda);
		game->dda = NULL;
	}
	if (game->col_data)
	{
		free(game->col_data);
		game->col_data = NULL;
	}
	if (game->rendcoldata)
	{
		free(game->rendcoldata);
		game->rendcoldata = NULL;
	}
}

void	cleanup_ressources_two(t_game *game)
{
	if (!game)
		return ;
	free_texture(game);
	free_other_resources(game);
}

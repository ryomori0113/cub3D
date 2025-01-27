/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 04:14:10 by yyamasak          #+#    #+#             */
/*   Updated: 2025/01/27 13:58:30 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// TODO change position, direction, plane parameter based on arguments
void	_init_player(t_player *player, int x, int y)
{
	player->pos.x = (double)player->init_userpos_x + 0.5;
	player->pos.y = (double)player->init_userpos_y + 0.5;
	player->dir.x = 0.0;
	player->dir.y = -1.0;
	player->plane.x = 0.66;
	player->plane.y = 0;
	player->side_flg = 0;
	player->approx_flg = 0;
	player->rotate_flg = 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:52:54 by yyamasak          #+#    #+#             */
/*   Updated: 2025/02/05 22:52:57 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// DDA algo
static void	_calc_hit_pos_(t_params *params, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (params->map[ray->map.y][ray->map.x] == '1'
			|| params->map[ray->map.y][ray->map.x] == '2')
			ray->hit = 1;
	}
}

static double	calc_wall_distance_(t_ray *ray)
{
	double	dis;

	if (ray->side == 0)
		dis = ray->side_dist.x - ray->delta_dist.x;
	else
		dis = ray->side_dist.y - ray->delta_dist.y;
	return (dis);
}

void	_raycast(t_params *params)
{
	t_data		*data;
	t_player	*player;
	t_ray		*ray;
	t_ivec		coord;
	t_wall		wall;

	data = &(params->data);
	player = &(params->player);
	ray = &(params->ray);
	coord.x = 0;
	while (coord.x < data->img.width)
	{
		_ray_assign(ray, data, player, &coord);
		_calc_hit_pos_(params, ray);
		ray->perp_wall_dist = calc_wall_distance_(ray);
		_wall_assign(&wall, data, ray, player);
		_draw_vertical(data, &coord, &wall);
		coord.x++;
	}
}

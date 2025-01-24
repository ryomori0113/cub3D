/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:02:04 by yyamasak          #+#    #+#             */
/*   Updated: 2025/01/24 15:59:18 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	_move_by_key_(int keycode, t_params *param)
{
	t_player *player;
	double move_speed = 0.5; // 移動速度（調整可能）

	player = param->player;

	if (keycode == KEY_W)
		player->approx_flg = 1;
	if (keycode == KEY_S)
		player->approx_flg = -1;
	if (keycode == KEY_A)
		player->side_flg = -1;
	if (keycode == KEY_D)
		player->side_flg = 1;
	if (keycode == KEY_R_DIR)
		player->rotate_flg = 1;
	if (keycode == KEY_L_DIR)
		player->rotate_flg = -1;
	return (0);
}

int	_key_hook(int keycode, void *arg)
{
	t_data	*data;
	t_params *params;

	params = (t_params *)arg;
	data = (t_data *)(params->data);
	if (keycode == KEY_ESC)
		_close_window(params);
	else if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D
		|| keycode == KEY_R_DIR || keycode == KEY_L_DIR)
		_move_by_key_(keycode, params);
	else
		return (0);
	return (0);
}

int		_key_release_hook(int keycode, t_params *param)
{
	t_player *player;

	player = param->player;
	if (keycode == KEY_W || keycode == KEY_S)
		player->approx_flg = 0;
	if (keycode == KEY_A || keycode == KEY_D)
		player->side_flg = 0;
	if (keycode == KEY_R_DIR || keycode == KEY_L_DIR)
		player->rotate_flg = 0;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_interface.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:51:44 by yyamasak          #+#    #+#             */
/*   Updated: 2025/02/06 14:03:06 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static int	check_all_settings_(t_params *params)
{
	if (!params->data.tex_north.path)
		return (ft_printf_fd(ERR_FD, "Error\n%s%s\n", ERR2, ERR_NOPATH));
	if (!params->data.tex_south.path)
		return (ft_printf_fd(ERR_FD, "Error\n%s%s\n", ERR2, ERR_NOPATH));
	if (!params->data.tex_west.path)
		return (ft_printf_fd(ERR_FD, "Error\n%s%s\n", ERR2, ERR_NOPATH));
	if (!params->data.tex_east.path)
		return (ft_printf_fd(ERR_FD, "Error\n%s%s\n", ERR2, ERR_NOPATH));
	if (params->data.ceilling_color == -1)
		return (ft_printf_fd(ERR_FD, "Error\n%s%s\n", ERR2, ERR_NOCOLOR));
	if (params->data.floor_color == -1)
		return (ft_printf_fd(ERR_FD, "Error\n%s%s\n", ERR2, ERR_NOCOLOR));
	return (0);
}

int	_parse_map(char **line, t_params *params)
{
	int	start_index;

	start_index = _parse_map_settings(line, params);
	if (check_all_settings_(params))
		return (1);
	if (start_index < 0)
		return (1);
	if (_parse_map_data(line, start_index, params))
		return (1);
	if (params->player.init_userpos_x == -1)
		return (ft_printf_fd(ERR_FD, "Error\n%s%s\n", ERR2, ERR_NOPLAYER));
	return (0);
}

#include "utils.h"

int	main_loop(void *arg)
{
	t_params	*params;
	t_data		*data;
	t_player	*player;

	params = (t_params *)arg;
	data = &(params->data);
	player = &(params->player);
	if (data->mlx && data->win && data->img.img)
		ft_bzero(data->img.addr, data->img.llen * data->img.height);
	_update_player(params, player);
	_raycast(params);
	if (data->mlx && data->win && data->img.img)
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	*params;

  if (argc == 1)
  {
    write(1, "need arguments\n", 15);
    return (1);
  }
  if (argc != 2)
  {
    write(1, "too many arguments\n", ft_strlen("too many arguments\n"));
    return (1);
  }
	params = _init_params();
	_parse(argv[1], params);
	_init_data(&(params->data));
	_init_player(&(params->player));
	set_event(&(params->data), params);
	mlx_loop_hook(params->data.mlx, &main_loop, (void *)params);
	mlx_loop(params->data.mlx);
	return (0);
}
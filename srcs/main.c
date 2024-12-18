/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:10:44 by npirard           #+#    #+#             */
/*   Updated: 2024/11/28 13:31:02 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt/minirt.h>
#include <minirt/parsing.h>
#include <minirt/raytracing.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <libft.h>
#include <math.h>
#include <minirt/calculus.h>

static int	display_init(t_data *data)
{
	img_update(data);
	img_update_chunk(data);
	data->win = mlx_new_window(data->mlx, data->win_size.x,
			data->win_size.y, "MiniRT");
	if (!data->win)
		handle_close(data);
	return (0);
}

static void	 data_init(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		handle_close(data);
	data->win_size.x = DFT_SIZE_X;
	data->win_size.y = DFT_SIZE_Y;
	data->img_chunk_size = DFT_IMG_CHUNK_SIZE;
	data->threads_nbr = DFT_NBR_THREADS;
	data->scene.data = data;
	data->scene.camera.dir = (t_vec3f){1, 0, 0};
	data->scene.camera.fov = 70 * ((2 * M_PI) / 360.f);
	data->scene.ambiant_light.ratio = 0.2;
	data->scene.ambiant_light.color = (t_color3f){255, 255, 255};
	pthread_mutex_init(&data->thread_mutex, NULL);
}

static int	hook_init(t_data *data)
{
	mlx_hook(data->win, ButtonPress, ButtonPressMask,
		event_button_press, data);
	mlx_hook(data->win, ButtonRelease, ButtonReleaseMask,
		event_button_release, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, event_key_release, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask,
		event_mouse_move, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, handle_close, data);
	mlx_hook(data->win, ConfigureNotify, StructureNotifyMask,
		handle_resize, data);
	mlx_loop_hook(data->mlx, render, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_putendl_fd("wrong number of arguments", 2), 0);
	data_init(&data);
	if (scene_open(argv[1], &data.scene) || display_init(&data)
		|| hook_init(&data))
		handle_close(&data);
	normalize_scene(&data.scene);
	init_camera(&data);
	translate_scene(&data, &data.scene.camera.origin);
	t_scene_print(&data.scene);
	transform_scene(&data, &data.scene.matrix, 0.0);
	mlx_loop(data.mlx);
	handle_close(&data);
	return (0);
}

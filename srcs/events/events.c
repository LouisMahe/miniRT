/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:19:17 by npirard           #+#    #+#             */
/*   Updated: 2024/02/26 13:33:13 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <minirt/minirt.h>

int	event_button_press(int keycode, int x, int y, t_data *data)
{
	if (keycode == Button1)
	{
		data->mouse_pressed = true;
		data->dnd.x = x;
		data->dnd.y = y;
	}
	else if (keycode == Button4 || keycode == Button5)
		handle_zoom(data, keycode);
	return (0);
}

int	event_button_release(int keycode, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (keycode == Button1)
		data->mouse_pressed = false;
	else if (keycode == Button3)
		return (0);
	return (0);
}

int	event_mouse_move(int x, int y, t_data *data)
{
	if (data->mouse_pressed)
	{
		data->dnd.x -= x;
		data->dnd.y -= y;
		handle_rotation(data);
		data->dnd.x = x;
		data->dnd.y = y;
	}
	return (0);
}

int	event_key_release(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		handle_close(data);
	else if (keycode == XK_Right || keycode == XK_Left
		|| keycode == XK_Up || keycode == XK_Down)
		handle_pan(data, keycode);
	else if (keycode == 58 || keycode == XK_bracketleft
		|| keycode == 33 || keycode == XK_bracketright)
		handle_threads_nbr(keycode, data);
	else if (keycode == 61 || keycode == XK_minus)
		handle_chunk_size(keycode, data);
	return (0);
}

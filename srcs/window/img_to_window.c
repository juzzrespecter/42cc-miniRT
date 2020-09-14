/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:21:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/14 20:28:53 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// (WINDOW)
//
//get all cam imgs
//window mgmt (keyboard, mouse)
//img_to_window

void img_to_window(t_cam *cam_lst, t_rtindex *index)
{
	void *win_ptr;
	t_data *data;

	data = index->data;
	win_ptr = mlx_new_window(data->mlx_ptr, data->res_x, data->res_y, "miniRayTracer scene");
	data->win_ptr = win_ptr;
	mlx_key_hook(win_ptr, &window_press_esc, index);
	mlx_mouse_hook(win_ptr, &window_click_exit, index);
	mlx_key_hook(win_ptr, &window_change_cam, index);
	mlx_put_image_to_window(data->mlx_ptr, win_ptr, cam_lst->img_ptr, 0, 0);
	mlx_loop(data->mlx_ptr);	
}

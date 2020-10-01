/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 21:14:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 21:14:41 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# define PREV_CAM 123
# define NEXT_CAM 124
# define ESC_KEY 53

void	img_to_window(t_rt *index);
int		window_key_options(int key, t_rt *index);
int		window_change_cam(int key, t_rt *index);
void	window_generate_images(t_rt *index);

#endif

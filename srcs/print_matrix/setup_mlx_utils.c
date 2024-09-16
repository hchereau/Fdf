/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:14:40 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/16 15:14:48 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_tab_keys_vue(t_display *display)
{
	display->keys[15].keycode = I_KEY;
	display->keys[16].keycode = P_KEY;
	display->keys[17].keycode = N_KEY;
}

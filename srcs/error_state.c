/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:51:17 by imback            #+#    #+#             */
/*   Updated: 2024/08/14 16:48:24 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(int signal)
{
	perror(strerror(signal));
}

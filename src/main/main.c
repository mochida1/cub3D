/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:02:44 by hmochida          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/18 21:13:29 by viferrei         ###   ########.fr       */
=======
/*   Updated: 2023/01/14 18:56:11 by hmochida         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_raw_map	*map;

	map = init_map("map.cub");
	map = detroy_map(map);

	(void) argc;
	(void) argv;
}

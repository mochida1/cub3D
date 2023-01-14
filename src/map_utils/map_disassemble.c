/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_disassemble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:13:50 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/14 18:53:57 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_defs.h"
#include "cub3d.h"

/*
	Splits raw map data loaded in memmory into unparsed configs strings and
	unparsed layout strings
*/
void	map_disassemble(t_raw_map *map)
{
	get_map_raw_layout(map);
}

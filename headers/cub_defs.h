/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:09:00 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/10 21:10:53 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DEFS_H
# define CUB_DEFS_H

typedef struct s_raw_map
{
	char	**raw_map_data;
	unsigned int	raw_map_size;
	unsigned int	raw_map_max_len;
}	t_raw_map;


#endif // CUB_DEFS_H

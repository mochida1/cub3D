/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:17:31 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/10 21:10:45 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_UTILS_H
# define CUB_UTILS_H

void	*safe_free(void *content);
void	*free_string_array(char	**pp);

#endif //CUB_UTILS_H

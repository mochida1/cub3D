/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:17:31 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/21 20:42:33 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_UTILS_H
# define CUB_UTILS_H

void	*safe_free(void *content);
void	*free_string_array(char	**pp);
int		ft_strcmp(char *str, char *str2);

#endif //CUB_UTILS_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_strrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:48:14 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/28 16:48:16 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Ugly workaround to make return values easier to deal with :)
	Searches for 'c' in 'str',
	returns 0 if 'c' is contained in 'str' otherwise 1.
*/
int	int_strrchr(const char *str, char c)
{
	while (*str != 0)
	{
		if (*str == (char)c)
			return (0);
		str++;
	}
	return (1);
}

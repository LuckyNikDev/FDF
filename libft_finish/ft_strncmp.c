/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:19:00 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/22 19:50:24 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*one;
	unsigned char	*two;
	size_t			i;

	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (one[i] != two[i])
			return (one[i] - two[i]);
		if (one[i] == '\0' && two[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

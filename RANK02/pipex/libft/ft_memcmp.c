/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:18:02 by pkhienko          #+#    #+#             */
/*   Updated: 2024/08/31 17:51:17 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			idx;

	idx = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (idx < n)
	{
		if (*(str1 + idx) == *(str2 + idx))
			idx++;
		else
			return (*(str1 + idx) - *(str2 + idx));
	}
	return (0);
}

// int main()
// {
// 	const char *s1 = "Hello";
// 	const char *s2 = "H llo";

// 	printf("%d\n",ft_memcmp(s1, s2, 2));
// 	printf("%d",memcmp(s1, s2, 2));
// }

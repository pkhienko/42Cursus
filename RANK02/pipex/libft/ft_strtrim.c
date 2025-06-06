/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:21:46 by pkhienko          #+#    #+#             */
/*   Updated: 2024/09/13 00:27:44 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	l;
	int	r;

	if (!s1 || !set)
		return (NULL);
	l = 0;
	r = ft_strlen(s1) - 1;
	while (s1[l] && ft_strchr(set, s1[l]))
		l++;
	while (s1[l] && ft_strchr(set, s1[r]))
		r--;
	return (ft_substr(s1, l, r - l + 1));
}

// int main()
// {
// 	char *str = "    -'      ++ Hello +++++++++";

// 	str = ft_strtrim(str, "+ -'");
// 	printf("%s\n", str);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:15:51 by khestia           #+#    #+#             */
/*   Updated: 2021/12/11 16:57:44 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/keys.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s2;
	const char	*s1;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	s2 = (char *)dst;
	s1 = (const char *)src;
	if (src < dst)
	{
		while (len--)
			s2[len] = s1[len];
	}
	else
	{
		while (i < len)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	if (n == 0)
		return (0);
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && s11[i] == s22[i] && s11[i] && s22[i])
		i++;
	if (s11[i] == s22[i])
		return (0);
	else
		return (s11[i] - s22[i]);
}

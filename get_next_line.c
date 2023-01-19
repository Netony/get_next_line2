/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:22:08 by dajeon            #+#    #+#             */
/*   Updated: 2023/01/19 16:46:37 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(const char *s, unsigned int start, size_t len);
static char	*ft_read_on(int fd, char *stack);
static size_t ft_strlen(const char *s1);

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*ret;

	if (stack == NULL)
	{
		stack = malloc(1);
		if (stack == NULL)
			return (NULL);
		*stack = 0;
	}
	ret = NULL;
	stack = ft_read_on(fd, stack);
	stack = get_stack(stack, &ret);
	return (ret);
}

char	*get_stack(char *stack, char **ret)
{
	char	*temp;
	if (stack == NULL)
		return (NULL);
	else if (*stack == '\0')
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	else if (ft_find(stack, '\n', 0))
	{
		temp = stack;
		*ret = ft_substr(stack, 0, ft_find(stack, '\n', 0));
		if (*ret)
			stack = ft_substr(stack, ft_find(stack, '\n', 0), -1);
		else
			stack = NULL;
		free(temp);
		return (stack);
	}
	else
	{
		*ret = stack;
		stack = NULL;
		return (stack);
	}
}
/*
static char	*ft_substr(const char *s1, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (start > ft_strlen(s1))
		return (NULL);
	if (len > ft_strlen(s1) - start)
		len = ft_strlen(s1) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s1[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
*/
static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static char	*ft_read_on(int fd, char *stack)
{
	int		red;
	char	*temp;
	char	buf[BUFFER_SIZE];

	while (!ft_find(stack, '\n', 0))
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (red == -1)
		{
			free(stack);
			return (NULL);
		}
		else if (red == 0)
			return (stack);
		else if (0 < red && red <= BUFFER_SIZE)
		{
			temp = ft_join(stack, buf, ft_strlen(stack), red);
			free(stack);
			stack = temp;
			if (stack == NULL)
				return (NULL);
		}
	}
	return (stack);
}

char	*ft_join(const char *s1, const char *s2, int len1, int len2)
{
	int		i;
	int		j;
	char	*join;
	
	join = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		join[i] = s1[i];
	   	i++;
	}
	j = 0;
	while (j < len2)
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}


int	ft_find(const char *s1, int c, int flag)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i++] == (char)c)
			return (i);
	}
	if (flag)
		return (i);
	else
		return (0);
}

static size_t	ft_strlen(const char *s1)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	return (len);
}


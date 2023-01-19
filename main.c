/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:39:48 by dajeon            #+#    #+#             */
/*   Updated: 2023/01/19 14:38:36 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = 0;
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}


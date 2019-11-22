/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:13:40 by mweerts           #+#    #+#             */
/*   Updated: 2019/11/22 15:26:07 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int		fd;
	char	*str;
	int 	i;


	fd = open("test.txt", O_RDONLY);
	while ((i = get_next_line(fd, &str)) > 0)
	{
		printf("[%d] %s\n", i, str);
		free(str);
	}
	printf("[%d] %s", i, str);
	free(str);	


}

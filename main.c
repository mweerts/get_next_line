/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:13:40 by mweerts           #+#    #+#             */
/*   Updated: 2019/11/05 23:25:18 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int		fd;
	char	*str;

	fd = open("./fichiers/alphabet", O_RDONLY);
	while (get_next_line(fd, &str))
	{
		printf("%s\n", str);
		free(str);
	}
}

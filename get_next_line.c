#include "get_next_line.h"

static int get_line(char **str, char **line)
{
	int		i;
	char	*tmp;

	if (!*str || !line)
		return (-1);
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr(*str, 0, i);
	if ((*str)[i] == '\n')
	{
		tmp = *str;
		*str = ft_substr(tmp, i + 1, ft_strlen(tmp) + 1);
		free(tmp);
		return (1);
	}
	else if ((*str)[i] == '\0')
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*tab[OPEN_MAX + 1];
	int			ret;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (tab[fd])
		{
			tmp = tab[fd];
			tab[fd] = ft_strjoin(tmp, buff);
			free(tmp);
			tmp = NULL;
		}
		else
			tab[fd] = ft_strdup(buff);
		if (ft_strchr(tab[fd], '\n'))
			return (get_line(&tab[fd], line));
	}
	if (ret == 0 && tab[fd] == NULL)
		return (0);
	else if (ret < 0)
		return (-1);
	else
		return (get_line(&tab[fd], line));
}

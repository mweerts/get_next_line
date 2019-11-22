#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>

int 	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif

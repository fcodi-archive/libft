/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:33:38 by fcodi             #+#    #+#             */
/*   Updated: 2020/03/05 20:13:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# if (NEED_VANILLA_STRING || !NO_VANILLA_LIBFT)
#  define NEED_SPECIAL_SYMBOL_NAMING
#  define NEED_BOOLEAN
#  include <unistd.h>
#  include <ft_astr.h>
#  include <ft_memfunc.h>
#  include <ft_stddef.h>

size_t			ft_strlenc(const char *s, char c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strtrim(const char *s);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *string);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strequ(const char *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *string, int c);
char			*ft_strstr(const char *haystack, const char *needle);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);
unsigned int	ft_strnlen(unsigned int n);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);

# endif

#endif

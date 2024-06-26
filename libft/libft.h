/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:18:31 by ehida             #+#    #+#             */
/*   Updated: 2023/06/05 03:51:50 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));
int				ft_isalpha(int c);
int				ft_isdigit(int num);
int				ft_isalnum(int arg);
int				ft_isascii(int c);
int				ft_isprint(int arg);
int				ft_toupper(int c);
int				ft_tolower(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t len);
void			ft_bzero(void *s, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dest, const char *src, size_t dstsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
long long		ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
void			free_2d(void **array);

char			*get_next_line(int fd);
size_t			ft_strlen_gnl(const char *s);
int				ft_strchr_gnl(const char *s, int c);
char			*ft_strjoin_gnl(const char *s1, const char *s2);

int				ft_idc_printf(int n, char c);
int				ft_printf(const char *str, ...);
int				ft_put_unbr_printf(unsigned int nbr);
int				ft_putaddress_printf(unsigned long long ptr);
int				ft_putchar_printf(char c);
int				ft_puthex_printf(unsigned int nbr, char c);
int				ft_putnbr_printf(int nbr);
int				ft_putstr_printf(char *str);

#endif

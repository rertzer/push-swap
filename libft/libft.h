/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:20:30 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/15 16:18:09 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_flush_split(char **splited);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
/* bonus functions*/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *newlst);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *newlst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));

/**********************************************************/
/*                 ft_printf                              */
/**********************************************************/

# define FORMAT_STR	"cspdiuxX%"
# define FORMAT_NBR 9
# define FLAGS_STR "-0.# +"
# define FLAGS_NBR 7
# define BASETEN "0123456789"
# define BASEUHEX "0123456789ABCDEF"
# define BASELHEX "0123456789abcdef"

typedef struct s_data
{
	const char	*fs;
	va_list		ap;
	int			len;
}	t_data;

typedef unsigned int		t_uint;
typedef unsigned long long	t_ull;
typedef int					(*t_vafun)(t_data *data);

/* ft_printf.c functions */
int			ft_printf(const char *fs, ...);
int			parse_fs(t_data *data);
int			parse_format(t_data *data, int start, int i);
int			get_va(char c, t_data *data);
t_vafun		get_fun(int i);
/* ftpf_format_alpha functions */
int			ft_format_char(t_data *data);
int			ft_format_str(t_data *data);
int			ft_format_per(t_data *data);
int			ft_format_wft(char c);
/* ftpf_format_num functions */
int			ft_format_int(t_data *data);
int			ft_format_uns(t_data *data);
int			ft_format_lhx(t_data *data);
int			ft_format_uhx(t_data *data);
int			ft_format_point(t_data *data);
/* ftpf_printf_utils functions */
int			ft_instr(char *str, char c);
int			get_string(const char *fd, int start, int end);
int			str_print(char *str);
/* ftpf_uxitoa.c functions */
char		*ft_uxitoa(unsigned int nb, char *base);
/* ftpf_pointoa.c functions */
char		*ft_pointoa(t_ull nb);

/* ************************************************************************** */
/*                          get next line                                     */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4 
# endif

# define FD_MAX 1

typedef struct s_buffer
{
	ssize_t	start;
	char	buffer[BUFFER_SIZE + 1];
}	t_buffer;

typedef struct s_gnllist
{
	ssize_t				len;
	char				*string;
	struct s_gnllist	*prev;
	struct s_gnllist	*next;
}	t_gnllist;

/* get_next_line.c functions */
char		*get_next_line(int fd);
char		*gnl_clean_one(t_buffer **buff, int fd);
void		clean_all(t_gnllist *list, t_buffer **buff, int fd);
char		*get_line(int fd, t_gnllist *line, t_buffer *buff);
char		*list_join(t_gnllist *line);
ssize_t		get_toappend_len(char *buffer);
/* get_next_line_utils.c functions */
ssize_t		buffer_update(int fd, t_buffer *buff);
t_gnllist	*ft_strappend(t_gnllist *last, char *src, ssize_t len);
void		list_join_util(t_gnllist *line, char *str);
t_buffer	*init_buffer(t_buffer *buff);
#endif

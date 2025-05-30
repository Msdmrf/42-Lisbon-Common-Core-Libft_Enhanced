/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:07:43 by migusant          #+#    #+#             */
/*   Updated: 2025/05/27 17:27:33 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

# include "ft_printf.h"
# include "get_next_line.h"

// LIST STRUCT ALIAS
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// STACK STRUCT ALIAS
typedef struct s_stack
{
    void			*content;
    struct s_stack	*next;
    struct s_stack	*prev;
}					t_stack;

// FUNCTIONS FROM <string.h>
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);

// FUNCTIONS FROM <strings.h>
void		ft_bzero(void *s, size_t n);

// FUNCTIONS FROM <stdlib.h>
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);

// FUNCTIONS FROM <ctype.h>
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

// NON STANDARD FUNCTIONS
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// LIST FUNCTIONS
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// STACK FUNCTIONS
t_stack		*ft_stacknew(void *content);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
int			ft_stacksize(t_stack *stack);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackdelone(t_stack *stack, void (*del)(void*));
void		ft_stackclear(t_stack **stack, void (*del)(void*));
void		ft_stackiter(t_stack *stack, void (*f)(void *));
t_stack		*ft_stackmap(t_stack *stack, void *(*f)(void *), void (*del)(void *));

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:00:30 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 21:01:21 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <errno.h>
# include "../libft/libft.h"

# define LNK 1
# define SIZE 2
# define DEV 3

typedef struct		s_env
{
	char			*opt;
	int				ac;
	t_list			*arg;
	int				cap;
	int				nb_file;
	int				arg_t;
	int				file;
	int				nb_arg;
	size_t			max_uid;
	size_t			max_gid;
	size_t			max_maj;
	size_t			max_min;
	size_t			max_size;
	size_t			max_link;
	char			*path;
}					t_env;

typedef struct		s_inode
{
	char			*name;
	char			*path;
	char			*real_path;
	int				type;
	struct stat		buf;
}					t_inode;

void				set_env(t_env *e, int ac);
void				arg_way(char **av, int ac, t_env *e);
void				manag_ls(char *option, t_list *arg, t_env *e);
void				manag_tri(t_list *list, char *option);
void				tri_arg(t_list *list, char *option);
void				alpha_sort(t_list *list);
void				time_sort(t_list *list);
void				reverse_time_sort(t_list *list);
void				reverse_alpha_sort(t_list *list);
void				reverse_sort(t_list *list);
void				classic_sort(t_list *list);
void				recursion(char *path, t_env *e);
void				padding_right(mode_t right);
void				padding_link(t_list *tmp, t_env *e);
void				padding_size(t_list *tmp, t_env *e);
void				padding_uid(t_list *tmp, t_env *e);
void				padding_gid(t_list *tmp, t_env *e);
void				padding_time(t_list *list);
void				padding_block(t_list *list);
void				padding_min(dev_t dev, t_env *e);
void				padding_maj(dev_t dev, t_env *e);
char				mode_type(mode_t mode);
void				global_padding_file(int cap, t_env *e, t_list *arg);
void				global_padding_dir(t_env *e, t_list *arg, t_list **list);
void				global_padding_recur(int cap, t_env *e, t_list *arg);
void				print_list(t_list *list, t_env *e);
void				print_all(t_list *list, t_env *e);
void				print_file_all(t_list *list, t_env *e);
void				print_first_rep(t_list **list, char *option, t_env *e);
void				content(struct dirent *dir, t_inode *inode,
		t_list **list, t_env *e);
void				classic_read(char *path, t_list **list,
		char *option, t_env *e);
void				set_max(t_env *e, struct stat buf);
void				catch_error(char *path);
void				illegal_option(char *option);
void				del(void *content, size_t size);
void				ft_swap_inode(t_inode *a, t_inode *b);
t_list				*index_list(t_list **list, int index);
int					check_option(char *option, char letter);
int					check_time(time_t tmp);
int					count_arg(t_list *arg);
int					count_dir(t_list *arg);
int					count_file(t_list *arg, char *option);
int					check_link(char *path);
int					set_type(mode_t mode);

#endif

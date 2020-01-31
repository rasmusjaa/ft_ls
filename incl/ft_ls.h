/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:30:21 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/31 14:16:33 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define LS_RIGHTS "rwxrwxrwx"

# include "libft.h"
# include "ft_printf.h"
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>

typedef struct		s_ls
{
	int				term_w;
	int				max_len;
	int				l_flag;
	int				cr_flag;
	int				a_flag;
	int				r_flag;
	int				t_flag;
	int				ct_flag;
	int				arg_files;
	int				arg_dirs;
	int				arg_missing;
	char			cur_dir[2048];
	int				col_width;
	int				link_width;
	int				user_width;
	int				group_width;
	int				byte_width;
	int				col_count;
	int				cur_col;
	int				dir_contains;
	int				printed;
	struct s_lstext	*start;
}					t_ls;

typedef struct		s_lstext
{
	char			*str;
	struct s_lstext	*next;
}					t_lstext;

void				ls_print_acl_ext(char *path);
void				ls_calc_columns(t_ls *data);

int					ls_options(int ac, char **av, t_ls *data);

void				ls_recurse_rev(t_ls *data, t_lstext *node);
int					ls_print_rev(t_ls *data, t_lstext *node);

void				ls_error_exit(char *str);
void				ls_usage(t_ls *data);
t_lstext			*ls_node_new(t_lstext *node);
int					ls_free_all(t_lstext *node);
int					ls_is_not_dot(char *str);

void				ls_init_layout(t_ls *data);
int					ls_if_longer(int current, char *str);
int					ls_ends_in_slash(char *str);
int					ls_arg_exists(int ac, char **av, int i, t_ls *data);
void				ls_short_time(char *now, char *file);

int					ls_closedir_error(DIR *dir);

int					ls_open_dir(char *str, t_ls *data);
int					ls_read(int ac, char **av, int i, t_ls *data);

int					ls_sort_dir(t_ls *data);

void				ls_sort_args(int ac, char **av, int i, t_ls *data);

int					start_again(char *str, t_ls *old_data);

void				ls_output_l(t_ls *data, t_lstext *node);
void				ls_output_no_l(t_ls *data, t_lstext *node);
int					ls_print_nodes(t_ls *data);

void				ls_parse_l_flag(t_ls *data, struct stat buf,
						char *str, char *path);

int					ls_total_dir(char *str);
int					ls_arg_dir(int ac, char **av, int i, t_ls *data);
void				ls_arg_file(int ac, char **av, int i, t_ls *data);

#endif

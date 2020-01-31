/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:49:36 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/30 16:15:46 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>

static void	ls_print_time(t_ls *data, struct stat buf)
{
	time_t	now;
	char	cur_time[25];
	char	file_time[25];
	int		i;

	i = 0;
	time(&now);
	ft_strcpy(cur_time, ctime(&now));
	ft_strcpy(file_time, ctime(&(buf.st_mtime)));
	if (data->ct_flag == 1)
	{
		while (file_time[i])
			i++;
		write(1, file_time, i - 1);
	}
	else
	{
		ls_short_time(cur_time, file_time);
	}
}

static void	ls_size_owner(struct stat buf, t_ls *data, char *str)
{
	struct passwd	*pwd;
	struct group	*grp;

	if (!(pwd = getpwuid(buf.st_uid)))
	{
		ft_printf("./ft_ls: %s: %s\n", str, strerror(errno));
		return ;
	}
	if (!(grp = getgrgid(buf.st_gid)))
	{
		ft_printf("./ft_ls: %s: %s\n", str, strerror(errno));
		return ;
	}
	ft_printf("%*s  ", -1 * data->user_width, pwd->pw_name);
	ft_printf("%*s  ", -1 * data->group_width, grp->gr_name, buf.st_size);
	ft_printf("%*d ", data->byte_width, buf.st_size);
}

static void	ls_print_links(struct stat buf, t_ls *data)
{
	ft_printf(" %*d ", data->link_width, buf.st_nlink);
}

static void	ls_print_rights(struct stat buf)
{
	char	c;
	int		i;

	i = 0;
	if (S_ISLNK(buf.st_mode))
		ft_putchar('l');
	else if (S_ISDIR(buf.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(buf.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(buf.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(buf.st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(buf.st_mode))
		ft_putchar('s');
	else
		ft_putchar('-');
	while (i < 9)
	{
		c = (buf.st_mode & (1 << (8 - i))) ? LS_RIGHTS[i] : '-';
		ft_putchar(c);
		i++;
	}
}

void		ls_parse_l_flag(t_ls *data, struct stat buf, char *str, char *path)
{
	char	link[2048];
	int		ret;

	ls_print_rights(buf);
	ls_print_acl_ext(path);
	ls_print_links(buf, data);
	ls_size_owner(buf, data, str);
	ls_print_time(data, buf);
	ft_putchar(' ');
	if (S_ISLNK(buf.st_mode))
	{
		ret = readlink(path, link, 1024);
		if (ret == -1)
			ls_error_exit("Readlink error\n");
		ft_printf("%s -> ", str);
		write(1, link, ret);
		write(1, "\n", 1);
	}
	else
		ft_putendl(str);
}

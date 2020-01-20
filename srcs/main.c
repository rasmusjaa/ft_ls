/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:59:50 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/20 19:51:34 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_printf.h"
#include <dirent.h>
#include "ft_ls.h"

#define N 12 // Number of files
#define W 80 // Terminal width


void		ls_usage(t_options *options)
{
	free(options);
	ft_printf("usage: ./ft_ls [-lRart] [directory ...]\n");
	exit (1);
}

size_t		longest_name(DIR	*dir)
{
	struct dirent	*sd;
	int	current;
	int	longest;

	current = 0;
	longest = 0;
	while((sd = readdir(dir)) != NULL)
	{
		current = ft_strlen(sd->d_name);
		if (current > longest)
			longest = current;
	}
	return (longest);
}

static int	ls_open_dir(char *str, char **av, t_options *options)
{
	DIR				*dir;
	int				len;
	struct dirent	*sd;

	ft_printf("l %d R %d a %d r %d t %d\n", options->l_flag, options->cr_flag,	options->a_flag, options->r_flag, options->t_flag);
	dir = opendir(str);
	if (dir == NULL)
	{
		ft_printf("%s: %s: No such file or directory\n", av[0], str);
		exit(1);
	}
	len = longest_name(dir);
	closedir(dir);
	dir = opendir(str);
	while((sd = readdir(dir)) != NULL)
	{
		ft_printf("%*s\n", len + 1, sd->d_name);
	}
	ft_printf("\n");
	closedir(dir);
	return (0);
}

static int	ls_read_dir(int ac, char **av, int i, t_options *options)
{
	if (!av[i])
	{
		ft_printf("no dir\n");
		ls_open_dir(".", av, options);
	}
	while (i < ac)
	{
		ft_printf("av is %s\n", av[i]);
		ls_open_dir(av[i], av, options);
		i++;
	}
	return (0);
}

static void	ls_set_options(t_options *options)
{
	options->l_flag = 0;
	options->cr_flag = 0;
	options->a_flag = 0;
	options->r_flag = 0;
	options->t_flag = 0;
}

static int	ls_check_char(char c, t_options *options)
{
	if (c == 'l')
		options->l_flag = 1;
	else if (c == 'R')
		options->l_flag = 1;
	else if (c == 'a')
		options->l_flag = 1;
	else if (c == 'r')
		options->l_flag = 1;
	else if (c == 't')
		options->l_flag = 1;
	else if (c == '\0')
		return (0);
	else
		return (1);
	return (0);
}

static void	ls_options(int ac, char **av, t_options *options)
{
	int				i;
	int				j;

	ls_set_options(options);
	i = 1;
	while (i < ac && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (ls_check_char(av[i][j], options) != 0)
				ls_usage(options);
			j++;
		}
		i++;
	}
	ft_printf("options checked, i %d\n", i);
	ls_read_dir(ac, av, i, options);
}

int			main(int ac, char **av)
{
	t_options		*options;

	if (!(options = (t_options *)malloc(sizeof(t_options))))
		return (1);
	ls_options(ac, av, options);
	free (options);
	return (0);
}
// hai: kato makroja rv esim?
// muista recursiivisesti kansiot alusta asti!

/* READ man (2 or 3) or google
ls
◦ opendir / readdir / closedir
◦ stat / lstat
◦ getpwuid / getgrgid
◦ time / ctime
◦ readlink
◦ perror / strerror
*/

/*
List a directory
• Write a program that uses the opendir, readdir and closedir functions to open
a folder and list the names of its files on the standard output.
• Example :
$>mkdir -p toto/tyty
$>touch toto/{tata,titi,tutu}
$>./ft_list_dir toto
tata
titi
tutu
tyty
$>
*/

/*
Get a file’s data
• Write a program which takes a file as a parameter and uses, among others, the stat
function to get the file’s information and display it on screen.
• Example :
$>./ft_inspect_file a_crazy_file
Name: a_crazy_file
Type: File
Modes: rwxr-xr-x
Number of links: 1
Owner: zaz
Group: staff
Size: 2142 octets
Last modification date: Sep 17 23:42
$>
*/

/*
Within your mandatory part you are allowed to use the following functions:
◦ write
◦ opendir
◦ readdir
◦ closedir
◦ stat
◦ lstat
◦ getpwuid
◦ getgrgid
◦ listxattr
◦ getxattr
◦ time
◦ ctime
◦ readlink
◦ malloc
◦ free
◦ perror
◦ strerror
◦ exit
to use tcgetattr is justified in certain case

◦ Required flags:
-l : (The lowercase letter ``ell''.)  List in long format.  (See below.)  If the output is to a termi-
             nal, a total sum for all the file sizes is output on a line before the long listing.
	The Long Format
     If the -l option is given, the following information is displayed for each file: file mode, number of
     links, owner name, group name, number of bytes in the file, abbreviated month, day-of-month file was last
     modified, hour file last modified, minute file last modified, and the pathname.  In addition, for each
     directory whose contents are displayed, the total number of 512-byte blocks used by the files in the
     directory is displayed on a line by itself, immediately before the information for the files in the
     directory.  If the file or directory has extended attributes, the permissions field printed by the -l
     option is followed by a '@' character.  Otherwise, if the file or directory has extended security infor-
     mation (such as an access control list), the permissions field printed by the -l option is followed by a
     '+' character.
-R : Recursively list subdirectories encountered.
-a : Include directory entries whose names begin with a dot (.).
-r : Reverse the order of the sort to get reverse lexicographical order or the oldest entries first
             (or largest files last, if combined with sort by size
-t : Sort by time modified (most recently modified first) before sorting the operands by lexicographi-
             cal order.

◦ You do not have to deal with the multiple column format for the exit when
the option -l isn’t in the arguments.
◦ You are not required to deal with ACL and extended attributes.
◦ padding or pagination diff ok, but no information can be missing.

bonus ideas:
Management of ACL and extended attributes.
• Management of the columns without the option -l. (man 4 tty)
• Management of options -u, -f, -g, -d, ...
• Management of views in colors (Similar to option -G)
• Optimization of your code (What is the response time of your ls on a BIG ls -lR)
*/
// check leaks

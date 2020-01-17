/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:59:50 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/17 17:05:52 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <dirent.h>

#define N 12 // Number of files
#define W 80 // Terminal width

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

int		main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*sd;
	int				len;

	if (ac == 1)
		dir = opendir(".");
	else
		dir = opendir(av[1]);
	if (dir == NULL)
	{
		ft_printf("%s: %s: No such file or directory\n", av[0], av[1]);
		exit(1);
	}
	len = longest_name(dir);
	ft_printf("longest %d\n", len);
	closedir(dir);
	dir = opendir(".");
	while((sd = readdir(dir)) != NULL)
	{
		ft_printf("%*s\n", len, sd->d_name);
	}
	ft_printf("\n");
	closedir(dir);
	return (0);
}
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

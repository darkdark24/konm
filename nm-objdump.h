/*
** nm-objdump.h for nm-objdump in /home/candan_c/rendu/project/nm-objdump
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Mar 22 11:29:44 2008 caner candan
** Last update Mon Mar 31 00:05:02 2008 caner candan
*/

#ifndef __NM_OBJDUMP_H__
# define __NM_OBJDUMP_H__

# define FILE_DEFAULT	"a.out"

# define NAME_NM	"nm"
# define NAME_OD	"objdump"

# define DUMP_NAME	"\n%s:\n"
# define HEADER_FILE	"\n%s:     file format %s-%s-%s\n\n"
# define CONTENTS_SCN	"Contents of section %s:\n"
# define ADDR_STR	" %04x "
# define HEXA_CHAR	"%02x"

# define ERRMSG		"Error: %s\n"
# define ERRFILE	"%s: %s: File format not recognized\n"
# define NOFILE		"%s: '%s': No such file\n"
# define NOSYMBOL	"%s: %s: no symbols\n"

/*
**
*/

int	file_open(char *file, int *length, char *name);
void	file_close(int fd);
void	*file_init(int fd, int length);
void	file_free(void *buf, int length);
void	file_type(void *buf);
int	file_elf(void *buf, char *file, char *name);
char	*get_class(int cl);
char	*get_os(int os);
char	*get_machine(int ma);
void	*scn_get(void *buf, unsigned int type, int pos);
int	dump_scn(void *buf);
int	dump_scn_rules(void *buf, void *s, int nb);
void	dump_scn_split(void *buf, void *s);
void	dump_scn_split_hexa(void *s, unsigned char *str, int nb);
void	dump_scn_split_string(void *s, unsigned char *str, int nb);
int	dump_sym(void *buf);
int	dump_prg(void *buf);
void	get_scn(void *buf, void **scn, char **strtab);
void	get_sym(void *buf, void **sym, char **strtab);
void	get_rel(void *buf, void **rel);
void	get_info_sym(void *s);
void	**sort_symtab(void **sym, char *strtab);
void	**fill_symtab(void *buf, void *scn);

#endif /* !__NM_OBJDUMP_H__ */

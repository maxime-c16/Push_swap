#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>

int		ft_isdigit(int c);
long	ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_exit(char *exit_msg, int exit_code);
void	ft_str_isalpha(char **str);
void	push_swap(int ac, char **av);
void	ft_check_db(char **str);
void	ft_putstr_fd(char *s, int fd);
void	ft_char_to_tab(char **str, int **tab);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}					t_stack;

int		get_size(t_stack **stack);
int		get_minimum(t_stack **stack);
t_stack	*ft_lstlast(t_stack **lst);
t_stack	*ft_lstnew(int num);
void	ft_lstadd_back(t_stack **stack, int nb);
void	ft_lstadd_front(t_stack **stack, t_stack *elem);
void	ft_init_lst(t_stack **stack, long nb);
void	ft_print_lst(t_stack **stack_a, t_stack **stack_b);
void	ft_exec_cmd(char *cmd, t_stack **stack_a, t_stack **stack_b);

//parsing functions

int		ft_isalpha(int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_check_int(long nb);
char	**ft_split(char *s, char c);
void	ft_parse_int(t_stack **stack, char **av, int ac);
void	ft_parse_fill(t_stack **stack, char *str);
char	**ft_cpy_num(int ac, char **av);

//rotate functions

void	ft_rotate(char *cmd, t_stack **stack_a, t_stack **stack_b);
void	ft_back_r(t_stack **stack);
void	ft_rotate_stck(t_stack **stack);

//reverse rotate functions

void	ft_rotate_rr(char *cmd, t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_rr_stck(t_stack **stack);

//push functions

void	ft_push(char *cmd, t_stack **stack_a, t_stack **stack_b);
void	ft_push_stck(t_stack **stack_a, t_stack **stack_b, t_stack *tmp);
void	ft_del_one(t_stack **stack);

//swap functions

void	ft_swap_cmd(char *cmd, t_stack **stack_a, t_stack **stack_b);
void	ft_swap_stck(t_stack **stack);

//radix sort

t_stack	*get_max(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_stack *temp1, t_stack *temp2);
void	quicksort(char	**tab, int low, int high);
void	ft_normalize(t_stack **stack, int ac, char **av);

#endif

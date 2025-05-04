#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../lib/libft/include/libft.h"
# include <limits.h>

# define ARG_NUMBER "You entered a wrong amount of arguments.\n"
# define INT_ERROR "One value of array is not integer.\n"
# define INT_OVERFLOW "One value of array is out of the limits of integer datatype.\n"
# define INT_DUP "Your stack has an duplicated value.\n"

typedef struct s_node
{
    int n;
    int i;
    struct s_node *next;
    struct s_node *prev;
} t_node;


typedef struct s_stack
{
    t_node *first;
    t_node *last;
    int     size;
} t_stack;

typedef struct s_stack_list
{
    t_stack *a;
    t_stack *b;
}   t_stack_list;

void	free_stack(t_node *node_lst);
void	free_stack_list(t_stack_list *stack_list);
void    print_error(t_stack_list *stack_list, char *message);

void    init_stack_list(t_stack_list *stack_list, char **values);

long int	ps_atoi(t_stack_list *stack_list, const char *nptr);
void	check_duplicates(t_stack_list *stack_list, t_node *node, int num);
int	next_int(const char *value, int i);
void	split_value(t_stack_list *stack_list, t_stack *stack, const char *value);
void	parse_data(t_stack_list *stack_list, t_stack *stack, char **values);

t_node *new_node(int num);
void	append_stack(t_node **node_lst, t_node *new);
t_node	*stack_last(t_node *first);
int	stack_size(t_node *node);
void	print_stack(t_node *stack_a, t_node *stack_b);

void	swap_int(t_node *node1, t_node *node2);
void	sa(t_stack_list *stack_list);
void	sb(t_stack_list *stack_list);
void	ss(t_stack_list *stack_list);

void	pa(t_stack_list *stack_list);
void	pb(t_stack_list *stack_list);

void	rotate_node(t_stack *stack);
void	ra(t_stack_list *stack_list);
void	rb(t_stack_list *stack_list);
void	rr(t_stack_list *stack_list);

void	rev_rotate_node(t_stack *stack);
void	rra(t_stack_list *stack_list);
void	rrb(t_stack_list *stack_list);
void	rrr(t_stack_list *stack_list);

#endif
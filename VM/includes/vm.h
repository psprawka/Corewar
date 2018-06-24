/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:13:30 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:19:30 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# include "op.h"
# include "errno.h"

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"
# define RRR		0b01010100
# define RIR		0b01110100
# define RDR		0b01100100
# define IRR		0b11010100
# define IIR		0b11110100
# define IDR		0b11100100
# define DRR		0b10010100
# define DIR		0b10110100
# define DDR		0b10100100
# define IR			0b11010000
# define DR			0b10010000
# define RR			0b01010000
# define RI			0b01110000

// processes of player info
typedef struct		s_process
{
	int				champ_numb;
	int				id;
	uint32_t		pc;
	int				carry;
	int				registers[REG_NUMBER + 1];
	int				live;
	int				cycles;
	int				opcode;
	int				last_live;
}					t_process;

// players info
typedef struct		s_player
{
	int				number;
	int				color;
	uint32_t		size;
	char			*warrior_file;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				first_pc;
	int				last_live;
	int				total_lives_period;
}					t_player;

// arena
typedef struct		s_arena
{
	unsigned char		map[MEM_SIZE + 1];
	// visual render variables to add

}					t_arena;

// game info
typedef struct		s_game
{
	t_player		players[MAX_PLAYERS];
	t_arena			arena;
	t_list			*processes_stack;
	int				cycle_so_far;
	int				cycle_delta;
	int				cycle_to_die;
	int				cycle_to_check;
	int				max_checks;
	int				winner;
	int				nb_players;
	int				dump;
	int				speed;
	int				last_alive;
	int				nb_lives;
	int				nb_checks;
	int				nb_id;
}					t_game;

typedef struct		s_op
{
	char				*mnemonic;
	uint32_t			nb_params;
	t_arg_type			params_types[MAX_ARGS_NUMBER];
	uint32_t			opcode;
	uint32_t			cycles;
	char				*description;
	uint32_t			coding_byte;
	uint32_t			trunc_direct;
	void 				(*f)(t_game *, t_process *);
}					t_op;

typedef struct		s_fun
{
	int			opcode;
	void		(*f)(t_game *, t_process *);
}					t_fun;

// parser

void			parse_options(int argc, char **argv, t_game *game);

// handle header

void			read_magic(int fd);
void			read_name(t_game *game, int fd, int player);
void			read_prog_size(t_game *game, int fd, int player);
void			read_comment(t_game *game, int fd, int player);

// load players

void			load_warrior(t_game *game, char *warrior_file, int player);

// init

t_process		*new_proc(uint32_t pc, int champ_numb, int id);
void			load_first_processes(t_game *game);
void			init_game_env(t_game *game);

// utils

uint32_t		modulo(int nb);
void			set_tab(t_game *game);
uint32_t 		change_endianness(uint32_t value);
int				search_instruction(uint32_t opcode);
void			print_map(t_game *game);

// op utils

uint32_t		size_param(unsigned char type, uint32_t opcode);
int				param_good(t_game *game, t_process *process);
void			put_param(int param, t_game *game, u_int pos);

// errors
void			usage(void);

// read params
int				read_4_bytes(t_game *game, int pc);
short			read_2_bytes(t_game *game, int pc);
int				is_champ_number(t_game *game, int nbr);
int				get_value(t_game *game, t_process *process, unsigned char type,
				int position);
int				get_value_nomod(t_game *game, t_process *process, unsigned char type,
				int position);

// do cycles

int				do_cycle(t_game *game);

//  process_execution

void			read_opcode(t_game *game, t_process *process);
int				exec_process(t_game *game, t_process *process);
void			replace(t_game *game);

// run game // check lives

void			run_vm(t_game *game);
int				check_die_list(t_game *game);
void			end_game(t_game *game);


// operations

void			live(t_game *game, t_process *process);
void			ld(t_game *game, t_process *process);
void			st(t_game *game, t_process *process);
void			add(t_game *game, t_process *process);
void			sub(t_game *game, t_process *process);
void			ft_and(t_game *game, t_process *process);
void			ft_or(t_game *game, t_process *process);
void			ft_xor(t_game *game, t_process *process);
void			zjmp(t_game *game, t_process *process);
void			ldi(t_game *game, t_process *process);
void			sti(t_game *game, t_process *process);
void			ft_fork(t_game *game, t_process *process);
void			lld(t_game *game, t_process *process);
void			lldi(t_game *game, t_process *process);
void			lfork(t_game *game, t_process *process);
void			aff(t_game *game, t_process *process);
t_process		*clone_process(t_game *game, t_process *process);

// stack utils

void			ft_push_sorted(t_list **list, t_list *newb);
void			ft_delsup(t_list **list, t_list *bye, t_list *previous);
int				stack_size(t_list *list);

// freezer

void			free_player(t_player *player);
void			free_game(t_game *game);
void			free_op(t_op *op);
void			free_process(void *process);

// Ressources
void			print_game(t_game *game);
int				get_index(t_game *game, unsigned char type, t_process *process, uint32_t pos);
int				ft_abs(int number);
void 			afficher_stack(t_game *game);
t_player		get_player(t_game *game, int champ_number);

t_op			g_op_tab[NB_OP + 1];

#endif

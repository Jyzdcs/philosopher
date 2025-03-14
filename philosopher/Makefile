# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#              #
#    Updated: 2025/03/14 18:08:36 by kclaudan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS_DIR = srcs
INCS_DIR = includes
OBJS_DIR = objs

SRCS = main.c \
	   init/parse_args.c \
	   init/init_simulation.c \
	   init/init_philosophers.c \
	   init/init_mutexes.c \
	   init/threads.c \
	   lifecycle/philosopher_routine.c \
	   lifecycle/actions.c \
	   lifecycle/states.c \
	   time/timing.c \
	   monitor/monitor.c \
	   utils/cleanup.c \
	   utils/strategy.c \
	   utils/helpers.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -I$(INCS_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
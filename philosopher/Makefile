# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 00:00:00 by user42            #+#    #+#              #
#    Updated: 2025/03/13 14:22:16 by kclaudan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -f

INCLUDES = -I./includes

SRCS_DIR = srcs/
INIT_DIR = $(SRCS_DIR)init/
ACTIONS_DIR = $(SRCS_DIR)actions/
MONITORING_DIR = $(SRCS_DIR)monitoring/
UTILS_DIR = $(SRCS_DIR)utils/
CLEANUP_DIR = $(SRCS_DIR)cleanup/

SRCS = $(SRCS_DIR)main.c \
	$(INIT_DIR)parse_args.c \
	$(INIT_DIR)init_simulation.c \
	$(INIT_DIR)init_philosophers.c \
	$(INIT_DIR)init_mutexes.c \
	$(INIT_DIR)thread_management.c \
	$(ACTIONS_DIR)philosopher_routine.c \
	$(ACTIONS_DIR)eating.c \
	$(ACTIONS_DIR)sleeping_thinking.c \
	$(ACTIONS_DIR)deadlock_prevention.c \
	$(MONITORING_DIR)monitor.c \
	$(MONITORING_DIR)death_check.c \
	$(UTILS_DIR)time_utils.c \
	$(UTILS_DIR)print_utils.c \
	$(UTILS_DIR)str_utils.c \
	$(CLEANUP_DIR)cleanup.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
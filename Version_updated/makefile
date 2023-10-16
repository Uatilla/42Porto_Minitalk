# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 20:50:44 by uviana-a          #+#    #+#              #
#    Updated: 2023/08/18 22:29:10 by uviana-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.SILENT:

# Colors
RESET = \033[0m       # Text Reset
BLACK = \033[1;30m       # Black
RED = \033[1;31m         # Red
GREEN = \033[1;32m       # Green
YELLOW = \033[1;33m      # Yellow
BLUE = \033[1;34m       # Blue
PURPLE = \033[1;35m     # Purple
CYAN = \033[1;36m        # Cyan
WHITE = \033[1;37m       # White

# Commands
CC		= cc
RM		= rm -rf

# Flags
CFLAGS	= -Wall -Wextra -Werror

# Files
CLIENT			= client
SERVER			= server
CLT_OBJS 		= client.o
SRV_OBJS 		= server.o

CLIENT_BONUS	= client_bonus
SERVER_BONUS	= server_bonus
CLT_B_OBJS		= client_bonus.o
SRV_B_OBJS		= server_bonus.o

UTILS			= utils
UTL_OBJS		= utils.o

all: $(CLIENT) $(SERVER)


$(CLIENT): $(CLT_OBJS) $(UTL_OBJS)
	$(CC) $(CFLAGS) $(CLT_OBJS) $(UTL_OBJS) -o $(CLIENT)
	printf "Client		$(GREEN)[OK]$(RESET)\n"

$(SERVER): $(SRV_OBJS) $(UTL_OBJS)
	$(CC) $(CFLAGS) $(SRV_OBJS) $(UTL_OBJS) -o $(SERVER)
	printf "Server		$(GREEN)[OK]$(RESET)\n"

clean:
	$(RM) $(CLT_OBJS) $(SRV_OBJS) $(UTL_OBJS) $(CLT_B_OBJS) $(SRV_B_OBJS)
	printf "clean	       $(CYAN)[OK]$(RESET)\n"

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	printf "fclean	       $(CYAN)[OK]$(RESET)\n"

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLT_B_OBJS) $(UTL_OBJS)
	$(CC) $(CFLAGS) $(CLT_B_OBJS) $(UTL_OBJS) -o $(CLIENT_BONUS)
	printf "Client Bonus	$(GREEN)[OK]$(RESET)\n"
$(SERVER_BONUS): $(SRV_B_OBJS) $(UTL_OBJS)
	$(CC) $(CFLAGS)	$(SRV_B_OBJS) $(UTL_OBJS) -o $(SERVER_BONUS)
	printf "Server Bonus	$(GREEN)[OK]$(RESET)\n"

re:	fclean all

.PHONY: clean fclean all re norm

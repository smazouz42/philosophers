SRCB = philo_bonus.c parser_bonus.c ft_new_philo.c ft_lstlast.c ft_lstadd_back.c all_data.c philo_bonus_utils.c

OBJB = $(SRCB:.c=.o)

NAME = philo_bonus

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
$(NAME) : ${OBJB} philo_bonus.h
	@$(CC)  ${OBJB} $(CFLAGS) -o ${NAME}
	@echo ██████╗░░█████╗░███╗░░██╗██╗░░░██╗░██████╗
	@echo ██╔══██╗██╔══██╗████╗░██║██║░░░██║██╔════╝
	@echo ██████╦╝██║░░██║██╔██╗██║██║░░░██║╚█████╗░
	@echo ██╔══██╗██║░░██║██║╚████║██║░░░██║░╚═══██╗
	@echo ██████╦╝╚█████╔╝██║░╚███║╚██████╔╝██████╔╝
	@echo ╚═════╝░░╚════╝░╚═╝░░╚══╝░╚═════╝░╚═════╝░
clean :
	$(RM) $(OBJB)

fclean : clean
	$(RM) philo_bonus

re : fclean all
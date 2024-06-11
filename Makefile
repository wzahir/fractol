NAME = fractol

PROG = fractol_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = fractol.c  utils.c  init.c  mandelbrot.c  julia.c  events.c  check_arg.c\

OBJ = $(SRC:.c=.o)

SRC_B = fractol_bonus.c  utils_bonus.c  init_bonus.c  events_bonus.c\
        burningship_bonus.c  mandelbrot_bonus.c  julia_bonus.c  check_arg_bonus.c\

OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework opengl -framework appkit $(OBJ) -o $(NAME)
	
bonus: $(PROG)

$(PROG): $(OBJ_B)
	$(CC) $(CFLAGS) -lmlx -framework opengl -framework appkit $(OBJ_B) -o $(PROG)

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) fractol_bonus

re: fclean all
##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	lib/hashtable/hash.c	\
		lib/hashtable/new_hashtable.c	\
		lib/hashtable/delete_hashtable.c	\
		lib/hashtable/ht_dump.c	\
		lib/hashtable/ht_insert.c	\
		lib/hashtable/ht_delete.c	\
		lib/hashtable/ht_search.c	\
		lib/my/mini_printf.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_compute_power_rec.c	\

CFLAGS	=	-Wall -Wextra -Werror -I./include/	\
			 -L. -lhashtable	\

CFLAGS_LIB 	=	-I./include/ -Werror -Wall -Wextra

OBJ_L	=	$(SRC_LIB:.c=.o)
OBJ	=	$(SRC:.c=.o)

SRC_TESTS =		tests/tests.c	\
				tests/tests_errors.c	\

FLAGS_TEST	=	-Wall -Wextra -Werror -I./include/	\
				-L. -lhashtable	\
				-lcriterion --coverage	\

all: $(OBJ)
	gcc -c $(SRC) $(CFLAGS_LIB)
	ar rc libhashtable.a $(OBJ)
	find -name "*.o" -delete

test: re
	gcc -o tests/test $(SRC) tests/main.c $(CFLAGS)

clean:
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f libhashtable.a
	rm -f unit_tests

re: fclean all

unit_tests: re
	gcc -o unit_tests $(SRC_TESTS) $(SRC) $(FLAGS_TEST)

tests_run: unit_tests
	./unit_tests --verbose

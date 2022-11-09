NAME		=	phonebook

SRCS		=	Contact.class.cpp		\
				deal_with_termios.cpp	\
				display.cpp				\
				Phonebook.class.cpp		\
				phonebook.cpp			\
				show.cpp				\
				Term.class.cpp

SRCS_DIR	=	srcs

CXX			=	c++

RM			=	rm -rf

CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98  -g -I~/Desktop/termios/inc -Iincludes

OBJS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))

OBJS_DIR		=	obj

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.cpp
	mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

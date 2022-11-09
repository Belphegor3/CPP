NAME		=	megaphone

SRCS		=	megaphone.cpp

SRCS_DIR	=	srcs

CXX			=	g++

RM			=	rm -rf

CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic -Weffc++ -g

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

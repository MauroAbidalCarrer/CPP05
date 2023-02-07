
NAME	:= Bureaucrats

SRCS	:= main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS	:= $(SRCS:.cpp=.o)

DEPS	=	$(OBJS:.o=.d)

CXX	:= c++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra -MMD -MP 

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(DEPS) 

fclean: clean
	rm -f $(NAME) superGardenForm_shrubbery

re:	fclean all

.PHONY: all clean fclean re

-include $(DEPS)
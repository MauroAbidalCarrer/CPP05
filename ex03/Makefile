
NAME	:= Bureaucrats

SRCS	:= main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS	:= $(SRCS:.cpp=.o)

GARDENS := 'an intern_shrubbery' 'the same intern_shrubbery' superGardenForm_shrubbery

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
	rm -f $(NAME) $(GARDENS)

re:	fclean all

.PHONY: all clean fclean re

-include $(DEPS)
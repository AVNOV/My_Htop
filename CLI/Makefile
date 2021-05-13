NAME	= htopSender

CC	= g++ -g3

RM	= rm -f

SRCS	= ./Graphical/GUI.cpp \
	  ./Graphical/SfmlGest.cpp \
	  ./Sources/CoreClockedModule.cpp \
	  ./Sources/CoreModule.cpp \
	  ./Sources/CpuModule.cpp \
	  ./Sources/DateTimeModule.cpp \
	  ./Sources/HostnameModule.cpp \
	  ./Sources/MonitorsInfo.cpp \
	  ./Sources/NetworkModule.cpp \
	  ./Sources/OsModule.cpp \
	  ./Sources/RamModule.cpp \
	  ./main.cpp 

OBJS	= $(SRCS:.cpp=.o)

override CPPFLAGS 	= -I ./Interface/ -I ./Sources -I ./Headers/
override CXXFLAGS 	+= -Wall -Wextra -Werror
override LDFLAGS	+= -lsfml-graphics -lsfml-window -lsfml-system -lncurses


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

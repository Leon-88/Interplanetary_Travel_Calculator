CXX = g++
CPPFLAGS = -std=c++17 -pedantic -Wall -Wextra -Werror -O3
RM = rm -f
# RM = del 2>nul
EXE_NAME = main
SRCS = main.cpp planet.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

all: voter

voter: $(OBJS)
	$(CXX) -o $(EXE_NAME) $(OBJS)

clean:
	$(RM) *.o
	$(RM) $(EXE_NAME)


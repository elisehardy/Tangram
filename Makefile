CC = g++
FLAGS = -g -O2 -Wall -Wextra -Werror -Wfatal-errors -Wshadow -Weffc++ -Wpointer-arith -std=c++11
IGNORED = -Wno-shadow -Wno-unused-parameter
LIB = -lm -lMLV
CFLAGS = $(FLAGS) $(IGNORED) $(LIB)

src = src/
bin = bin/
header = include/

vpath %.cpp $(src)
vpath %.hpp $(header)
vpath %.o $(bin)

################################################################################

# Create bin if it does not exists
$(shell mkdir -p $(bin))

################################################################################

all : tangram

.PHONY: clean all info


tangram: Set.o Game.o Polygon.o Square.o Triangle.o Parallelogram.o
	true

%.o: %.cpp %.hpp Polygon.hpp
	$(CC) -c $< -o $@  $(CFLAGS)


info:
	@echo "--------- compilation informations ----------"
	@echo "  compiler : $(CC)"
	@echo "  FLAGS    : $(CFLAGS)"
	@echo "  IGNORED  : $(IGNORED)"
	@echo "  LIB      : $(LIB)"


clean:
	rm -f rm $(exec)
	rm -Rf $(bin)*

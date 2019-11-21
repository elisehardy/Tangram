targets = State.o Menu.o

################################################################################

# Create bin if it does not exists
$(shell mkdir -p $(bin))

objects = $(addprefix $(bin), $(targets))

vpath %.cpp $(src)
vpath %.hpp $(header)
vpath %.o $(bin)

################################################################################

all: $(objects)

bin/State.o: src/State.cpp include/StateAbstract.hpp ../game/include/Engine.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/%.o: %.cpp %.hpp StateAbstract.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

clean:
	rm $(bin)* -Rf

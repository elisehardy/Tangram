targets =  Engine.o Event.o main.o

################################################################################

# Create bin if it does not exists
$(shell mkdir -p $(bin))

objects = $(addprefix $(bin), $(targets))

vpath %.cpp $(src)
vpath %.hpp $(header)
vpath %.o $(bin)

################################################################################

all: $(objects)

bin/Engine.o: src/Engine.cpp include/Engine.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/main.o: main.cpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/%.o: %.cpp %.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

clean:
	rm $(bin)* -Rf

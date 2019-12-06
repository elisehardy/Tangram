targets = Point.o Shape.o Triangle.o Polygon.o

################################################################################

# Create bin if it does not exists
$(shell mkdir -p $(bin))

objects = $(addprefix $(bin), $(targets))

vpath %.cpp $(src)
vpath %.hpp $(header)
vpath %.o $(bin)

################################################################################

all: $(objects)

bin/Point.o: src/Point.cpp include/Point.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/Triangle.o: src/Triangle.cpp include/Triangle.hpp include/Shape.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/%.o: %.cpp %.hpp Shape.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

clean:
	rm $(bin)* -Rf

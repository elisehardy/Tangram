targets = Triangle.o Polygon.o Shape.o

################################################################################

# Create bin if it does not exists
$(shell mkdir -p $(bin))

objects = $(addprefix $(bin), $(targets))

vpath %.cpp $(src)
vpath %.hpp $(header)
vpath %.o $(bin)

################################################################################

all: $(objects)

bin/Triangle.o: src/Triangle.cpp include/Triangle.hpp include/Point.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/Polygon.o: src/Polygon.cpp include/Polygon.hpp include/Triangle.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/Shape.o: src/Shape.cpp include/Shape.hpp include/Polygon.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/%.o: %.cpp %.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

clean:
	rm $(bin)* -Rf

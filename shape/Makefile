targets = Point.o Vector.o Polygon.o Square.o Triangle.o ShapeSet.o

################################################################################

# Create bin if it does not exists
$(shell mkdir -p $(bin))

objects = $(addprefix $(bin), $(targets))

vpath %.cpp $(src)
vpath %.hpp $(header)
vpath %.o $(bin)

################################################################################

all: $(objects)

bin/Vector.o: src/Vector.cpp include/Vector.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/Point.o: src/Point.cpp include/Point.hpp include/Vector.hpp
	$(CC) -c $< -o $@  $(CFLAGS)


bin/Polygon.o: src/Polygon.cpp include/Polygon.hpp include/Point.hpp include/Vector.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/%.o: %.cpp %.hpp Polygon.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

clean:
	rm $(bin)* -Rf

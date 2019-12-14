targets = Triangle.o Polygon.o ParserException.o Parser.o Shape.o

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

bin/Parser.o: src/Parser.cpp include/Parser.hpp include/ParserException.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/Shape.o: src/Shape.cpp include/Shape.hpp include/Polygon.hpp include/Parser.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

bin/%.o: %.cpp %.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

clean:
	rm $(bin)* -Rf


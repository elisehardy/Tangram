targets = Observer.o Button.o

################################################################################

# Create bin if it does not exists
$(shell mkdir -p $(bin))

objects = $(addprefix $(bin), $(targets))

vpath %.cpp $(src)
vpath %.hpp $(header)
vpath %.o $(bin)

################################################################################

all: $(objects)

bin/%.o: %.cpp %.hpp Drawable.hpp
	$(CC) -c $< -o $@  $(CFLAGS)

clean:
	rm $(bin)* -Rf

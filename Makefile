exec = tangram
modules = shape game

################################################################################

export CC = g++
export FLAGS = -g -O2 -Wall -Wextra -Werror -Wfatal-errors -Weffc++ -Wpointer-arith -std=c++17
export IGNORED = -Wno-unused-parameter
export LIB = -lm -lMLV
export CFLAGS = $(FLAGS) $(IGNORED) $(LIB)

export src = src/
export bin = bin/
export header = include/

vpath %.cpp $(src)
vpath %.hpp $(header)
vpath %.o $(bin)

# Create bin if it does not exists
$(shell mkdir -p $(bin))
cleansubbin = $(addsuffix /bin/*, $(modules))

################################################################################

all : $(modules)

.PHONY: clean all info $(modules)


$(modules):
	$(MAKE) -C $@


info:
	@echo "--------- compilation informations ----------"
	@echo "  compiler : $(CC)"
	@echo "  FLAGS    : $(CFLAGS)"
	@echo "  IGNORED  : $(IGNORED)"
	@echo "  LIB      : $(LIB)"


clean:
	rm -f rm $(exec) $(bin)* $(cleansubbin)

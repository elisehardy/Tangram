exec = tangram
modules = shape game state gui

################################################################################

export CC = g++
export FLAGS = -g -O2 -Wall -Wextra -Werror -Wfatal-errors -Weffc++ -Wpointer-arith -std=c++17
export IGNORED = -Wno-unused-parameter -Wno-effc++
export LIB = -lm -lstdc++ `pkg-config --libs-only-other --libs-only-L MLV` `pkg-config --libs-only-l MLV`
export CFLAGS = $(FLAGS) $(IGNORED)

export src = src/
export bin = bin/
export header = include/

vpath %.cpp $(src)
vpath %.hpp $(header)
vpath %.o $(bin)

# Create bin if it does not exists
$(shell mkdir -p $(bin))
subbins = $(addsuffix /bin/*, $(modules))

################################################################################

.PHONY: clean all info $(modules)

all: $(modules) tangram

tangram: $(modules)
	gcc $(subbins) -o $@ $(LIB)

$(modules):
	$(MAKE) -C $@


info:
	@echo "--------- compilation informations ----------"
	@echo "  compiler : $(CC)"
	@echo "  FLAGS    : $(FLAGS)"
	@echo "  IGNORED  : $(IGNORED)"
	@echo "  LIB      : $(LIB)"


clean:
	rm -f rm $(exec) $(bin)* $(subbins) tangram

exec = tangram
modules = geometry gui state game

################################################################################

FLAGS = -g -O2 -Werror -Weverything -Wfatal-errors -std=c++17
IGNORED =  -Wno-unused-parameter -Wno-effc++ -Wno-shadow -Wno-c++98-compat -Wno-padded -Wno-weak-vtables
IGNORED += -Wno-global-constructors -Wno-exit-time-destructors -Wno-unused-template

export CC = clang++
export LIB = -lm -lstdc++ -lMLV -lSDL
export CFLAGS = $(FLAGS) $(IGNORED)

export src = src/
export bin = bin/
export header = include/

# Create bin if it does not exists
$(shell mkdir -p $(bin))
subbins = $(addsuffix /bin/*, $(modules))

################################################################################

.PHONY: clean all info $(modules)

all: $(modules) tangram

tangram: $(modules)
	$(CC) $(subbins) -o $@ $(LIB)

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

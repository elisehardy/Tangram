exec = tangram
modules = geometry game state gui

################################################################################

export CC = clang++
export FLAGS = -g -O2 -Werror -Weverything -Wfatal-errors -std=c++17
IGNORED = -Wno-unused-parameter -Wno-effc++ -Wno-shadow -Wno-c++98-compat -Wno-sign-conversion -Wno-padded
IGNORED += -Wno-global-constructors -Wno-weak-vtables -Wno-delete-non-virtual-dtor -Wno-exit-time-destructors
IGNORED += -Wno-c++11-narrowing -Wno-unneeded-internal-declaration -Wno-float-conversion -Wno-unused-template
IGNORED += -Wno-unused-function -Wno-unused-private-field
export IGNORED
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

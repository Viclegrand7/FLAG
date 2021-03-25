BIN := KICV_ELLD


CC := g++
CFLAGS = -std=c++2a -g -Wall -Werror -Wshadow -Wunreachable-code \
-Wuninitialized -Wduplicated-cond -Wduplicated-branches -Wpedantic -m64 \
 -I /usr/include
RLSFLAGS = -std=c++2a -m64 -O3 -DNDEBUG -I /usr/include

DBGFLAG := $(filter test, $(MAKECMDGOALS))
REALFLAGS = $(if $(DBGFLAG), $(CFLAGS), $(RLSFLAGS))

OBJ = $(patsubst %.cc, %.o, $(wildcard *.cc))

COMPILE = $(CC) $(REALFLAGS) $(TARGET_ARCH) -c

all : $(BIN)

$(BIN) : $(OBJ)
	$(CC) $(REALFLAGS) $^ $(ENGOBJ) $(LDLIBS) -o $@

%.o : %.cc
	$(COMPILE) -o $@ $<

.PHONY : clean test debug love all 

debug : REALFLAGS = $(CFLAGS) 
debug : $(BIN)



clean : 
	rm -f $(BIN) $(OBJ)
	
love : 
	@echo "not war"
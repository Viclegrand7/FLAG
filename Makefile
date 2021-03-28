BIN := KICV_ELLD.exe


CC := g++
CFLAGS = -std=c++2a -g -Wall -Werror -Wshadow -Wunreachable-code \
-Wuninitialized -Wduplicated-cond -Wduplicated-branches -Wpedantic -m64 \
 -I /usr/include
RLSFLAGS = -std=c++2a -m64 -O3 -DNDEBUG -I /usr/include

DEPFLAGS = -MT $@ -MMD -MP -MF $*.Td
POSTCOMPILE = mv -f $*.Td $*.d && touch $@

DBGFLAG := $(filter test, $(MAKECMDGOALS))
REALFLAGS = $(if $(DBGFLAG), $(CFLAGS), $(RLSFLAGS))

OBJ 	 = $(filter-out testcase.o, $(patsubst %.cc, %.o, $(wildcard *.cc)))
OBJ_TEST = $(filter-out main.o, $(patsubst %.cc, %.o, $(wildcard *.cc)))

COMPILE = $(CC) $(REALFLAGS) $(DEPFLAGS) $(TARGET_ARCH) -c

all : $(BIN)

$(BIN) : $(OBJ)
	$(CC) $(REALFLAGS) $^ $(LDLIBS) -o $@

%.o : %.cc %.d
	$(COMPILE) -o $@ $<
	$(POSTCOMPILE)


DEPFILES := $(OBJ:%.o=%.d) testcase.d
$(DEPFILES):
include $(wildcard $(DEPFILES))

.PHONY : clean test debug love all 

debug : REALFLAGS = $(CFLAGS) 
debug : $(BIN)

testcase: $(OBJ_TEST)
	$(CC) $(REALFLAGS) $^ $(LDLIBS) -o $@.exe

clean : 
	rm -f $(BIN) $(OBJ) testcase.exe testcase.o
	
love : 
	@echo "not war"

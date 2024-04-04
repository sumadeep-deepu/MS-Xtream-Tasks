CMP=g++
INCLUDE=-Iinclude

BINDIR=bin
OBJ=array
BIN=$(BINDIR)/$(OBJ)
SRCDIR=src
SRC=$(SRCDIR)/*.cpp

all:
	$(CMP) -o $(BIN) $(SRC) $(INCLUDE)
run:
	./$(BIN)
remove:
	rm -f $(BIN)

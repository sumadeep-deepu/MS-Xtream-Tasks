COMPILER=g++
CPPFLAGS= -g -Wall
LIBS= -l:libubacsbu2webapp.so.1.5.6 -l:libubacappiinfo.so.1.0.0 -l:libubacipc.so.1.4.4 -l:libubacjsonparser.so.1.2.8

INCLUDE=-Iinclude
SRCDIR=src
BINDIR=bin
SRC=$(SRCDIR)/*.cpp
BIN=$(BINDIR)/httpserver
CONFIGDIR=config
CONFIG=$(CONFIGDIR)/configuration.json
JSON=app_info.json

all:
	$(COMPILER) $(CPPFLAGS) -o $(BIN) $(SRC) $(INCLUDE) $(LIBS)

run:
	./$(BIN) $(CONFIGDIR)/$(JSON) $(CONFIG)

remove:
	rm -f $(BINDIR)/*
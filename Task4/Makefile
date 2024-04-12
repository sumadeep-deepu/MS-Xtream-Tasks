PKG_NAME=libubacappiinfo
PKG_VERSION=1.0.0
UBAC_PKG_DEPENDS=libubacjsonparser.so.1.2.8
OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/jsonparser

LIBS = -lyajl -l:libubacjsonparser.so.1.2.8

CPP = g++
CPPFLAGS = -g --shared -Wall   -fpic          
SRC = src/*
BIN = bin

INCLUDE = -I include
OBJ = $(BIN)/$(OBJ_NAME)

all:
		$(CPP) $(SRC) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $(OBJ)

install-bin:
		cp $(OBJ) /usr/local/lib/
			ldconfig /usr/local/lib

install-dev:
		test -d $(install_include_dir) ||  mkdir $(install_include_dir)
			cp include/* $(install_include_dir)/

install: install-bin install-dev

clean:
		rm -f $(BIN)/*


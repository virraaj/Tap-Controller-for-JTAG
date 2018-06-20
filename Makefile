include ../Makefile.config

PROJECT = main
OBJS    = $(PROJECT).o $(DEP1).o $(DEP2).o
DEP1     = tap
DEP2     = tb


include ../Makefile.rules

# Makefile--
# AUTHOR:Ruikang Dai
# DATE:Sat Mar 14 11:55:21 EDT 2015
#CC	= gcc
#CCOPT	= -g -DDEBUG -DPRINT
#CCOPT	= -O2

command: keeplog.o liblist.o libkeeplog.o
	cc libkeeplog.o liblist.o keeplog.o -o $@
liblist.o: keeploglib.c listlib.h
	cc -g listlib.c -c -o $@
libkeeplog.o: keeploglib.c listlib.h
	cc -g keeploglib.c -c -o $@
keeplog.o: keeplog.c listlib.h
	cc -g keeplog.c -c -o $@

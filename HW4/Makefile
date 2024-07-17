#for compiling grades.c to grades.o
CC= gcc
CCFLAGS=-g -Wall -std=c99
CCLINK=$(CC)
#our object and library
OBJS= grades.o
SO=libgrades.so
#remove what we have made
RM= rm -rf grades.o libgrades.so

$(SO): $(OBJS)
	$(CCLINK) $(CCFLAGS) -shared $(OBJS) -o $(SO) -llinked-list -L.

grades.o: grades.c grades.h linked-list.h
	$(CC) $(CCFLAGS) -c -fpic grades.c 

clean:
	$(RM)

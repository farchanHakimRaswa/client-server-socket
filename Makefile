#--------------------------------------------------------
SOURCES = main.c \
	  client.h
LIBS = -lpthread
EXECUTABLE = test
#---------------------------------------------------------
CC=gcc
CFLAGS=-c -Wall
LDFLAGS= -pipe -O2 
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(HEADER) $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) core *~ *.so *.lo *.o
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(LIBS) $< -o $@

IDIR =../include
CC=gcc
CFLAGS= -I$(IDIR) -g -std=c++11 -O0

ODIR=.

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f  main
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append        
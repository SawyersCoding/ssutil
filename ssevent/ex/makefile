
CC=g++

EXAMPLE=example

DEPS=ssevent.o

%.o: $(addprefix ../src/, %.cpp)
	$(CC) -c -o $@ $^

$(EXAMPLE): $(EXAMPLE).cpp $(DEPS)
	$(CC) -o $(EXAMPLE) $^

clean:
	rm -f *.o
	rm -f *.exe
	rm -f $(EXAMPLE)
CC=g++
FLAGS=-lm
EXE=main_.exe
OBJS=dutchflag.o main.o
 
$(EXE):$(OBJS)
	$(CC) $(FLAGS) -o $(EXE) $(OBJS)
%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<
clean:
	rm $(OBJS)

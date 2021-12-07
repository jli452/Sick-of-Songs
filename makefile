FLAGS = -Wall -Wextra -g

CA = 5
LASTNAME = Li
BU_USERID = jli452
GITHUB_USERID = jli452
EXECUTABLE = main
CC = g++
OBJS = main.o System.o Song.o Heap.o User.o Graph.o Library.o


$(EXECUTABLE): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(EXECUTABLE)

System.o: System.cpp System.h BST.h
	$(CC) $(FLAGS) -g -c System.cpp

Song.o: Song.cpp Song.h
	$(CC) $(FLAGS) -g -c Song.cpp

Heap.o: Heap.cpp Heap.h
	$(CC) $(FLAGS) -g -c Heap.cpp

User.o: User.cpp User.h
	$(CC) $(FLAGS) -g -c User.cpp

Graph.o: Graph.cpp Graph.h
	$(CC) $(FLAGS) -g -c Graph.cpp

Library.o: Library.cpp Library.h
	$(CC) $(FLAGS) -g -c Library.cpp

tar: clean
	cd .. && tar -cvzf CA$(CA)_$(LASTNAME)_$(BU_USERID).tar.gz cs240-spring21-ca$(CA)-$(GITHUB_USERID) && cd -

scrub: clean
	rm ~* *.swp *\#

run: $(EXECUTABLE)
	./$(EXECUTABLE)

memcheck: $(EXECUTABLE)
	valgrind ./$(EXECUTABLE)

clean:
	rm -f *.o $(EXECUTABLE)

mazeGenerator: main.o unionfind.o mazegen.o
        g++ -o mazeGenerator main.o unionfind.o mazegen.o

main.o: main.cpp
        g++ -c main.cpp

unionfind.o: unionfind.cpp unionfind.h
        g++ -c unionfind.cpp

mazegen.o: mazegen.cpp mazegen.h
        g++ -c mazegen.cpp

clean:
        rm -f mazeGenerator *.o *-


all:
	g++ WindLoad.cpp -c -o ./WindLoad.o
	g++ ConsoleProject1.cpp WindLoad.o -o ./ConsoleProject1.o
clean:
	rm ./ConsoleProject1
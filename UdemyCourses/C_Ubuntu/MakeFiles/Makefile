OBJECT_FILES = ./build/one.o ./build/two.o

system: ${OBJECT_FILES}
./build/one.o: ./one.cpp
	g++ one.cpp -c -o ./build/one.o
./build/two.o: ./two.cpp
	g++ two.cpp -c -o ./build/two.o
all: system
	g++ main.cpp ${OBJECT_FILES} -o ./main

clean:
	rm ./main
	rm ${OBJECT_FILES}
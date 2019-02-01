all:TestMessage.exe

TestMessage.exe:main.o message.o
	g++ main.o message.o -o $@

main.o:main.cpp
	g++ -c main.cpp -o main.o

message.o:message.cpp
	g++ -c message.cpp -o message.o

clean:
	rm -v *.o TestMessage.exe


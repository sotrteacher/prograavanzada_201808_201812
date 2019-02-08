all:Test_Nota_Nota_Directorio.exe

Test_Nota_Nota_Directorio.exe:Test_Nota_Nota_Directorio.o Nota_Directorio.o Nota.o 
	g++ $^ -o $@

#main.o:main.cpp
#	g++ -c main.cpp -o main.o
#
#message.o:message.cpp
#	g++ -c message.cpp -o message.o

clean:
	rm -v *.o *.exe


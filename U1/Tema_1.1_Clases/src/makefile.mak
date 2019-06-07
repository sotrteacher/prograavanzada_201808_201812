all-before:Test_Nota_Nota_Directorio.cpp
#	g++ -E Test_Nota_Nota_Directorio.cpp -o Test_Nota_Nota_Directorio.i
	g++ -E dummy.cpp -o dummy.i

#Nota_Directorio.o:Nota_Directorio.cpp
#	g++ -DDISC_2016620256 -c Nota_Directorio.cpp -o Nota_Directorio.o

CXXFLAGS +=-DDISC_2011640360 -DDISC_2015080063 -DDISC_2016620256 \
-DDISC_2016640031 -DDISC_2019640503 -DDISC_2013090388 -DDISC_2015031144 \
 
 


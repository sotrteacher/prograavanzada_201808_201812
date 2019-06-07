all:Test_Nota_Nota_Directorio.exe 

#DISCENTES=2016640031.o \
#	  2014030116.o \
#	  2015090762.o

#2018640271.o
#DISCENTES=2011640360.o\
#	2014030116.o\

#DISCENTES=2013090388.o\

#DISCENTES=2015040092.o\

#	2015080865.o\
	

#	2016640087.o\
	
#	2017362541.o\

#	2018640271.o\

#	2017640791.o\

#	2015080693.o\


#	2015090762.o\

#2013090388.o\

#	2015031144.o

#DISCENTES=2016620256.o\
#	2015080063.o\
#	2016640031.o\
#	2019640503.o\
#	2011640360.o
                   
#MFLAGS=-DDISC_2016620256 -DDISC_2015080063 -DDISC_2016640031 \
#-DDISC_2011640360 -DDISC_2019640503 


Nota_Directorio.o:Nota_Directorio.cpp
	g++ $(MFLAGS) -c $^ -o $@

Test_Nota_Nota_Directorio.o:Test_Nota_Nota_Directorio.cpp
	g++ $(MFLAGS) -c $^ -o $@
                   
Test_Nota_Nota_Directorio.exe:Test_Nota_Nota_Directorio.o \
Nota_Directorio.o Nota.o gettingdate.o Nota_Directorio_weak.o \
Test_Nota_Nota_Directorio_weak.o $(DISCENTES)
	g++  $^ -o $@
	-cp -v $@ ../ 


#Test_Nota_Nota_Directorio1.exe:Test_Nota_Nota_Directorio.o Nota_Directorio1.o Nota.o 2014030116.o
#	g++ $^ -o $@

clean:
	@-rm -v *.o *.exe

.PHONY:all clean


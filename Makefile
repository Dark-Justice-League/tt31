all: tt12

tt12: main.o  help.o ciz_information.o sotrudnik_information.o shop_information.o
	g++ main.o help.o ciz_information.o sotrudnik_information.o shop_information.o -o tt12
main.o: main.cpp
	g++ main.cpp -c -o main.o

help.o: help.cpp 
	g++ help.cpp -c -o help.o

ciz_information.o: ciz_information.cpp
	g++ ciz_information.cpp -c -o ciz_information.o

sotrudnik_information.o: sotrudnik_information.cpp
	g++ sotrudnik_information.cpp -c -o sotrudnik_information.o
    
shop_information.o: shop_information.cpp
	g++ shop_information.cpp -c -o shop_information.o
clean:
	rm -rf *.o tt12
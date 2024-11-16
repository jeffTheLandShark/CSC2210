# makefile for balance code

a.out: dollar.o balance.o
	g++ dollar.o balance.o

dollar.o: dollar.h dollar.cpp
	g++ -c dollar.cpp

balance.o: dollar.h balance.cpp
	g++ -c balance.cpp

clean:
	rm -f dollar.o balance.o a.exe a.out

incpath= /home/seth-linux-pc/Documents/Big_Cpp_Source_Code/cccfiles
libpath=/home/seth-linux-pc/Documents/Big_Cpp_Lib
libs = -lccc -lX11
objects=Square.o Rectangle.o Triangle.o Shape.o

all: prog8_11 prog8_12 prog8_13

prog8_13: main3.cpp Icon.o Circle.o $(objects)
	g++ -I $(incpath) main3.cpp Icon.o Circle.o $(objects) -L $(libpath) $(libs) -o prog8_13

prog8_11: main1.cpp $(objects)
	g++ -I $(incpath) main1.cpp $(objects) -L $(libpath) $(libs) -o prog8_11

prog8_12: main2.cpp Icon.o $(objects)
	g++  -I $(incpath) main2.cpp Icon.o $(objects) -L $(libpath) $(libs) -o prog8_12

Circle.o: Circle.cpp $(objects)
	g++ -c -I $(incpath) Circle.cpp -L $(libpath) $(libs)

Icon.o: Icon.cpp $(objects)
	g++ -c -I $(incpath) Icon.cpp $(objects) -L $(libpath) $(libs)

Square.o: Square.cpp
	g++ -c -I $(incpath) Square.cpp -L $(libpath) $(libs)

Rectangle.o: Rectangle.cpp
	g++ -c -I $(incpath) Rectangle.cpp -L $(libpath) $(libs)

Triangle.o: Triangle.cpp
	g++ -c -I $(incpath) Triangle.cpp -L $(libpath) $(libs)

Shape.o: Shape.cpp 
	g++ -c -I $(incpath) Shape.cpp -L $(libpath) $(libs)

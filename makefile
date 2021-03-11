main_executable: driver.o mystring.o
	g++ -g -o driver driver.o mystring.o
	chmod 755 driver

driver.o: driver.cpp mystring.h
	g++ -g -c driver.cpp
    
mystring.o: mystring.cpp mystring.h
	g++ -g -c mystring.cpp    

clean:
	rm -f *.o
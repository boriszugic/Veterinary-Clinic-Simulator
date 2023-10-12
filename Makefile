CXX = g++
FLAGS = -Wall

a5: main.o Animal.o Appt.o Date.o Schedule.o Time.o Control.o View.o
	$(CXX) $(FLAGS) -o a5 main.o Animal.o Appt.o Date.o Schedule.o Time.o Control.o View.o

main.o: main.cc Control.h
	$(CXX) $(FLAGS) -c main.cc

Animal.o: Animal.cc defs.h
	$(CXX) $(FLAGS) -c Animal.cc

Appt.o: Appt.cc Animal.h Date.h
	$(CXX) $(FLAGS) -c Appt.cc

Date.o: Date.cc Time.h
	$(CXX) $(FLAGS) -c Date.cc

Schedule.o: Schedule.cc Animal.h List.h Appt.h
	$(CXX) $(FLAGS) -c Schedule.cc

Time.o: Time.cc 
	$(CXX) $(FLAGS) -c Time.cc

Control.o: Control.cc View.h Appt.h List.h
	$(CXX) $(FLAGS) -c Control.cc

View.o: View.cc 
	$(CXX) $(FLAGS) -c View.cc

clean:
	rm -f *.o a5
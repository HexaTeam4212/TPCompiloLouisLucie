CPPFLAGS = -pedantic -std=c++11  -g
MAPFLAG = 

EXEC = 	analog
SRCPP = $(wildcard *.cpp)
OBJETS = $(SRCPP:.cpp=.o)

.PHONY : target clean realclean

target : $(EXEC)

%.o : %.cpp %.h
	@echo "Compil de <$<>"
	g++ $(CPPFLAGS) $(MAPFLAG) -c $<

$(EXEC) : $(OBJETS)
	@echo "EDL de <$(EXEC)>"
	g++ -o $(EXEC) $(OBJETS)

clean :
	rm -f *.o core

realclean :
	rm -f *~

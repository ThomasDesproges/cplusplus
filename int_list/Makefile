CXX=g++
CXXFLAGS=-Wall -g
RM=rm -f

test : test_intlist.o
	$(CXX) $(CXXFLAGS) $^ -o $@ 

test_intlist.o : test_intlist.cpp intlist.h

%.o:%.cpp; $(CXX) $(CXXFLAGS) -o $@ -c $<

clean :
	$(RM) test_intlist.o



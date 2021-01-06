CXX=g++
CXXFLAGS=-Wall -ggdb
RM=rm -f

test_intstack : intstack.o test_intstack.o
	$(CXX) $(CXXFLAGS) $^ -o $@ 

test_intstack.o : test_intstack.cpp intstack.cpp

%.o:%.cpp; $(CXX) $(CXXFLAGS) -o $@ -c $<

clean :
	$(RM) intstack.o test_intstack.o
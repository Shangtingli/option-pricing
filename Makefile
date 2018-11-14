EXENAME1 = TestCases1
EXENAME2 = Main
OBJS = test1.o options.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lpthread

all : $(EXENAME1) $(EXENAME2)

$(EXENAME1) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME1)

$(EXENAME2) : main.o options.o
	$(LD) main.o options.o $(LDFLAGS) -o $(EXENAME2)

main.o : main.cpp options.o
	$(CXX) $(CXXFLAGS) main.cpp

test1.o : test1.cpp options.o
	$(CXX) $(CXXFLAGS) test1.cpp

options.o : options.cpp options.h
	$(CXX) $(CXXFLAGS) options.cpp

clean :
	-rm -f *.o $(EXENAME1)$(EXENAME2)

CXX = clang++

CXXFLAGS =	-O3 -g -Wall -fmessage-length=0 -std=c++11

VPATH = ../src:../include

OBJS =		Parser.o

LIBS =

TARGET =	Parser

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

CXX=g++ -std=c++11
CFLAGS=-O2
WARN=-Wall -Werror
EXECUTABLE=graph_test.o
OBJS=$(SOURCES:.cpp=.o)
SOURCES=test_graph.cpp

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CFLAGS) $(WARN) $(SOURCES) -o $@


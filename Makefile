CXX = g++
TARGET = kv_server

SOURCES = \
	main.cpp \
	src/server/server.cpp \
	src/session/session.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CXXFLAG = -std=c++20 -Wall -Wextra
CPPFLAGS = -I include -MMD -MP

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAG) -c $< -o $@



clean: 
	rm -f $(OBJECTS) $(TARGET)

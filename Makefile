CXX = g++
TARGET = echo_server
CXXFLAG = -std=c++20 -Wall -Wextra
CPPFLAGS = -I include

$(TARGET): main.o server.o session.o
	$(CXX) main.o server.o session.o -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c main.cpp -o main.o
server.o: src/server/server.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c src/server/server.cpp -o server.o
session.o: src/session/session.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c src/session/session.cpp -o session.o

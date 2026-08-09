CXX = g++
TARGET = echo_server

CXXFLAG = -std=c++20 -Wall -Wextra
CPPFLAGS = -I include

$(TARGET): main.o server.o session.o
	$(CXX) $^ -o $@
main.o: main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
server.o: src/server/server.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
session.o: src/session/session.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

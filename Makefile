CXX = g++
TARGET = echo_server

CXXFLAG = -std=c++20 -Wall -Wextra
CPPFLAGS = -I include

$(TARGET): main.o src/server/server.o src/session/session.o
	$(CXX) $^ -o $@
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAG) -c $< -o $@

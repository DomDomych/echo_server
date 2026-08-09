CXX = g++

echo_server: main.o server.o session.o
	$(CXX) main.o server.o session.o -o echo_server
main.o: main.cpp
	$(CXX) -Iinclude -c main.cpp -o main.o
server.o: src/server/server.cpp
	$(CXX) -Iinclude -c src/server/server.cpp -o server.o
session.o: src/session/session.cpp
	$(CXX) -Iinclude -c src/session/session.cpp -o session.o

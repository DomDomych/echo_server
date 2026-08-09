echo_server: main.o server.o session.o
	g++ main.o server.o session.o -o echo_server
main.o: main.cpp
	g++ -Iinclude -c main.cpp -o main.o
server.o: src/server/server.cpp
	g++ -Iinclude -c src/server/server.cpp -o server.o
session.o: src/session/session.cpp
	g++ -Iinclude -c src/session/session.cpp -o session.o

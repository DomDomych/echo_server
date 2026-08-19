CXX = g++
SERVER_TARGET = kv_server
CLIENT_TARGET = kv_client

SERVER_SOURCES = \
	main.cpp \
	src/server/server.cpp \
	src/session/session.cpp

CLIENT_SOURCES = \
	src/client/client.cpp

SERVER_OBJECTS = $(SERVER_SOURCES:.cpp=.o)
CLIENT_OBJECTS = $(CLIENT_SOURCES:.cpp=.o)

CXXFLAGS = -std=c++20 -Wall -Wextra
CPPFLAGS = -I include -MMD -MP


OBJECTS = $(SERVER_OBJECTS) $(CLIENT_OBJECTS)
DEPS = $(OBJECTS:.o=.d)

.PHONY: all clean

all: $(SERVER_TARGET) $(CLIENT_TARGET)

$(SERVER_TARGET): $(SERVER_OBJECTS)
	$(CXX) $^ -o $@

$(CLIENT_TARGET): $(CLIENT_OBJECTS)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean: 
	rm -f $(OBJECTS) $(DEPS) $(SERVER_TARGET) $(CLIENT_TARGET)

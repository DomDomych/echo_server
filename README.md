# Echo Server

A simple synchronous TCP echo server written in C++20 using Boost.Asio.

The server accepts a TCP connection, reads data sent by the client, and sends the same data back.

This project is intended for learning basic TCP networking, Boost.Asio, and CMake.

## Requirements

- C++20 compatible compiler
- CMake 3.16 or newer
- Boost
- netcat (`nc`)

On Ubuntu/Debian:

```bash
sudo apt install build-essential cmake libboost-all-dev netcat-openbsd
```

## Build

Clone the repository:

```bash
git clone https://github.com/DomDomych/echo_server.git
cd echo_server
```

Configure the project:

```bash
cmake -S . -B build
```

Build it:

```bash
cmake --build build
```

## Run

Start the server:

```bash
./build/echo_server
```

The server listens on TCP port `8080`.

Open another terminal and connect to it:

```bash
./scripts/connect.sh
```

Now type any message:

```text
hello
```

The server will send the same data back:

```text
hello
```

## How it works

The server uses a blocking, synchronous model.

For each client it:

1. accepts a TCP connection;
2. creates a session for the connected client;
3. waits for incoming data;
4. sends the received data back;
5. repeats until the client disconnects.

Because the implementation is synchronous, one client is served at a time.

## Project structure

```text
echo_server/
├── include/
│   ├── server/
│   └── session/
├── src/
│   ├── server/
│   └── session/
├── scripts/
│   └── connect.sh
├── CMakeLists.txt
├── Makefile
└── main.cpp
```

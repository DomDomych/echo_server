# TCP Key-Value Server

A simple synchronous TCP key-value server written in C++20 using Boost.Asio.

The server stores key-value pairs in memory and supports a small line-based protocol.

## Commands

```text
SET key value
GET key
DEL key
```

Example:

```text
SET name Damir
OK

GET name
Damir

DEL name
OK
```

The storage is shared between client sessions and exists while the server is running.

## Build

Requirements:

* C++20 compiler
* CMake 3.16+
* Boost

Build the project:

```bash
./scripts/build.sh
```

## Run

Start the server:

```bash
./build/tcp_key_value_server
```

The server listens on port `8080`.

Connect from another terminal:

```bash
./scripts/connect.sh
```

## Notes

The current version uses synchronous I/O and handles one client at a time.

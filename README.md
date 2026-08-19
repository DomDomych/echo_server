# TCP Key-Value Server

A simple synchronous TCP key-value server and command-line client written in C++20 using Boost.Asio.

The server stores key-value pairs in memory and uses a small line-based protocol.

## Commands

The following commands are supported:

```text
SET key value
GET key
DEL key
```

Example:

```text
> SET name Damir
OK!

> GET name
Damir

> DEL name
OK!

> GET name
No Such Key!
```

## Requirements

* C++20 compatible compiler
* CMake 3.16+
* Boost
* clang-format (optional, for formatting)

## Build

Build both the server and client:

```bash
./scripts/build.sh
```

The executables will be created in the `build` directory:

```text
build/kv_server
build/kv_client
```

## Run

Start the server:

```bash
./scripts/run_server.sh
```

The server listens on port `8080`.

In another terminal, start the client:

```bash
./scripts/run_client.sh
```

The client connects to `127.0.0.1:8080` and provides a simple interactive prompt:

```text
Connected
> SET language C++
OK!
> GET language
C++
> DEL language
OK!
```

Type `exit` to close the client.

## Formatting

Format the source files with:

```bash
./scripts/format.sh
```

## Notes

The current implementation uses synchronous I/O and handles one connected client at a time.

The storage is shared between client sessions and exists only while the server is running.

# Project Documentation

## Overview

This project consists of two separate C programs that demonstrate basic client-server communication over a TCP/IP network. The server and client programs are written in C and use the POSIX socket API for network communication.

### Server Program

The server program is designed to listen on a specified port, accept incoming connections from clients, receive messages from these clients, and send back a confirmation message.

### Client Program

The client program connects to the server on a specified hostname and port, sends a message to the server, and receives a response from the server.

## Getting Started

### Prerequisites

- A Unix-like operating system (Linux, BSD, macOS)
- GCC or another C compiler installed

### Compilation

To compile the programs, use the gcc compiler:

For the server:
```bash
gcc -o server server.c
```

For the client:
```bash
gcc -o client client.c
```

## Usage

### Server

Run the server program with the following command:

```bash
./server [port]
```

Replace `[port]` with the port number you want the server to listen on.

### Client

Run the client program with the following command:

```bash
./client [hostname] [port]
```

Replace `[hostname]` with the server's hostname or IP address and `[port]` with the port number the server is listening on.

## Program Details

### Server Program

1. **Initialization**: The server sets up a TCP socket and binds it to the specified port.
2. **Listening**: The server listens for incoming connections.
3. **Connection Handling**: Upon a successful connection, the server reads a message from the client.
4. **Response**: The server sends a confirmation message back to the client.
5. **Closure**: The server closes the client connection and then shuts down.

### Client Program

1. **Initialization**: The client sets up a TCP socket and connects it to the server's IP address and port.
2. **Communication**: The client sends a message to the server and waits for a response.
3. **Closure**: After receiving the server's response, the client closes the socket and exits.

## Error Handling

Both the server and client programs include basic error handling for network operations. In case of an error, the programs will output an appropriate message and terminate.

## Limitations

- The server handles one client at a time. Concurrent client handling is not implemented.
- The client and server are designed for basic text message exchange and do not support advanced networking features.
- Error handling is basic and does not cover all potential network issues.

## Conclusion

This project demonstrates the fundamentals of TCP/IP networking in C using POSIX sockets. It is suitable for educational purposes and as a starting point for more complex networked applications.

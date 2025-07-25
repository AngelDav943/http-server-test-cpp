# C++ basic HTTP server test
Testing out `httplib` to make a simple http server.

## Build executable
```g++ -std=c++11 -pthread -o main main.cpp -lws2_32```

## Notes:
`-pthread` flag basically enables multithreading support to the code. just in case
`-lws2_32` flag tells the linker to include the Winsock 2 library
`-S` flag makes the compiler stop at the initial c++ to assembly transform
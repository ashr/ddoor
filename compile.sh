#!/bin/bash
SRC_DIR=ddoor
g++ -std=c++11 -pthread -lresolv -O2 $SRC_DIR/main.cpp $SRC_DIR/crypto.cpp $SRC_DIR/startup.cpp $SRC_DIR/dns_query.cpp $SRC_DIR/process_commands.cpp -o bin/binary
strip bin/binary
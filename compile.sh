#!/bin/sh
g++ -std=c++11 main.cpp -lresolv -o bin/binary && strip bin/binary
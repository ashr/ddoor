#!/bin/sh
g++ -g -std=c++11 main.cpp -lresolv -o bin/binary && strip bin/binary
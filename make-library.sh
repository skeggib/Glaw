#!/bin/bash

g++ -c src/*.cpp
ar rcs libGlaw.a *.o
rm *.o

#!/bin/zsh

if [ $# -ne 1 ]
then
  echo "Missing file name!"
else
  g++ -pipe -O2 -std=c++14 $1.cpp -lm -o $1 &&
  ./$1 &&
  rm $1
fi

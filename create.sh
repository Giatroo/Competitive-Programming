#!/bin/zsh

if [ $# -ne 1 ]
then
  echo "Missing file name!"
else
  cp /media/sf_Coding/cppWorkspace/Maratona/template.cpp ./$1.cpp
  vim $1.cpp +51
fi

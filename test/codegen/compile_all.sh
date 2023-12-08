#!/bin/bash
for src in good*.bminor
do
  filename=${src%%.*}
  echo "Compiling " $filename
  ~/dfeng3-compiler/bminor --codegen $src $filename.s
  gcc -g $filename.s library.c -o $filename
done

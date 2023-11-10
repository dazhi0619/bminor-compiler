#!/bin/sh

for testfile in test/resolve/good*.bminor
do
  ./bminor --resolve $testfile > $testfile.out1
done

for testfile in test/resolve/good*.bminor
do
  ./bminor --resolve $testfile > $testfile.out2
done

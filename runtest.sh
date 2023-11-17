#!/bin/sh

for testfile in test/typecheck/good*.bminor
do
  ./bminor --typecheck $testfile > $testfile.out
done

for testfile in test/typecheck/bad*.bminor
do
  ./bminor --typecheck $testfile > $testfile.out
done

exit 0

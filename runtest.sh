#!/bin/sh

for testfile in test/print/good*.bminor
do
  ./bminor --print $testfile > $testfile.out1
done

for testfile in test/print/good*.bminor
do
  ./bminor --print $testfile > $testfile.out2
done

success=true
for testfile in test/print/good*.bminor
do
  file1=$testfile.out1
  file2=$testfile.out2
  diff $file1 $file2 > /dev/null
  if [ $? != 0 ]
  then
    echo "$file1 $file2 don't match!"
    success=false
  fi
done
if [ $success == true ]
then
  echo "success (as expected)"
else
  echo "failure (INCORRECT)"
fi

#!/bin/bash
for i in {1..150}
do
#cat "$(od -d if=/dev/random bs=3 count=1)" >> number.txt
#cat "$(od -N1 /dev/random)" >> number.txt
#echo "$(od -c -N2 /dev/random)" | cat - >> number.txt
od -An -N1 -i /dev/random >> number.txt
done
exit 0
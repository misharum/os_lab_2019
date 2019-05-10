#!/bin/bas
echo "$#"
ret=0
for i in $@
do
ret=$(($ret+$i))
done
ret=$((ret/$#))
echo "$ret"
exit 0

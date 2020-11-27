#!/bin/bash

s=`echo $((1 + RANDOM % 1000)) $((1 + RANDOM % 1000)) $((1 + RANDOM % 1000)) | ./a.out`;
#a=`echo -5 10 0 | ./a.out`;
while [ -z `echo $s | grep "Yes"`]
do
	s=`echo $((-10 + RANDOM % 100)) $((0 + RANDOM % 100)) $((-1 + RANDOM % 1000)) | ./a.out`;
done

echo $s;

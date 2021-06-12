#!/bin/bash 
ls -l
for i in $(ls);do
	cat $i
done

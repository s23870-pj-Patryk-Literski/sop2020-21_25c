#!/bin/bash
input=($@)

for ((i=0; i<$#; i++)) do
	cat ${input[$i]}; done
for ((i=$#-1; i>=0; i--)) do
	cat ${input[$i]}; done

#!/bin/bash
tablica=($@)
for ((i=0; i<$#; i++)) do
	echo ${tablica[$i]} ; done


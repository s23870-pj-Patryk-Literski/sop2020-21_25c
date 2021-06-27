#!/bin/bash
pliki=($(ls | grep .c))

for ((i=0; i<${#pliki[@]}; i++)) do 
	basename=${pliki[$i]}
	basename=${basename%%.*}
	cc ${pliki[$i]} -o $basename;
done


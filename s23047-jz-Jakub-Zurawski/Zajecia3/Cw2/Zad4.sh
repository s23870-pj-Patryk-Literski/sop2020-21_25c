#!/bin/bash
for f in ./*.c; do
nazwaPliku=$(basename $f)
samaNazwa=${nazwaPliku%.*}
samoRoz=${nazwaPliku##*.}
	echo $nazwaPliku $samaNazwa $samoRoz
	echo $f
	cc $f -o $samaNazwa 
done



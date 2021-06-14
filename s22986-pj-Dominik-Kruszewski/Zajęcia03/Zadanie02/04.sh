#!/bin/bash
for f in ./*.c; do
    nazwaPliku=$(basename ${f})
    nazwa=${nazwaPliku%.*}
    rozszerzenie=${nazwapliku##*.}
	cc $f -o $nazwa
done


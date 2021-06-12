#!/bin/bash
nazwaPliku=$(ls -p | grep -v /)
for i in ${nazwaPliku};
    do echo "Patrzcie państwo oto plik $i";
done

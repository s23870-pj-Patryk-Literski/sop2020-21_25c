#!/bin/bash
echo "\n tablica = (element 1 "element 2" element\ 3)"
TABLICA=(element1 "element 2" element\ 3)
echo 1
echo ${TABLICA[1]}
echo "*"
echo ${TABICA[*]}
echo "@"
echo ${TABLICA[@]}
echo "*"
echo ${TABLICA[*]}
echo "@ i *  razem z wykrzyknkiem" 
echo "${!TABLICA[@]} ${!TABLICA[*]}"
echo "@ z haszem"
echo ${#TABLICA[@]}


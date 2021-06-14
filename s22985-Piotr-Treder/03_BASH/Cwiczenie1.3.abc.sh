#!/bin/bash -e

nazwaPliku=$(basename ${1})    

samaNazwa=${nazwaPliku%.*}  # pobiera samą nazwę pliku 
samoRoz=${nazwaPliku##*.}   # sama nazwa rozszerzenia
echo $samaNazwa     
echo $samoRoz

if [ ${samoRoz} != "sh" ]; then
    mv ${0} ${0}.sh
fi 

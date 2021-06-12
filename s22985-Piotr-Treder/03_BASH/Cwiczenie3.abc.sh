#!/bin/bash -e

nazwaPliku=$(basename ${0})

samaNazwa=${nazwaPliku%.*}
samoRoz=${nazwaPliku##*.} 
echo $samaNazwa
echo $samoRoz

if [ ${samoRoz} != "sh" ]; then
    mv ${0} ${0}.sh
fi 

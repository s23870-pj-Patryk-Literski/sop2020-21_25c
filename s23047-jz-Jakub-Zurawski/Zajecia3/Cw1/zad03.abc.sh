#!/bin/bash

nazwaPliku=$(basename ${0})
samaNazwa=${nazwaPliku%.*}
samoRoz=${nazwaPliku##*.}

if [ ${samoRoz} != "sh" ]; then
	mv ${0} ${0}.sh
fi



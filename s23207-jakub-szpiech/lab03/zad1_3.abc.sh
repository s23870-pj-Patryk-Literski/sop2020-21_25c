#!/bin/bash

nazwapliku=$(basename ${0})
echo $nazwapliku
samanazwa=${nazwapliku%.*}
samoroz=${nazwapliku##*.}
echo $samanazwa
echo $samoroz

if [ ${samoroz} != "sh" ]; then
	mv ${0} ${0}.sh
fi


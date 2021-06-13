#!/bin/bash

nazwaPliku=$(basename ${0}}
nazwa=${nazwapliku%.*}
rozszerzenie=${nazwapliku##*.}

if [ ${rozszerzenie} != "sh" ]; then
    mv ${nazwaPliku} ${nazwaPliku}.sh
fi


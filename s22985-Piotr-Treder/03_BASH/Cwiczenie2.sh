#!/bin/bash

if [ -f config.cfg ]; then # -f oznacza "czy występuje plik "
    ./config.sfg    # jeżeli tak, wykonaj config.cfg
elif [ $# -gt 0 ]; then 
    ./$1
else echo błąd 
fi
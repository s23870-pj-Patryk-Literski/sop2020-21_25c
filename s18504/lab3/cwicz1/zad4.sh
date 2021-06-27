#!/bin/bash
count=$(ls $pwd | sort | wc -l)
if [[ 5 < $count ]]; then echo "w katalogu jest wiecej niz 5 plikow"
fi


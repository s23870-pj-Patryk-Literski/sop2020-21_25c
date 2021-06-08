#!/bin/bash

if [ $# -gt 1 ]; then               # $# <- liczba podanych parametrów
    echo $1;
else echo nie podano parametrów;
fi

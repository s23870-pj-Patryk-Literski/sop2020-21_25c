#!/bin/bash

function jakasFunkcja(){
    local  tekst=$1
    local  kolory=$2

    echo -e " \e[${kolory}m ${tekst} "
}
jakasFunkcja  $1 $2


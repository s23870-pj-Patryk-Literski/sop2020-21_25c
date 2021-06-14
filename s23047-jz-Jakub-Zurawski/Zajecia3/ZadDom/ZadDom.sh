#!/bin/bash

name=$(echo $1 | tr -d '[A-Z]' | tr -d '[0-9]' | tr -d '[:space:]' | tr -d '[:punct:]')
if [[ "$name" == "${1:1}" && ${#name} != 0 ]]; then echo "Podano imie"
fi

postCode=$(echo $1 | tr -d '[:alpha:]' | tr -d '[:space:]' | tr -d '[:punct:]')
postCodeVar="${1:0:2}${1:3}"
if [[ "$postCode" == "$postCodeVar" && ${#postCode} == 5 ]]; then echo "Podano kod pocztowy"
fi

basemail=${1%@*}
maildomain=${1##*@}
mail="$basemail@$maildomain"
if [[ "$1" == "$mail" && ${#maildomain} != 0 && ${#basemail} != 0 ]]; 
then echo "Podano adres email"
fi



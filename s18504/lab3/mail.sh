#!/bin/bash
basemail=${1%@*}
maildomain=${1##*@}
mail="$basemail@$maildomain"
if [[ "$1" == "$mail" && ${#maildomain} != 0 && ${#basemail} != 0 ]]; 
then echo "Podano prawidlowo adres email"
else echo "Podano nieprawidlowy adres email"
fi



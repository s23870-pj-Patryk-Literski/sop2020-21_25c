#!/bin/bash

basemail=${1%@*}
maildomain=${1##*@}
mail="$basemail@$maildomain"
if [[ "$1" == "$mail" && ${#maildomain} != 0 && ${#basemail} != 0 ]]; 
then echo "To jest email"
else echo "Nie jest to email"
fi




#!/bin/bash
pcode=$(echo $1 | tr -d '[:alpha:]' | tr -d '[:space:]' | tr -d '[:punct:]')
pcodeVar="${1:0:2}${1:3}"
if [[ "$pcode" == "$pcodeVar" && ${#pcode} == 5 ]]; then echo "Podano prawidlowy kod pocztowy"
else echo "Nie podano prawidlowego kodu pocztowego"
fi



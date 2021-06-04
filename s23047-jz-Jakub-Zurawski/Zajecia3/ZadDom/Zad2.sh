#!bin/bash

postCode=$(echo $1 | tr -d '[:alpha:]' | tr -d '[:space:]' | tr -d '[:punct:]')
postCodeVar="${1:0:2}${1:3}"
if [[ "$postCode" == "$postCodeVar" && ${#postCode} == 5 ]]; then echo "Podano kod pocztowy"
fi



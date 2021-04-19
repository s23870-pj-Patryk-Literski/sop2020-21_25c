#!/bin/bash
name=$(echo $1 | tr -d '[A-Z]' | tr -d '[0-9]' | tr -d '[:space:]' | tr -d '[:punct:]')
if [[ "$name" == "${1:1}" && ${#name} != 0 ]]; then echo "Podano prawidlowe imie"
else echo "Nie podano prawidlowego imienia"
fi



#!/bin/bash
name=$(echo $1 | tr -d '[A-Z]' | tr -d '[0-9]' | tr -d '[:space:]' | tr -d '[:punct:]')
if [[ "$name" == "${1:1}" && ${#name} != 0 ]]; then echo "Imie jest poprawnie napisane"
else echo "Imie jest zle napisane"
fi




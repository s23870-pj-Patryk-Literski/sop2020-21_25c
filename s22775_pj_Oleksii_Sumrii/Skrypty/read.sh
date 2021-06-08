#!/bin/bash 
imie="Oleksii"
text=$(cat $1)
echo -e "${text//${imie}/\\e[31m${imie}\\e[0m}"


#!/bin/bash

file=plik.txt
red='\e[31m'
end='\e[0m'
while read line; do
printf "$line" | sed s/Jakub/\\${red}*Jakub*${end}/g
done < $file


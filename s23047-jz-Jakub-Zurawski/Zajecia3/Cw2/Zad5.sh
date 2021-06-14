#!/bin/bash

table=(*)
echo -e "\e[34mnormal"
for i in ${table[@]}; do
echo  $i
done
echo -e "\e[35mreverse"
for (( i=${#table[@]}-1 ; i>=0 ; i-- )); do
echo "${table[i]}" 
done

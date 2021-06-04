#!/bin/bash

location="/home/ubuntu/Desktop/SOP/Lab3-Bash/Cw2/$1"
for i in "$location"/*;do
echo "Prosze Panstwa, oto plik: "$(basename $i)
done


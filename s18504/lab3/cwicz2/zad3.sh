#!/bin/bash
number=$(ls | sort | wc -l)
position=($(ls | sort))
for ((i=0; i<$number; i++)) do
echo "oto plik:" ${position[$i]};
done



#!/bin/bash

a=0
b=1
echo "Liczby fibo:"
function zad2 {
for (( i=0; i<10; i++ ));
do
return $a
echo $a
suma=$a+$b
a=$b
b=$suma;
done
}
zad2


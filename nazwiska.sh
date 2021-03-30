#skrypt z zadania domowego, po wywołaniu go z argumentem (nazwa pliku z listą nazwisk) wyświetlona zostanie zawartośc listy która podkresli moje naziwsko na czerwono
# np ./nazwiska.sh listanazwisk.txt


#!/bin/bash
A=$(sed 's/klimowski/\\e[31mKLIMOWSKI\\e[30m/gi' $1)
echo -e $A

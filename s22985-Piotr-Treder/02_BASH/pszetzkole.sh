#!/bin/bash
echo 'Podaj imię'
read var
X=${#var}
Y=a
#echo ${#X}
echo ${var:X-1:X}
echo $Y
if [ ${var:X-1:X} == $Y ]; then
    echo $var ma kota, a kot ma ${var:0:X-1}ę
else #[ ${var:X-1:X}!=$Y ]
     echo $var ma kota, a kot ma ${var}a
fi

echo ' Wprowadź tekst '
read var2
X2=${#var2}
echo '1. Pierwszy znak z argumentu'
echo ${var2:0:1}
echo '2. Ostatni znak z argumentu'
echo ${var2:X2-1:X2}
echo '3. Zamiana tekstu'
echo -e "${var2//'SOP'/\\e[32mSOP\\e[0m}"

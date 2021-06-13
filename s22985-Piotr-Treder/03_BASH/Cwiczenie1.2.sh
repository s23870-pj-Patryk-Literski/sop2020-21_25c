#!/bin/bash
    
if [ -f config.cfg ]; then # -f oznacza "czy występuje plik "
    ./config.cfg    # jeżeli tak, wykonaj config.cfg
elif [ $# -gt 0 ]; then # jeżeli liczba przyjętych parametrów jest większa od 0 // greater than <- -gt
    ./$1            #wyświetl pierwszy podany parametr / lub wywołuje podany skrypt
else echo błąd 
fi




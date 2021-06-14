#/bin/bash


if [ $# -gt 1 ]; then               # $# <- liczbę przekazanych parametrów
    for (( i = 1; i <= $#; i++ ))   # pętla które dodaje 1 aż do końca liczby paramertrów
    do  echo "${!i}"                # wyświetla patametr i-ty
        
    done
else echo nie podano parametrów;

fi

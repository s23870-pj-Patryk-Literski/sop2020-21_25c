#!/bin/bash

coto=$1

echo -e $coto ': \c' 

if [[ "$coto" =~ ^[A-Z][a-z]*$ ]]
    then 
        echo " imię "
elif [[ "$coto" =~ ^[0-9][0-9]-?[0-9][0-9][0-9] ]]
    then
        echo " kod pocztowy "
elif [[ "$coto" =~ ^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$ ]] 
    then 
        echo "adres e-mail"
    else
        echo " nic z tego "
fi
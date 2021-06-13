#!/bin/bash

if [ $(ls -l | grep -e ^- | wc -l) -gt 5 ]; then 
    # w poleceniu grep symbole ^ i $ to znaki 
    # identyfikujące odpowiednio początek 
    # i koniec słowa
    echo Jest wiecej niz 5 plikow 
fi
#!/bin/bash

if [ $(ls -l|grep -e ^- |wc -l) -gt 5 ]; then
	echo "Wiecej niz 5 plikow"
else echo"Nie ma tylu"
fi



#!/bin/bash
if [ $# -gt 1 ];
	then
		echo "$1";
elif [ $# -eq 1  ];
	then
		echo "Podan jeden parametr, napisz drugi"
else 
	echo "Nie podano parametrów";
fi


#!/bin/bash

if [ $(ls -l | grep -e ^- | wc -l) -lt  5 ];
	then
		echo "Mniej niż 5"
	else 
		echo "Więcej niż 5 =" $(ls -l | grep -e ^- | wc -l)	
fi


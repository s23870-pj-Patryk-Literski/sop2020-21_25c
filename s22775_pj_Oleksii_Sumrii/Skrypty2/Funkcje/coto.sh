#!/bin/bash

if [ $1 ];
	then
		echo $1 | awk '/[0-9][0-9]-[0-9][0-9][0-9]/'
	else 
		echo "Wpisz dobrze"
fi

if [ $2 ];
	then
		echo $2 | awk '/[a-zA-Z]/'
	else "Wpisz normalnie imie"
fi

if [ $3  ] 
	then
	   $ echo $3 | awk '/^([a-zA-Z0-9_\-\.\+]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$/{print $0}'


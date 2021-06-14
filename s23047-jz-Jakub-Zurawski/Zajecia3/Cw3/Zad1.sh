#!/bin/bash
function zad1 {
	echo "Podaj kolor: "
	read color
	echo "Podaj tekst:"
	read text
	declare -A colors;
	colors=(\
	["yellow"]='\e[33m'\
	["green"]='\e[32m'\
	["blue"]='\e[34m'\
	);
	yourColor="${colors[$color]}"
	echo -e $yourColor $text
}
zad1

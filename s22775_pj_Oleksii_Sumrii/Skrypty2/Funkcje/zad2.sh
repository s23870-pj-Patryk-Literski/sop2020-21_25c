#!/bin/bash

function fib 
{
	echo "Podaj liczbe naturalna: "
	read n
	if [ $n -lt 3 ];
	then
			return "fib(n-2)+fib(n-1)"	
	fi
}

fib $n


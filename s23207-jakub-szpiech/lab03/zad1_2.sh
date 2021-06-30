#!/bin/bash

if [ -f config.cfg ]; then
	./config.cfg
elif [ $# -gt 0 ]; then
	./$1
else
	echo "Error";
fi


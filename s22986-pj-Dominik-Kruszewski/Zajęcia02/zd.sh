#!/bin/bash

A=$(sed 's/kruszewski/\\e[31mKRUSZEWSKI\\e[30m/gi' $1)
echo -e $A

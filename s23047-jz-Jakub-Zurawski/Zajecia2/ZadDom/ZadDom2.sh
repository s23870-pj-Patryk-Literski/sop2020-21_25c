#!/bin/bash

Name=$(sed 's/Jakub/\\e[31mJAKUB\\e[0m/g' $1)
echo -e $Name

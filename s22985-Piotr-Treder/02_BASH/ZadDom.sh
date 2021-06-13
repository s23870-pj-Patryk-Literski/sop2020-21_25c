#!/bin/bash

var=`cat ZDom.txt`
echo -e "${var//'Piotr'/\\e[31mPiotr\\e[0m}"
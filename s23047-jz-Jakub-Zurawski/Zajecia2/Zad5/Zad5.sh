#!/bin/bash

echo "Dobry, prosze podac tekst, nastepnie wcisnac enter: "
read text
echo ${text:0:1}
echo ${text: -1}
echo -e ${text/SOP/\\e[32mSOP\\e[0m}

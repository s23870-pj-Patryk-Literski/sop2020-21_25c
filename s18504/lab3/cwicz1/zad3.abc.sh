#!/bin/bash
name=$(basename ${0})
echo "Nazwa pliku to: ${name}"
onlyname=${name%%.*}
extension=${name##*.}
echo "Test rozbicia:  ${onlyname} + ${extension}"
if [[ "sh" != ${extension} ]]; then mv ${0} ${0}.sh
fi


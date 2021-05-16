#!/bin/bash

if [ $(ls -l | grep -e ^- | wc -l) -gt 5 ]; then
    echo Jest wiecej niz 5 plikow 
fi
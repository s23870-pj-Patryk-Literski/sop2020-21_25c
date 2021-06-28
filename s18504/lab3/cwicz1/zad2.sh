#!/bin/bash

if [ -e config.cfg ]; then ./config.cfg
else if [[ 0 != $# ]]; then ./$1
else echo "error"
fi
fi


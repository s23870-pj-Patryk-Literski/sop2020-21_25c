#!/bin/bash
zawart="musi starac sie wiecej"
zmin="stara sie czegos sie nauczyc"
sed -e "s/${zmin}/${zawart}/g" $1 


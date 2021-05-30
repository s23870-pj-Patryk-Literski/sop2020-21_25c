#!/bin/bash

for i in  $(ls | grep .tt); do 
		mv ${i} r.txt
	done


#!/bin/bash

fib()
{

  if [ $1 <= 2 ] ; then
    echo 1
  else
    a=$(fib $[$1-1])
    b=$(fib $[$1-2])
    c=$(($a+$b))
    return $c
  fi
  
}
 var=$(fib)
 echo $var
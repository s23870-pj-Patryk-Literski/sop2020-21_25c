 #!/bin/bash

ciagFibonaciego(){
  local liczba=$1
  local x=0
  local y=1
  local z=1


  if [ ${liczba} -le 1 ] ; then
        echo  "${liczba} "
  else
  for((i=1; i <=${liczba} ; i++))
    do
        z=$((x+y))
        x=y
        y=z
    done
    echo " ${z}"
  fi
}

ciagFibonaciego $1

#/bin/bash


 funkcja () {
    liczba="$2"
    #echo $liczba
    
        if [ $liczba == "czerwony" ] ; then
            liczba='31';
        elif [ $liczba == "zielony" ]; then
            liczba='32';
        elif [ $liczba == "żółty" ]; then
            liczba='33'; 
        elif [ $liczba == "niebieski" ]; then
            liczba='34';
        elif [ $liczba == "magenta" ]; then
            liczba='35';
        elif [ $liczba == "szary" ]; then
            liczba='90';       
        else echo Brak koloru;
        fi
    #echo $liczba
       # echo -e "\e[`$liczba`mczerwony\e[0m"
    

        echo -e "\e["$liczba"m"$1"\e[0m"
            }

funkcja $1 $2





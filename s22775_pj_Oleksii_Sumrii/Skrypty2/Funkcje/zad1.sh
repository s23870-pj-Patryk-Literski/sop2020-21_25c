#!/bin/bash

echo "skrypt "tekst" kolor"
echo "czerwony "
echo "czarny "
echo "zielony "
echo "brazowy "
echo "niebieski "
echo "purpurowy "
echo "cyjan "
echo "jasnyszary "
red="czerwony"
black="czarny"
green="zielony"
brown="brazowy"
blue="niebieski"
purple="purpurowy"
cyan="cyjan"
lightgray="jasnyszary"

if [ "$2" ==  "${red}" ]; 
	then 
		echo -e "\e[31m$1\e[0m" 
	elif [ "$2" ==  "${black}" ]; 
		then 
			echo -e "\e[30m$1\e[0m" 
		elif [ "$2" ==  "${green}" ]; 
			then 
				echo -e "\e[32m$1\e[0m" 
			elif [ "$2" ==  "${brown}" ]; 
				then 
					echo -e "\e[33m$1\e[0m" 
				elif [ "$2" ==  "${blue}" ]; 
					then 
						echo -e "\e[34m$1\e[0m" 
					elif [ "$2" ==  "${purple}" ]; 
						then 
							echo -e "\e[35m$1\e[0m"
						elif [ "$2" ==  "${cyan}" ]; 
							then 
								echo -e "\e[36m$1\e[0m" 
							elif [ "$2" ==  "${lightgray}" ]; 
								then 
									echo -e "\e[37m$1\e[0m"  
fi


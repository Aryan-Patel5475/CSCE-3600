#/usr/bin/bash

ranNum=$[RANDOM%10+1]

userChoice=0

while [ $ranNum -ne $userChoice ]
do
	read -p "Enter a number between 1 and 10: " userChoice
	if test $ranNum -eq $userChoice
	then
		echo "Congratulations, the number is ${ranNum}.";
	else
		echo "Sorry, you are not correct. Try again!";
	fi
done
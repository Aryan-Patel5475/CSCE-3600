#!/bin/bash

if [ -z $1 ]
then
	echo "usage: ./rec05.sh <curve amount>"
	exit 0
fi

function curve() {
	local var1=$1
	shift
	local array=("$@")
	
	echo "Curved Grades: "
	
	let j=0
	for i in "${array[@]}"
	do
		let k=0
		echo -n "grades[$j] = "
		let "k = ${array[$j]} + $var1"
		let "j = $j + 1"
		echo $k
	done
}

let k=0
for i in 1 2 3 4 5
do
	echo -n "Enter QUIZ #$i: "; read num;
	pet[k]=$num
	let "k = $k + 1"
done

pas1=$1

curve $pas1 "${pet[@]}"
#!/bin/bash
# Name: Aryan Patel
# EUID: asp0144
# Date: 10/20/22
# Assignment: Minor2

#storing server name in a variable
host_name=`hostname`

#storing username in a string
string=`who | cut -d' ' -f1 | sort | uniq`

#converting string into array
arr=($string)

i=0
#copying array in another array
initial_list=("${arr[@]}")

host_name=`hostname`
todaysDate=`date`
#printing out the date
printf "$todaysDate ) initial user logged in\n"

#printing out the list of all the user who are already logged in
for ((i=0; i<${#arr[@]}; i++));
do
	printf ">${arr[$i]} logged in to $host_name\n"
done

#custom signal handler
sigint_signal()
{
	printf " (SIGINT) ignored. enter ^C 1 more time to terminate program.\n"
	trap - INT
}

trap 'sigint_signal' INT #trap '' INT

#looping until user enters control+c two times
while true
do
	
	#storing date in variable
	todaysDate1=`date`
	#storing length of the array in a variable
	num="${#initial_list[@]}"
	#printing out date and number of user
	printf "$todaysDate1 ) # of users: $num\n"
	
	# storing username in another array
	new_string=`who | cut -d' ' -f1 | sort | uniq`
	new_list=($new_string)
	
	#storing length of two variables to compare them
	num1="${#initial_list[@]}"
	num2="${#new_list[@]}"
	
	#comapring two arrays
	if [ "$num1" -ne "$num2" ]
	then
		#storing the difference between two array in another array
		array3=(`echo ${initial_list[@]} ${new_list[@]} | tr ' ' '\n' | sort | uniq -u`)
		#if inital_list is greater then new_list then print out user who logged out
		if [ "$num1" -gt "$num2" ]
		then
			printf ">${array3[@]} user logged out\n"
		fi
		# if inital_list is less then new_list then print out user who logged in
		if [ "$num1" -lt "$num2" ]
		then
			printf ">${array3[@]} user logged in\n"
		fi
		# updating inital_list
		initial_list=("${new_list[@]}")
	fi
	
	# waiting for 10 seconds before looping
	sleep 10
done

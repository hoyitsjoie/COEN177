# Name: Joy Zou 
# Date: TH 9:15 | 9/24/2020
# Title: Lab1 – Circle
# Description: This program computes the area of a Circle using the bc command for floating points

#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "jzou" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!" 
        exit 1
fi

response="Yes"
while [ $response != "No" ]
do
        echo "Enter radius of circle: "
        read radius
	x=`echo "$radius*$radius" |bc`
	echo $x
	area=`echo "$radius^2*3.14"| bc`
        echo "The area of the circle is $area"

        echo "Would you like to repeat for another circle [Yes/No]?"
        read response
done

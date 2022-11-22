//Name: Logan Rosenbaum
//Course Section: 004
//Date: October 16th, 2022
/*Description: This program takes a user entered int value, from between 1-4294967295, and converts it to binary. It then counts the
  number or 1's in that binary value, and returns 0 if the amount is even, and 1 if the amount is odd.*/
#include <stdio.h>
#include <math.h>
#include "major1.h"

void parity_num(void)
{
        long long num; //this variable will hold the user inputted value
        printf("Enter a 32-bit number (>=1 and <= 4294967295, inclusively): ");
        scanf("%lld", &num); //takes user input and stores it in num
        if(num < 1 || num > 4294967295) //Triggers if the user enteres an invalid number
        {
                num = 0;
                printf("Enter a 32-bit number (>=1 and <= 4294967295, inclusively): ");
                scanf("%lld", &num); //takes user input and stores it in num
        }
        //printf("%lld\n", num);
        long long temp = num; //variable to hold nums original value for use in the printf statement later on
        int tally = 0;
        int  i = 0; //incrementor variable

        //While loop to convert the users entered value into binary
        while(i<32)
        {
                tally+= num & 1;
                num >>= 1;
                i++; //increments i
                //printf("%lld, %lld\n", num, temp);

        }
//      printf("%d\n",tally);
        tally = tally & 1; //I do tally & 2 since if there were an odd number of zeroes, the remainder should be 1
//      printf("%d\n",tally);
        printf("Parity of %lld is %d\n", temp, tally);
}

#include "major1.h"
#include <stdio.h>

void rotate_num(void) {

    unsigned long long int RotateNum = 0;
    unsigned long long int RotateBy = 0;
    unsigned long long int store = 0;
    unsigned long long int Rotate_num = 0;
    unsigned long long int Rotate_by = 0;
    
    //Taking input of Number to rotate, using a loop preventing user from entering an invalid input.
    do{
        
        printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
        scanf("%lld", &RotateNum);
        Rotate_num = RotateNum;

        if (RotateNum < 1 || RotateNum > 4294967295){

            printf("Please match the condition provided and re-enter\n");
        }


    }while (RotateNum < 1 || RotateNum > 4294967295);
    
    //Taking input of Number to by, using a loop preventing user from entering an invalid input.
    do{

        if (RotateBy < 0 || RotateBy > 31){

            printf("Please match the condition provided and re-enter\n");
        }

        printf("Enter the number of positions to rotate-right the input (between 0 and 31, inclusively): ");
        scanf("%lld", &RotateBy);
        Rotate_by = RotateBy;
    
    }while(RotateBy < 0 || RotateBy > 31);
    
    //Rotate right using rotate >> RotateBy % 32
    //Extract the right bits depeding on rotateBy using RotateNum << (32 - RotateBy) % 32 and or with result
    store = (RotateNum >> RotateBy % 32)|(RotateNum << (32 - RotateBy) % 32);
    printf("%lld rotated by %lld position gives: %lld\n", Rotate_num, Rotate_by, store);

}

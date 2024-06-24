/**
 * @file p_ex1.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>


int main(void)
{
    int date,dd,mm,yyyy;
    printf("Enter a date (mm/dd/yyyy):");
    scanf(&dd);
    scanf(&mm);
    scanf(&yyyy);

    printf("You entered the date %d%d%d",yyyy,mm,dd);


    return 0;
}
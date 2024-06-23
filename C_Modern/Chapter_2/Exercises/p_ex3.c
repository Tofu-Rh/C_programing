#include <stdio.h>


int main(void){
    float r;
    float volume;
    

    printf("Enter the radius value of the esphere:");
    scanf("%f",&r);

    volume = (4/3.14f) * (1/r*r*r);

    printf("the volume is: %f\n",volume);
    return 0;
}
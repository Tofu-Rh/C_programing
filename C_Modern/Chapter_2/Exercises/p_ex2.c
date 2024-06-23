#include <stdio.h>


int main(void){
    float r = 10;
    float volume;
    
    volume = (4/3.14f) * (1/r*r*r);

    printf("the volume is: %f\n",volume);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    
    //mendeklarasikan varaibel yang akan dipakai
    int int1;
    int int2;
    float float1;
    float float2;
    
    //meminta user memasukkan input
    scanf("%d %d", &int1, &int2);
    scanf("%f %f", &float1, &float2);
    
    //menampilkan hasil ke layar
    printf("%d %d\n", int1+int2, int1-int2);
    printf("%.1f %.1f", float1+float2, float1-float2);
    
    return 0;
}

// สร้างผลคูณจากเลขที่รับจากผู้ใช้งาน
#include <stdio.h>

int main(){
    float a;
    float b;
    printf("Enter a number(1): ");
    scanf("%f", &a);
    printf("Enter a number(2): ");
    scanf("%f", &b);

    float result = a*b;

    printf("%f * %f is %f", a, b ,result);
    return 0;
}
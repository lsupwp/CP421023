// สร้างฟังก์ชันเพื่อแปลงหน่วยอุณหูมิจากเซลเซียส เป็นฟาเรนไฮ
#include <stdio.h>

int main(){
    double celsius;
    printf("Enter celsius: ");
    scanf("%lf", &celsius);

    double fahrenheit = (celsius * (9.0/5.0)) + 32.0;
    printf("Fahrenheit is %.2lf\n", fahrenheit);
    return 0;
}
// รับค่าตัวเลข แล้วตรวจสอบว่าเป้นจำนวนเต็มบวก เต็มลบ หรือศูนย์
#include <stdio.h>

int main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (number > 0){
        printf("%d เป็นจำนวนเต็มบวก\n", number);
    }else if (number == 0){
        printf("%d เป็นจำนวนเต็ม 0\n", number);
    }else{
        printf("%d เป็นจำนวนติดลบ\n", number);
    }
    return 0;
}
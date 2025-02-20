// สร้างฟังก์ชันการค่า Fibonacci ด้วย recursive function
#include <stdio.h>

int fibo(int n){
    if (n <= 1){
        return n;
    }else{
        return fibo(n-1) + fibo(n-2);
    }
}

int main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if(number < 0){
        printf("กรอกตัวเลขจำนวนเต็ม\n");
    }else{
        int result = fibo(number);
        printf("Fibonacci of %d is %d\n", number, result);
    }
    return 0;
}
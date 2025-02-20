#include <stdio.h>
#include <string.h>

int main(){
    int secret = 42;
    char buffer[8];

    printf("Inital value of secret: %d\n", secret);
    printf("Address of buffer: %p\n", (void *)buffer);
    printf("Address of secret: %p\n", (void *)&secret);

    strcpy(buffer, "This string is too long for buffer!");

    printf("Buffer content: %s\n", buffer);
    printf("Value of secret after overflow: %d\n", secret);
    return 0;
}
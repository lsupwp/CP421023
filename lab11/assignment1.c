// 673380166-0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Flight{
    char name[255];
    char departure[14];
}Flight;

#define N 8

int findPosition(Flight f[], char name[]){
    for(int i =0; i<N;i++){
        if(strcmp(f[i].name, name) == 0){
            return i+1;
        }
    }
    return -1;
}
char* findDeparture(Flight f[], char name[]) {
    for (int i = 0; i < N; i++) {
        if (strcmp(f[i].name, name) == 0) {
            char *d = (char*)malloc(20 * sizeof(char));
            if (d == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }
// 673380166-0
            sprintf(d, "%c%c%c%c-%c%c-%c%c %c%c:%c%c:%c%c", 
                f[i].departure[0], f[i].departure[1], f[i].departure[2], f[i].departure[3], 
                f[i].departure[4], f[i].departure[5], f[i].departure[6], f[i].departure[7], 
                f[i].departure[8], f[i].departure[9], f[i].departure[10], f[i].departure[11], 
                f[i].departure[12], f[i].departure[13]);
            return d;
        }
    }
    return NULL;
}

int outDeparture(Flight f[], int departureS, int departureE) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        char d[6];
        sprintf(d, "%c%c%c%c%c%c", 
        f[i].departure[8], f[i].departure[9], f[i].departure[10], 
        f[i].departure[11], f[i].departure[12], f[i].departure[13]);
        int d_s = atoi(d);

        if (d_s >= departureS && d_s <= departureE) {
            count++;
        }
    }
    return count;
}
// 673380166-0
int main(){
    Flight f[N] = {
        {"CZ 5027", "20221004000000"}, // 000000 x
        {"EK 376",  "20221004060400"}, // 060400 x
        {"EK 9889", "20221004000800"}, // 000800 x
        {"PG 132",  "20221004055733"}, // 055733 /
        {"PG 272",  "20221004043744"}, // 043744 /
        {"UL 402",  "20221004002300"}, // 002300 x
        {"WE 021",  "20221004024313"}, // 024313 x
        {"WE 260",  "20221004032308"}  // 032308 x  
        };

    // จากตารางการบินดังกล่าว จงเขียนโปรแกรมเพื่อค้นหาว่าเที่ยวบินที่ WE 021 อยู่ในลำดับที่เท่าไหร่
    printf("WE 021 is at position %d\n", findPosition(f, "WE 021"));

    // จากตารางการบินดังกล่าว จงเขียนโปรแกรมเพื่อค้นหาว่าเที่ยวบินที่ WE 021 มีเวลาออกกี่โมง
    char *d = findDeparture(f, "WE 021");
    printf("WE 021 departure time is %s\n", d);

    // จากตารางการบินดังกล่าว จงเขียนโปรแกรมเพื่อหาว่าเที่ยวมีกี่เที่ยวบินที่ออกเวลา 04.00-06.00 น.
    printf("Number of flights departing between 04.00-06.00 is %d\n", outDeparture(f, 40000, 60000));

    free(d);
}
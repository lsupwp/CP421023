// 673380166-0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8  // จำนวนข้อมูลในตาราง

// โครงสร้างสำหรับเก็บข้อมูลเที่ยวบิน
typedef struct {
    int no;
    char call_sign[10];
    char timestamp[15];  // YYYYMMDDHHMMSS
} Flight;

// ฟังก์ชัน Ternary Search
int ternary_search(Flight flights[], int left, int right, char target[]) {
    if (left > right) return -1;  // ไม่พบค่า

    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (strcmp(flights[mid1].call_sign, target) == 0) return mid1;
    if (strcmp(flights[mid2].call_sign, target) == 0) return mid2;

    if (strcmp(target, flights[mid1].call_sign) < 0) {
        return ternary_search(flights, left, mid1 - 1, target);
    } else if (strcmp(target, flights[mid2].call_sign) > 0) {
        return ternary_search(flights, mid2 + 1, right, target);
    } else {
        return ternary_search(flights, mid1 + 1, mid2 - 1, target);
    }
}
// 673380166-0
// ฟังก์ชันค้นหาเที่ยวบินที่ออกเวลา 04:00:00 - 06:00:00
void find_flights_in_time_range(Flight flights[], int size) {
    printf("เที่ยวบินที่ออกระหว่าง 04:00:00 - 06:00:00:\n");
    for (int i = 0; i < size; i++) {
        char hour[3] = {flights[i].timestamp[8], flights[i].timestamp[9], '\0'};
        int flight_hour = atoi(hour);

        if (flight_hour >= 4 && flight_hour < 6) {
            printf("เที่ยวบิน %s ออกเวลา %s\n", flights[i].call_sign, flights[i].timestamp + 8);
        }
    }
}

int main() {
    // ข้อมูลเที่ยวบินจากตาราง (ต้องเรียงลำดับตาม Call Sign)
    Flight flights[SIZE] = {
        {1, "CZ 5027", "20221004000000"},
        {2, "EK 376",  "20221004060400"},
        {3, "EK 9889", "20221004000800"},
        {4, "PG 132",  "2022100405733"},
        {5, "PG 272",  "20221004043744"},
        {6, "UL 402",  "20221004022030"},
        {7, "WE 021",  "20221004024313"},
        {8, "WE 021",  "20221004032308"}
    };
// 673380166-0
    char target[] = "WE 021";

    // ค้นหา "WE 021" อยู่ลำดับที่เท่าไร
    int index = ternary_search(flights, 0, SIZE - 1, target);
    if (index != -1)
        printf("เที่ยวบิน %s อยู่ในลำดับที่ %d\n", target, index + 1);
    else
        printf("ไม่พบเที่ยวบิน %s\n", target);

    // ค้นหาเวลาออกของ "WE 021"
    if (index != -1)
        printf("เที่ยวบิน %s ออกเวลา %s\n", target, flights[index].timestamp + 8);

    // ค้นหาเที่ยวบินที่ออกระหว่าง 04:00:00 - 06:00:00
    find_flights_in_time_range(flights, SIZE);

    return 0;
}

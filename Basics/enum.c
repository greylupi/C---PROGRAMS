//
// Created by Martin on 2025-04-24.
//

#include <stdio.h>

int main() {
    enum Weekdays {
        Monday,         // 0
        Tuesday,        // 1
        Wednesday,      // 2
        Thursday,       // 3
        Friday,         // 4
        Saturday,       // 5
        Sunday          // 6
      };

    // Defining a "Weekdays" enum variable
    enum Weekdays EnumName = Friday;       // 4

    // Check the value of "EnumName"
    switch (EnumName){
        case Monday:
            printf("Today Is Monday !\n");
            break;
        case Tuesday:
            printf("Today Is Tuesday !\n");
            break;
        case Wednesday:
            printf("Today Is Wednesday !\n");
            break;
        case Thursday:
            printf("Today Is Thursday !\n");
            break;
        case Friday:
            printf("Today Is Friday !\n");
            break;
        case Saturday:
            printf("Today Is Saturday !\n");
            break;
        case Sunday:
            printf("Today Is Sunday !\n");
            break;
        default:
            break;
    }

}
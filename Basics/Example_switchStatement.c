//simple switch statement for reference.

#include <stdio.h>

int main(void) {
  int month, day, year;

  // Standard date form
  printf("Enter date (mm/dd/yyyy): ");
  scanf("%d /%d /%d", &month, &day, &year);

  // Print the month
  switch (month){
    case 1:
      printf("January ");
      break;
    case 2:
      printf("February ");
      break;
    case 3:
      printf("March ");
      break;
    case 4:
      printf("April ");
      break;
    case 5:
      printf("May ");
      break;
    case 6:
      printf("June ");
      break;
    case 7:
      printf("July ");
      break;
    case 8:
      printf("August ");
      break;
    case 9:
      printf("September ");
      break;
    case 10:
      printf("October ");
      break;
    case 11:
      printf("November ");
      break;
    case 12:
      printf("December ");
      break;
  }

  // Print the day
  //if (day > 0 && day <= 31) {
    //printf(" %i", day);
  //} else {
    //printf("Day inputed is invalid. Please try again.");
    //return -1;
  //};
  switch (day) {
    case 1: case 21: case 31:
      printf("%ist", day);
      break;
    case 2: case 22:
      printf("%ind", day);
      break;
    case 3: case 23:
      printf("%ird", day);
      break;
    default:
      printf("%ith", day);
      break;
  }
  // Print the year
  printf(", %i\n", year);
  
  return 0;
}

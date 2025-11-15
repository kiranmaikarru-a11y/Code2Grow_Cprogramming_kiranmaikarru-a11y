
#include <stdio.h>
int main() {
    int attendance[5][5],m;
    int marks[5][5];
    char names[5][20];
    int i, j, choice;
    int totalAttendance[5] = {0};
    int totalAbsence[5] = {0};
    int totalMarks[5] = {0};
    float avgMarks[5];
    printf("Enter names of 5 students:\n");
    for(i = 0; i < 5; i++) {
        printf("Student %d name: ", i+1);
        scanf("%s", names[i]);
    }
    printf("\nEnter Attendance Matrix (1 = Present, 0 = Absent)\n");
    for(i = 0; i < 5; i++) {
    printf("Attendance for %s:\n", names[i]);
    for(j = 0; j < 5; j++) {
    printf("  Class %d: ", j+1);
    scanf("%d", &attendance[i][j]);
    }}
    printf("\nEnter Marks Matrix (Marks out of 100)\n");
    for(i = 0; i < 5; i++) {
    printf("Marks for %s:\n", names[i]);
    for(j = 0; j < 5; j++) {
    printf("  Subject %d: ", j+1);
    scanf("%d", &marks[i][j]);
    }}
    for(i = 0; i < 5; i++) {
    for(j = 0; j < 5; j++) { 
 totalAttendance[i] += attendance[i][j];
   totalMarks[i] += marks[i][j];
  }
  totalAbsence[i] = 5 - totalAttendance[i];
  avgMarks[i] = totalMarks[i] / 5.0;
    }
    int highA = 0, lowA = 0;
    for(i = 1; i < 5; i++) {
   if(totalAttendance[i] > totalAttendance[highA]) highA = i;
   if(totalAttendance[i] < totalAttendance[lowA]) lowA = i;
    }
    int topper = 0, lowPerf = 0;
    for(i = 1; i < 5; i++) {
   if(totalMarks[i] > totalMarks[topper]) topper = i;
   if(totalMarks[i] < totalMarks[lowPerf]) lowPerf = i;
    }
    do {
printf("\n========== MENU ==========\n");
printf("1. Display Attendance Matrix\n");
printf("2. Display Marks Matrix\n");
printf("3. Attendance Report\n");
 printf("4. Performance Report\n");
 printf("5. Grade Report\n");
 printf("6. Exit\n");
 printf("==========================\n");
 printf("Enter your choice: ");
scanf("%d", &choice);
 switch(choice) {
 case 1:
 printf("\n--- Attendance Matrix ---\n");
 for(i = 0; i < 5; i++) {
  printf("%s: ", names[i]);
 for(j = 0; j < 5; j++) {
 printf("%d ", attendance[i][j]);
 }
 printf("\n") }
 break;
 case 2:
 printf("\n--- Marks Matrix ---\n");
  for(i = 0; i < 5; i++) {
  printf("%s: ", names[i]);
  for(j = 0; j < 5; j++) {
  printf("%d ", marks[i][j]);
     }
      printf("\n");
      }
      break;
      case 3:
     printf("\n--- Attendance Report ---\n");
     for(i = 0; i < 5; i++) {
     printf("%s -> Present: %d, Absent: %d\n",
    names[i], totalAttendance[i], totalAbsence[i]);
    }
    printf("Highest Attendance : %s\n", names[highA]);
    printf("Lowest Attendance  : %s\n", names[lowA]);
    break; 
case 4:
    printf("\n--- Performance Report ---\n");
    for(i = 0; i < 5; i++) {
    printf("%s -> Total Marks: %d, Average: %.2f\n",
    names[i], totalMarks[i], avgMarks[i]);
     }
     printf("Class Topper        : %s\n", names[topper]);
     printf("Lowest Performer    : %s\n", names[lowPerf]);
     break;
      case 5:  
      printf("\n--- Grade Report ---\n");
       for(i = 0; i < 5; i++) {
        char grade[3];
       if(avgMarks[i] >= 90)
       sprintf(grade, "A+");
      else if(avgMarks[i] >= 80)
      sprintf(grade, "A");
     else if(avgMarks[i] >= 70)
     sprintf(grade, "B");
     else if(avgMarks[i] >= 60)
     sprintf(grade, "C");
     else if(avgMarks[i] >= 50)
    sprintf(grade, "D");
    else
  sprintf(grade, "F");
   printf("%s -> Average: %.2f, Grade: %s\n",
   names[i], avgMarks[i], grade);
   }
   break;
  case 6:
   printf("\nExiting program...\n");
   break;
   default:
    printf("Invalid choice! Try again.\n");
   }}
  while(choice != 6);
   return 0;
}  

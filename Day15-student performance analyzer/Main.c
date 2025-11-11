#include <stdio.h>
int main() {
    int totalStudents, score[10], i, maxMarkminMark, passCount = 0, failCount = 0;
    float total = 0, average;
    int cntAplus = 0, cntA = 0, cntB = 0, cntC = 0, cntD = 0;
    printf("====== Student Performance Analyzer ======\n");
    printf("Enter total number of students: ");
    scanf("%d", &totalStudents);
    printf("Enter marks for each student:\n");
    for (i = 0; i < totalStudents; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &score[i]);
        total += score[i];
    }
    maxMark = score[0];
    minMark = score[0];

    for (i = 0; i < totalStudents; i++) {
        if (score[i] > maxMark)
            maxMark = score[i];
        if (score[i] < minMark)
            minMark = score[i];
        if (score[i] >= 90)
            cntAplus++;
        else if (score[i] >= 80)
            cntA++;
        else if (score[i] >= 70)
            cntB++;
        else if (score[i] >= 60)
            cntC++;
else if (score[i] >= 50)
            cntD++;
        else
            failCount++;
    }
    passCount = totalStudents - failCount;
    average = total / totalStudents;
    printf("\n====== Result Summary ======\n");
    printf("Average Marks : %.2f\n", average);
    printf("Highest Marks : %d\n", maxMark);
    printf("Lowest Marks  : %d\n", minMark);
    printf("\nPassed Students : %d\n", passCount);
    printf("Failed Students : %d\n", failCount);
    printf("\nGrade Distribution:\n");
    printf("A+ : %d\n", cntAplus);
    printf("A  : %d\n", cntA);
    printf("B  : %d\n", cntB);
    printf("C  : %d\n", cntC);
    printf("D  : %d\n", cntD);
    printf("Fail : %d\n", failCount);
    printf("==============================\n");
    return 0;
}
       

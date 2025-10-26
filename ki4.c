#include<stdio.h> 

int main() {
    float s1, s2, s3, s4, s5, p, a;
    printf("enter five sub marks:");
    scanf("%f%f%f%f%f", &s1, &s2, &s3, &s4, &s5);

    p = ((s1 + s2 + s3 + s4 + s5) / 500) * 100;
    printf("percentage: %f\n", p);

    printf("enter the attendance percentage:");
    scanf("%f", &a);  // corrected from %d to %f since a is float

    if (a >= 90) {
        if (p < 50 && p >= 45)
            p = p + (5.0 / 500) * 100;  // use float division
    }

    if (a > 75) {
        if (p > 90) {
            printf("total percentage: %f\n", p);
            printf("attendance: %f\n", a);
            printf("final grade: A+\n");
            printf("remarks: excellent\n");
        }
        else if (p < 90 && p >= 80) {
            printf("total percentage: %f\n", p);
            printf("attendance: %f\n", a);
            printf("final grade: A\n");
            printf("remarks: very good\n");
        }
        else if (p < 80 && p >= 70) {   // fixed condition (was <70 && >=79)
            printf("total percentage: %f\n", p);
            printf("attendance: %f\n", a);
            printf("final grade: B\n");
            printf("remarks: good\n");
        }
        else if (p < 70 && p >= 60) {   // fixed condition (was <60 && >=69)
            printf("total percentage: %f\n", p);
            printf("attendance: %f\n", a);
            printf("final grade: C\n");
            printf("remarks: average\n");
        }
        else if (p < 60 && p >= 50) {   // fixed condition (was <50 && >=59)
            printf("total percentage: %f\n", p);
            printf("attendance: %f\n", a);
            printf("final grade: D\n");
            printf("remarks: pass\n");
        }
        else {
            printf("total percentage: %f\n", p);
            printf("attendance: %f\n", a);
            printf("final grade: F\n");
            printf("remarks: fail\n");
        }
    }

    return 0;
}

#include <stdio.h>

int main() {
    float percentage;

    
    printf("Enter the percentage obtained by the student: ");
    scanf("%f", &percentage);

    
    if (percentage >= 0 && percentage < 40) {
        printf("Class: Fail\n");
    } else if (percentage >= 40 && percentage < 60) {
        printf("Class: Second class\n");
    } else if (percentage >= 60 && percentage < 80) {
        printf("Class: First class\n");
    } else if (percentage >= 80 && percentage <= 100) {
        printf("Class: Distinction\n");
    } else {
        printf("Invalid percentage! Please enter a value between 0 and 100.\n");
    }

    return 0;
}
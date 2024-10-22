#include <stdio.h>
#include <string.h>

struct Student {
    int id;               
    char name[50];        
    float marks[3];       
    float totalMarks;     
    float percentage;    
    char division[20];
};

void calculateResults(struct Student* student) {
    student->totalMarks = student->marks[0] + student->marks[1] + student->marks[2];

    student->percentage = (student->totalMarks / 300) * 100;

    if (student->percentage >= 60) {
        strcpy(student->division, "First Class");
    } else if (student->percentage >= 50) {
        strcpy(student->division, "Second Class");
    } else if (student->percentage >= 40) {
        strcpy(student->division, "Third Class");
    } else {
        strcpy(student->division, "Fail");
    }
}

void displayMarksheet(struct Student student) {
    printf("\n---- Marksheet ----\n");
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Marks in Subject 1: %.2f\n", student.marks[0]);
    printf("Marks in Subject 2: %.2f\n", student.marks[1]);
    printf("Marks in Subject 3: %.2f\n", student.marks[2]);
    printf("Total Marks: %.2f / 300\n", student.totalMarks);
    printf("Percentage: %.2f%%\n", student.percentage);
    printf("Division: %s\n", student.division);
    printf("-------------------\n");
}

int main() {
    int n, i;
    struct Student students[15];
    printf("Enter the number of students: ");
    scanf("%d", &n);

 

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Enter student ID: ");
        scanf("%d", &students[i].id);

        printf("Enter student name: ");
        scanf(" %[^\n]%*c", students[i].name);

        printf("Enter marks for Subject 1: ");
        scanf("%f", &students[i].marks[0]);

        printf("Enter marks for Subject 2: ");
        scanf("%f", &students[i].marks[1]);

        printf("Enter marks for Subject 3: ");
        scanf("%f", &students[i].marks[2]);

        calculateResults(&students[i]);
    }

    for (i = 0; i < n; i++) {
        displayMarksheet(students[i]);
    }

    return 0;
}

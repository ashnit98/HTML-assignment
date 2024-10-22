#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char address[100];
    char phone[15];
};

// Function prototypes
void addRecord(FILE *fp);
void deleteRecord(FILE *fp);
void modifyRecord(FILE *fp);
void retrieveRecord(FILE *fp);
void listRecords(FILE *fp);

int main() {
    FILE *fp;
    int choice;
    char filename[] = "employee.dat";

    fp = fopen(filename, "rb+");
    if (fp == NULL) {
        fp = fopen(filename, "wb+");
        if (fp == NULL) {
            printf("Cannot open file.\n");
            exit(1);
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Add a new record\n");
        printf("2. Delete a record\n");
        printf("3. Modify an existing record\n");
        printf("4. Retrieve and display an entire record for a given ID/Name\n");
        printf("5. Generate a complete list of all employee names, addresses, and telephone numbers\n");
        printf("6. End of computation/Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(fp);
                break;
            case 2:
                deleteRecord(fp);
                break;
            case 3:
                modifyRecord(fp);
                break;
            case 4:
                retrieveRecord(fp);
                break;
            case 5:
                listRecords(fp);
                break;
            case 6:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    fclose(fp);
    return 0;
}

// Function to add a new record
void addRecord(FILE *fp) {
    struct Employee e;
    fseek(fp, 0, SEEK_END);
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]%*c", e.name);
    printf("Enter Employee Address: ");
    scanf(" %[^\n]%*c", e.address);
    printf("Enter Employee Phone: ");
    scanf(" %[^\n]%*c", e.phone);
    fwrite(&e, sizeof(struct Employee), 1, fp);
    printf("Record added successfully.\n");
}

// Function to delete a record
void deleteRecord(FILE *fp) {
    FILE *temp;
    struct Employee e;
    int id, found = 0;
    char filename[] = "employee.dat";

    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Cannot open temporary file.\n");
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    rewind(fp);

    while (fread(&e, sizeof(struct Employee), 1, fp)) {
        if (e.id != id) {
            fwrite(&e, sizeof(struct Employee), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove(filename);
    rename("temp.dat", filename);

    fp = fopen(filename, "rb+");
    if (found)
        printf("Record deleted successfully.\n");
    else
        printf("Record not found.\n");
}

// Function to modify an existing record
void modifyRecord(FILE *fp) {
    struct Employee e;
    int id, found = 0;
    printf("Enter Employee ID to modify: ");
    scanf("%d", &id);
    rewind(fp);

    while (fread(&e, sizeof(struct Employee), 1, fp)) {
        if (e.id == id) {
            printf("Enter new Employee Name: ");
            scanf(" %[^\n]%*c", e.name);
            printf("Enter new Employee Address: ");
            scanf(" %[^\n]%*c", e.address);
            printf("Enter new Employee Phone: ");
            scanf(" %[^\n]%*c", e.phone);
            fseek(fp, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&e, sizeof(struct Employee), 1, fp);
            found = 1;
            break;
        }
    }

    if (found)
        printf("Record modified successfully.\n");
    else
        printf("Record not found.\n");
}

// Function to retrieve and display an entire record for a given ID/Name
void retrieveRecord(FILE *fp) {
    struct Employee e;
    int id, choice, found = 0;
    char name[50];

    printf("Retrieve by:\n1. ID\n2. Name\nEnter your choice: ");
    scanf("%d", &choice);
    rewind(fp);

    if (choice == 1) {
        printf("Enter Employee ID: ");
        scanf("%d", &id);

        while (fread(&e, sizeof(struct Employee), 1, fp)) {
            if (e.id == id) {
                printf("\nEmployee ID: %d\n", e.id);
                printf("Employee Name: %s\n", e.name);
                printf("Employee Address: %s\n", e.address);
                printf("Employee Phone: %s\n", e.phone);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter Employee Name: ");
        scanf(" %[^\n]%*c", name);

        while (fread(&e, sizeof(struct Employee), 1, fp)) {
            if (strcmp(e.name, name) == 0) {
                printf("\nEmployee ID: %d\n", e.id);
                printf("Employee Name: %s\n", e.name);
                printf("Employee Address: %s\n", e.address);
                printf("Employee Phone: %s\n", e.phone);
                found = 1;
                break;
            }
        }
    } else {
        printf("Invalid choice.\n");
        return;
    }

    if (!found)
        printf("Record not found.\n");
}

// Function to generate a complete list of all employee names, addresses, and telephone numbers
void listRecords(FILE *fp) {
    struct Employee e;
    rewind(fp);

    printf("\nComplete list of employees:\n");
    while (fread(&e, sizeof(struct Employee), 1, fp)) {
        printf("\nEmployee ID: %d\n", e.id);
        printf("Employee Name: %s\n", e.name);
        printf("Employee Address: %s\n", e.address);
        printf("Employee Phone: %s\n", e.phone);
    }
}

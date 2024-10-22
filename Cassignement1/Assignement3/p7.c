#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cust {
    char name[20];
    char phoneno[15];
};

void searchcustomer(FILE *fp1) {
    struct cust c;
    char name[20];
    printf("Enter customer name: ");
    scanf("%s", name);
    rewind(fp1); // Reset file pointer to the start
    while (fread(&c, sizeof(c), 1, fp1)) {
        if (strcmp(c.name, name) == 0) {
            printf("Customer telephone is %s\n", c.phoneno);
            return;
        }
    }
    printf("Customer not found\n");
}

void searchtelephone(FILE *fp1) {
    struct cust c;
    char phone[15];
    printf("Enter phone number: ");
    scanf("%s", phone);
    rewind(fp1); // Reset file pointer to the start
    while (fread(&c, sizeof(c), 1, fp1)) {
        if (strcmp(c.phoneno, phone) == 0) {
            printf("Customer Name is %s\n", c.name);
            return;
        }
    }
    printf("Phone number not found\n");
}

void addrecord(FILE *fp1) {
    struct cust c;
    printf("\nEnter customer name: ");
    scanf("%s", c.name);
    printf("\nEnter customer phone number: ");
    scanf("%s", c.phoneno);
    fseek(fp1, 0, SEEK_END); // Move to end of file before adding new record
    fwrite(&c, sizeof(c), 1, fp1);
    printf("\nRecord added successfully\n");
}

void deleterecord(FILE *fp1, char *fn) {
    FILE *temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        printf("Cannot open temporary file\n");
        return;
    }

    struct cust c;
    char name[20];
    int found = 0;
    printf("\nEnter customer name to delete: ");
    scanf("%s", name);
    rewind(fp1);

    while (fread(&c, sizeof(c), 1, fp1)) {
        if (strcmp(c.name, name) != 0) {
            fwrite(&c, sizeof(c), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp1);
    fclose(temp);
    remove(fn);
    rename("temp.bin", fn);

    fp1 = fopen(fn, "rb+");
    if (fp1 == NULL) {
        printf("Error reopening the file\n");
        return;
    }

    if (found) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record not found.\n");
    }
}

void listcustomer(FILE *fp1) {
    struct cust c;
    rewind(fp1); // Reset file pointer to the start
    printf("Customer List:\n");
    while (fread(&c, sizeof(c), 1, fp1)) {
        printf("Name: %s, Phone: %s\n", c.name, c.phoneno);
    }
}

int main() {
    FILE *fp1;
    char fn[] = "cust.bin";
    fp1 = fopen(fn, "rb+");
    if (fp1 == NULL) {
        fp1 = fopen(fn, "wb+");
        if (fp1 == NULL) {
            printf("Cannot open file\n");
            exit(1);
        }
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Determine the telephone number of a specific customer\n");
        printf("2. Determine the customer whose telephone number is specified\n");
        printf("3. Add a new record\n");
        printf("4. Delete a record\n");
        printf("5. List all customers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                searchcustomer(fp1);
                break;
            case 2:
                searchtelephone(fp1);
                break;
            case 3:
                addrecord(fp1);
                break;
            case 4:
                deleterecord(fp1, fn);
                break;
            case 5:
                listcustomer(fp1);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    fclose(fp1);
    return 0;
}

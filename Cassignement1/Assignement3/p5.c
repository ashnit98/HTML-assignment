#include <stdio.h>
#include <stdlib.h>

void copyAndCountLines(const char *sourceFile, const char *destFile) {
    FILE *source, *dest;
    int ch, lineCount = 0;

    // Open the source file in read mode
    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Cannot open source file: %s\n", sourceFile);
        exit(1);
    }

    // Open the destination file in write mode
    dest = fopen(destFile, "w");
    if (dest == NULL) {
        printf("Cannot open destination file: %s\n", destFile);
        fclose(source);
        exit(1);
    }

    // Copy contents from source to destination and count lines
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
        if (ch == '\n') {
            lineCount++;
        }
    }

    // Close both files
    fclose(source);
    fclose(dest);

    // Print the number of lines in the source file
    printf("Number of lines in the source file: %d\n", lineCount);
}

int main() {
    char sourceFile[100], destFile[100];

    // Get the source file name from the user
    printf("Enter the source file name: ");
    scanf("%s", sourceFile);

    // Get the destination file name from the user
    printf("Enter the destination file name: ");
    scanf("%s", destFile);

    // Call the function to copy contents and count lines
    copyAndCountLines(sourceFile, destFile);

    return 0;
}

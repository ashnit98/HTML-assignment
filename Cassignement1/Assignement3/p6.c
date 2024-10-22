#include <stdio.h>
#include <stdlib.h>

void rc(const char *f) {
    FILE *f1;
    int nlines = 0, nc = 0, nw = 0, ns = 0;
    f1 = fopen(f, "r");
    if (f1 == NULL) {
        printf("Cannot read file: %s\n", f);
        exit(0);
    }

    int ch, prev_ch = EOF;
    while ((ch = getc(f1)) != EOF) {
        nc++; // Count characters
        if (ch == ' ') {
            ns++; // Count spaces
            if (prev_ch != ' ' && prev_ch != '\n' && prev_ch != '\t' && prev_ch != EOF) {
                nw++; // Count words
            }
        } else if (ch == '\n') {
            nlines++; // Count newlines
            if (prev_ch != ' ' && prev_ch != '\n' && prev_ch != '\t' && prev_ch != EOF) {
                nw++; // Count words
            }
        } else if (ch == '\t') {
            ns++; // Count tabs as spaces
            if (prev_ch != ' ' && prev_ch != '\n' && prev_ch != '\t' && prev_ch != EOF) {
                nw++; // Count words
            }
        }
        prev_ch = ch;
    }

    // Account for the last word if the file doesn't end with a space/newline/tab
    if (prev_ch != ' ' && prev_ch != '\n' && prev_ch != '\t' && prev_ch != EOF) {
        nw++;
    }

    fclose(f1);

    printf("\nNo of lines: %d", nlines);
    printf("\nNo of characters: %d", nc);
    printf("\nNo of spaces: %d", ns);
    printf("\nNo of words: %d", nw);
}

int main() {
    char f[60];
    printf("Enter filename: ");
    scanf("%59s", f); // Use scanf for safer input instead of gets
    rc(f);
    return 0;
}

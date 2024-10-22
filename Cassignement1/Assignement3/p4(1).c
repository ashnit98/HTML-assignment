#include <stdio.h>

struct Time {
    int h;
    int m;
    int sec;
};

void addSeconds(struct Time* t, int seconds) {
    t->sec += seconds;
    t->m += t->sec / 60;
    t->sec = t->sec % 60;
    t->h += t->m / 60;
    t->m = t->m % 60;
    t->h = t->h % 24; // To wrap around after 24 hours
}

void displayTime(struct Time t) {
    printf("Time: %02d:%02d:%02d\n", t.h, t.m, t.sec);
}

int main() {
    struct Time t;
    int seconds;

    printf("Enter time in format HH MM SS: ");
    scanf("%d %d %d", &t.h, &t.m, &t.sec);

    printf("Enter seconds to add: ");
    scanf("%d", &seconds);

    addSeconds(&t, seconds);

    printf("New ");
    displayTime(t);

    return 0;
}

#include <stdio.h>

int main() {
    char meldung[] = "Hello";
//    char meldung [6] = {72, 101, 108, 108, 111, 0};
//    char meldung [] = {72, 101, 108, 108, 111, 0};
//      char meldung [] = {'H', 'e', 'l', 'l', 'o', '\0'};
      int i;

    i=0;
    while(meldung[i] != '\0') {
        printf("%c - %3d\n", meldung[i], meldung[i]);
        i++;
    }
    printf("\n");

    return 0;
}


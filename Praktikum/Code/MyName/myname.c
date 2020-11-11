#include <stdio.h>

int main (){
  int day = 30;
  int month=05; 
  int year = 2002;
  char name[] = "Daniel Walther";

  printf("Mein Name ist %s\n", name);
  printf("Mein Geburtsdatum ist der %02d.%02d.%04d\n", day, month, year);
  return 0;
}

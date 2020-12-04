#include <stdio.h>
#include <stdlib.h>

int main(int argc, char argv[]){
  int z; 
  printf("Höhe eingeben: ");
  z = atoi(argv[1]);
 
  return 0;
  

}


int pascal(int z, int s){  //Eingabe von Zeile und Spalte
 if( z >= 0&&s >= 0){ // wenn z und s >= 0 
 return  (z/((z-s)*s))*pascal(z-1 , s-1);}
 else {return pascal(z-1 , s-1);}
}

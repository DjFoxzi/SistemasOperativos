#include <stdio.h>

int a;

int suma(int x, int y){
int z;
x= x + y;
z= x;
return z;
}
int main (int argc,char** argv) {
int x1, y1;
x1 = 4;
y1 = 5;
printf("Suma: %d\n",suma(4,5));
//printf("A: %d\n",a);
return 0;
}

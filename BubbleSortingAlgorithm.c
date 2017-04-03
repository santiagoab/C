
#include <stdio.h>
#include <stdlib.h>

void bubble(int **v, int n);
void intercanviar (int **x, int **y);

int main()
{

   int n;
   int i;
   int **a;

   printf("How many numbers do you wish to order:\n");
   scanf("%d", &i);

   a = (int **)malloc(sizeof(int *) * i);  //We save memory for the dynamic array.
   for(n = 0; n < i; n++){
       a[n] = (int *)malloc(sizeof(int));
   }

   for(n = 0; n < i; n++){                                    //We insert the numbers.
     printf("Write the number for the position %d:\n", n+1);
     scanf("%d", a[n]);
   }

   bubble(a, i);  //We call the Bubble sorting algorithm which orders the values into the pointers.

   printf("The values in order are:\n");  //We print the ordered values and its position.
   for(n = 0; n < i; n++){
        printf("Value %d: %d\n", n, *a[n]);
   }

   for(n = 0; n < i; n++){     //We free the memory previously used.
       free(a[n]);
   }
   free(a);

}


void bubble(int **v, int n){               //Bubble sorting algorithm adapted to order the values into the pointers.
       int x, y;
       for (x = 0; x < n - 1; x++){
           for(y = n - 1; y > x; y--){
                if (*(v[y]) < *(v[y - 1])){
                    intercanviar( &(v[y]), &(v[y-1]));
                }
       }
   }
}



void intercanviar (int **x, int **y){    //Function to interchange the postion to which two pointers point.
    int *aux;
    aux = *x;
    *x = *y;
    *y = aux;
}





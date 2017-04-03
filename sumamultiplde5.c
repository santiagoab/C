#include <stdio.h>

main()                  // Funció principal.
{
int suma=0, a, b, x, y, i; // Declarem les variables que utilitzarem.
printf("Calcularem la suma dels multiples de 5 compresos entre dos enters positius.\n"); // Expliquem a l'usuari el que farem al programa.
printf("Escrigui l'interval.\n"); // Demanem a l'usuari que escrigui l'interval on es trobaran els multiples que sumarem.
printf("Inici de l'interval: ");  // L'usuari escriu l'inici de l'interval.
scanf("%d",&a);   // El programa llegeix el que insereix l'usuari i ho pren com a variable a.
printf("Final de l'interval: "); // L'usuari escriu en final de l'interval.
scanf("%d",&b);   // El programa llegeix el que insereix l'usuari i ho pren com a variable b.

if(a>b);     //Verifiquem que els valors de l'interval s'introdueixen el l'ordre correcte i que l'inici de l'interval es menor que el final.
{
  x = b;
  y = a;

}
if (a<=b)    // Si la condició anterior no es compleix, és a dir, l'inici de l'interval és menor que el final
{            // els valors d'inici i de final del interval canvien entre si.
x = a;
y = b;
}

for (i=x; i<=y; i++)  //Determinem que entre l'inici i el final de l'interval donat, anirem agafant tots els valors.
{
    if(i%5==0)               // Per a tots els valors dins de l'interval que dividits entre 5 el seu residu sigui 0,
		suma = suma+i;       // és a dir, tots els múltiples de 5, es sumin al valor suma, el qual val 0.
}
	printf ("La suma total dels multiples de 5 val: %d", suma);    // Mostrem a l'usuari el valor final de la suma de tots els múltiples de 5.

}





#include <stdio.h>
#define N 6
#define M 50

//Gabriel Arroyo Hinojosa 
//Santiago Alarcos 

//Funciones

//Muestra un titulo con "adornos"
void titulo(char tabla[][M], int p);
//Imprime la matriz que se indique en la pantalla
void vertabla(int tabla[][M], int p);
//Muestra las estadísticas requeridas para la práctica
void stats(int tabla[][M], int p);
//Muestra una bola caer y muestra el numero de pasos que hace hasta llegar al final de la tabla
void bola(int tabla[][M], int p);
//Muestra 10 bolas cayendo y muestra el numero de veces que se ha pasado por la casilla.
void bolas10(int tabla[][M], int p);
/*Esta función se encarga de devolver la tabla a los valores dados inicialmente
después de que se hayan modificado en alguno de los procesos anteriores, de esta forma
conseguimos evitar errores.*/
void tablainicial(int tabla[][M], int p);
//Función que encuentra el valor mayor entre dos enteros dados
int mayor (int a, int b);

main()
{
//Variable que guardará la opción que introduzca el usuario
int selec = 0;
//Matrices que se usarán durante el programa. Una es un título y la otra la tabla a usar
char decor[N][M] = {
{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','P','I','N','B','A','L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
};
int tabla[M][M]= {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

//While que mantiene el selector de opciones mientras no se abandone el programa
while (selec != 5)
{
titulo(decor, N);    //Muestra el titulo incial decorado con asteriscos
printf("Bienvenido\n");   //Se muestra el menú con sus opciones en la pantalla entre las que debemos elegir una
    printf("1 - Visualizar el contenido de la tabla de obstaculos por pantalla\n");
    printf("2 - Visualizar estadisticas acerca de la tabla\n");
    printf("3 - Simular la caida de una pelota.\n");
    printf("4 - Simular la caida de 10 pelotas.\n");
    printf("5 - Salir del programa.\n");
    printf("Inserta el numero de la opcion que quieras escoger: ");
       scanf("%d", &selec);
    printf("\n");

/*El switch comprobará el valor de la variable select y escogerá la función deseada.
el printf dentro de cada caso sirve para dar una separación respecto el output de la función siguiente y el resto de datos.*/
switch(selec)
  {
  case 1:
      {
      vertabla(tabla, M);
      printf("\n");
      break;
      }
  case 2:
      {
      stats(tabla, M);
      tablainicial(tabla, M);
      printf("\n");
      break;
      }
  case 3:
      {
      bola(tabla, M);
      tablainicial(tabla, M);
      printf("\n");
      break;
      }
  case 4:
      {
      bolas10(tabla, M);
      tablainicial(tabla, M);
      printf("\n");
      break;
      }
  default:
      {
      break;
      }
  }
}
}

/*Esta función imprime una tabla de carácteres con tantas filas como indique p y M columnas
 Se utilitzará para imprimir el título del programa*/

void titulo(char tabla[][M], int p)
{
int n, z;
for (n = 0; n < p; n++)
   {
   for (z = 0; z < M; z++)
      {
	  printf("%c", tabla[n][z]);
      }
	  printf("\n");
   }
}

//Esta función imprime cualquier tabla numérica dada con 50 columnas y tantas filas como indique p
void vertabla(int tabla[][50], int p)
{
int n, z;

for(n = 0; n < p; n++)
{
   for(z = 0; z < M; z++)
   {
      if (tabla[n][z] == 1)
      {
         printf("*");
      }
      else
      {
         printf(".");
      }
   }
printf("\n");
}
}

//Estadísticas del juego
void stats(int tabla[][M], int p)
{
int n, z, g, j;

//Guardan la longitud de la linea
int longver, longhor, longdiaai, longdiaad;

/*Matrices que guardarán la longitud de  las lineas existentes. Damos el valor de 10 a los arrays ya que
en nuestro juego será suficiente para almacenar la cantidad de lineas que tengamos de cada tipo.*/

int verticales [10]= {0,0,0,0,0,0,0,0,0,0};
int horizontales [10]= {0,0,0,0,0,0,0,0,0,0};
int diagonalaiAds [10]= {0,0,0,0,0,0,0,0,0,0};
int diagonaladAis [10]= {0,0,0,0,0,0,0,0,0,0};

//En cada celda se guardará la información de las estadisticas para mostrarla por pantalla.
int estadisticas [10]= {0,0,0,0,0,0,0,0,0,0};

for(n = 0; n < p; n++)
{
   for(z = 0; z < M; z++)
   {
      //Linea Vertical: Condicion que empieza a contar el número de líneas verticales.
      if(tabla[n][z] != 0 && tabla[n+1][z] != 0 && tabla[n][z]%3 != 0)
      {
       if(n+1 == p)
         {
            break;
         }
       else
         {
            g = n;
            longver = 0; //Contamos la longitud de la linea vetical.
            for(g; g < M; g++)
            {
             if(tabla[g][z] != 0)
               {
                 tabla[g][z] = tabla[g][z]*3;
                 longver++;
               }
            else
               {
                tabla[g][z] = 0;
                break;
              }
             }
             verticales [estadisticas[0]] = longver; //Guarda el valor en la matriz vertical
             estadisticas[0]++; /*Cada vez que se cuente una linea vertical
                                 se sumará uno al espacio de estadisticas 0
                                 que guarda el numero de lineas verticales*/
         }
       }

       //Linea horizontal: Condición que empieza a contar el número de líneas horizontales.
       if(tabla[n][z] != 0 && tabla[n][z+1] != 0 && tabla[n][z]%5 != 0)
       {
        if(z+1 == 50)
        {
          break;
        }
        else
        {
           j = z;
           longhor = 0; //Contamos la longitud de la linea horizontal.
           for(j; j < M; j++)
           {
              if(tabla[n][j] != 0)
              {
                longhor++;
                tabla[n][j] = tabla[n][j]*5;
              }
              else
              {
                tabla[n][j] = 0;
                break;
              }
           }
           horizontales [estadisticas[1]] = longhor; //guarda el valor en la matriz horizontal
           estadisticas[1]++; //cuenta la linea vertical y añade 1 al espacio de estadisticas 1
        }
       }

       //Diagonal abajo izquierda arriba derecha:  Condición que empieza a contar el número de líneas diagonales abajo izquierda arriba derecha.
       if(tabla[n][z] != 0 && tabla[n+1][z-1] != 0 && tabla[n][z]%7 != 0)
       {
        if(n+1 == p || z-1 == 50)
        {
          break;
        }
        else
        {
           g = n;
           j = z;
           longdiaai = 0; //Contamos la longitud de la diagonal abajo izquierda arriba derecha.
           for(g; g < M; g++)
           {
               if(tabla[g][j] != 0)
                 {
                   tabla[g][j] = tabla[g][j]*7;
                   longdiaai++;
                   j = j-1;
                 }
               else
                 {
                   tabla[g][j] = 0;
                   break;
                 }
           }
           diagonalaiAds [estadisticas[2]] = longdiaai; //guarda el valor en la matriz diagonalaiAd
           estadisticas[2]++; //cuenta la linea diagonal y añade 1 al espacio de estadisticas 2
        }
       }

       //Diagonal abajo derecha arriba izquierda:  Condición que empieza a contar el número de líneas diagonales abajo derecha arriba izquierda.
       if(tabla[n][z] != 0 && tabla[n+1][z+1] != 0 && tabla[n][z]%11 != 0)
       {
        if(n+1 == p || z+1 == 50)
        {
          break;
        }
        else
        {
           g = n;
           j = z;
           longdiaad = 0; //Contamos la longitud de la linea diagonal abajo derecha arriba izquierda.
           for(g; g < M; g++)
           {
               if(tabla[g][j] != 0)
                 {
                   longdiaad++;
                   tabla[g][j] = tabla[g][j]*11;
                   j = j+1;
                 }
               else
                 {
                   tabla[g][j] = 0;
                   break;
                 }
           }
           diagonaladAis [estadisticas[3]] = longdiaad; //guarda el valor en la matriz diagonaladAi
           estadisticas[3]++; //cuenta la linea diagonal y añade 1 al espacio de estadisticas 3
         }
        }
   }
}

/*Vertical mas grande: Utilizamos la función mayor para comparar todas las verticales entre sí.
Finalmente tendremos la linea vertical mas grande guardada en el espacio de estadisticas 4. */
for(n = 0; n < 10; n++)
   {
     estadisticas[4] =  mayor(verticales[n], estadisticas[4]);
   }
/*Horizontal mas grande: Utilizamos la función mayor para comparar todas las horizontales entre sí.
Finalmente tendremos la linea horizontal mas grande guardada en el espacio de estadisticas 5. */
for(n = 0; n < 10; n++)
   {
     estadisticas [5] =  mayor(horizontales[n], estadisticas[5]);
   }
/*Diagonal abajo izquierda arriba derecha mas grande: Utilizamos la función mayor para comparar todas las diagonales abajo izquierda arriba derecha entre sí.
Finalmente tendremos la linea diagonal abajo izquierda arriba derecha mas grande guardada en el espacio de estadisticas 6. */
for(n = 0; n < 10; n++)
   {
     estadisticas [6] = mayor(diagonalaiAds [n], estadisticas [6]);
   }
/*Diagonal abajo derecha arriba izquierda mas grande: Utilizamos la función mayor para comparar todas las diagonales abajo derecha arriba izquierda entre sí.
Finalmente tendremos la linea diagonal abajo derecha arriba izquierda mas grande guardada en el espacio de estadisticas 7. */
for(n = 0; n < 10; n++)
   {
     estadisticas [7] = mayor(diagonaladAis [n], estadisticas [7]);
   }
/*Sumamos todas las lineas guardadas en estadisticas 0,1,2,3, para tener así el numero total de líneas,
el cual guardaremos en en espacio estadisticas 8*/
for(n = 0; n<4; n++)
   {
     estadisticas [8] = estadisticas[n] + estadisticas [8];
   }
/*Comparamos las líneas las grandes de cada tipo guardadas en estadisticas 4,5,6,7 entre sí con la función mayor.
Finalmente tendremos guardada la linea más grande en el espacio estadisticas 9.*/
for(n = 4; n<8; n++)
   {
     estadisticas [9] = mayor(estadisticas[n], estadisticas [9]);
   }
//Muestra la información de todas las estadisticas por pantalla.
for (n = 0; n < 10; n++)
{
    printf("s%d: %d \n", n, estadisticas[n]);
}
}

void bola(int tabla[][M], int p)  //Función con la que tiraremos una sola bola.
{
int n, z, pos, pasos;
char dir;

printf("Inserta un valor entero (de 1 a 50) para la columna donde empezar: ");
   scanf("%d", &pos);
pos = pos-1; //Restamos 1 al valor pos ya que estamos pidiendo al usuario valores entre 1 y 50, pero la matriz va entre 0 y 49.

fflush(stdin); /*Esta funcion borra el buffer de teclado de nombre Standard Input
               para evitar errores al introducir el carácter*/

printf("Introduce la direccion de disparo de la pelota. \n* Derecha(d)\n* Izquierda(i)\nDireccion: ");
   scanf("%c", &dir);

while((dir != 100) && (dir != 105))  /*Si el valor de la direccion no es ni d ni i (100 y 105 en ascii), muestra por pantalla un mensaje de error
                                      y pide de nuevo la dirección. */
   {
   printf("ERROR : La direccion introducida no es correcta\n");
   printf("Introduce la direccion de disparo de la pelota: \n* Derecha(d)\n* Izquierda(i)\nDireccion: ");
      scanf("%c", &dir);
   }

while(pos > 49 || pos < 0)  /*Si el valor de la posición se sale de los limites de la matriz, muestra por pantalla un mensaje de error
                              y pide de nuevo la posición.*/
   {
   printf("ERROR : El numero introducido no es correcto\n");
   printf("Inserta un valor entero (de 1 a 50) para la columna donde empezar: ");
      scanf("%d", &pos);
   pos = pos-1; //Restamos 1 al valor pos ya que estamos pidiendo al usuario valores entre 1 y 50, pero la matriz va entre 0 y 49.
   }

pasos = 0; //Movimientos de la bola en la matriz.
for(n = 0; n < p; n++)
{
    tabla[n][pos] = pasos;
    if (pasos == 1)   // Utilizamos los if para evitar que nos imprima un asterisco.
    {
    tabla[n][pos] = 100000;
    }
    if (pasos == 0) // Utilizamos los if para evitar que nos imprima un punto.
    {
    tabla[n][pos] = 100001;
    }
pasos++;
 if (tabla[n+1][pos] == 0)  //No hay obstaculo. No se hará nada y se continua con el nuevo valor del for.
 {

 }
   else if (dir == 'd')  //Movimientos de la bola cuando la dirección sea derecha.
       {
         while (tabla[n+1][pos] == 1)
         {
           if (tabla[n][pos+1] == 0)
           {
               pos++;
               tabla[n][pos] = pasos;
               pasos++;
               if (pos>49 || pos < 0)
               {
                   break;
               }
           }
           else if (tabla[n][pos-1] == 0)
           {
               pos--;
               tabla[n][pos] = pasos;
               pasos++;
               if (pos>49 || pos < 0)
               {
                   break;
               }
               dir = 'i';
           }
           else
           {
               break;
           }
         }
       }
   else     //Movimientos de la bola cuando la dirección sea izquierda.
       {
         while (tabla[n+1][pos] == 1)
         {
         if (tabla[n][pos-1] == 0)
           {
               pos--;
               tabla[n][pos] = pasos;
               pasos++;
               if (pos>49 || pos < 0)
               {
                   break;
               }
           }
           else if (tabla[n][pos+1] == 0)
           {
               pos++;
               tabla[n][pos] = pasos;
               pasos++;
               if (pos>49 || pos < 0)
               {
                   break;
               }
               dir = 'd';
           }
           else
           {
               break;
           }
         }
       }
}

for(n = 0; n < p; n++) //for que imprime la tabla.
{
   for(z = 0; z < M; z++)
   {
       if (tabla[n][z] == 100001)
       {
           printf(" 0");
       }
       else if (tabla[n][z] == 100000)
       {
           printf(" 1");
       }
       else if (tabla[n][z] < 10 && tabla[n][z] != 100000 && tabla[n][z] != 100001 && tabla[n][z] != 1 && tabla[n][z] != 0)
       {
           printf("%2d",tabla[n][z]); //imprimiremos los numeros de una cifra con dos espacios
       }
       else if(tabla[n][z] == 1)
       {
           printf(" *");
       }
       else if(tabla[n][z] == 0)
       {
           printf(" .");
       }
       else
        {
           printf("%d",tabla[n][z]);
        }
   }
printf("\n");
}
}

void bolas10(int tabla[][M], int p) //Función que muestra el recorrido de diez bolas
{
int n, z, pos;
char dir;
int disparos_pos[10] = {1, 5, 14, 22, 37, 48, 43, 40, 28, 19};    //Array de posición de salida de cada bola.
char disparos_dir[10]= {'i','i','d','i','d','d','i','d','d','i'};   //Dirección de salida de cada bola.

for (z = 0; z<10; z++) //for que va sacando cada bola.
{
dir = disparos_dir[z]; //Determina la dirección de cada bola.
pos = disparos_pos[z]; //Determina la posicion de cada bola.
for(n = 0; n < p; n++)
{
   tabla[n][pos] = tabla[n][pos] + 2;
   if (tabla[n+1][pos] != 1)
      {
       //La bola sigue cayendo.
      }
   else if (dir == 'd')  //Movimientos de la bola con dirección hacia la derecha.
       {
         while (tabla[n+1][pos] == 1)
         {
           if (tabla[n][pos+1] != 1)
           {
               pos++;
               if (pos>49 || pos < 0)
               {
                   break;
               }
               tabla[n][pos] = tabla[n][pos] + 2;
           }
           else if (tabla[n][pos-1] != 1)
           {
               pos--;
               if (pos>49 || pos < 0)
               {
                   break;
               }
               tabla[n][pos] = tabla[n][pos] + 2;
               dir = 'i';
           }
           else
           {
               break;
           }
         }
       }
   else  //Movimientos de la bola con dirección hacia la izquierda.
       {
         while (tabla[n+1][pos] == 1)
         {
         if (tabla[n][pos-1] != 1)
           {
               pos--;
               if (pos>49 || pos < 0)
               {
                   break;
               }
               tabla[n][pos] = tabla[n][pos] + 2;
           }
           else if (tabla[n][pos+1] != 1)
           {
               pos++;
               if (pos>49 || pos < 0)
               {
                   break;
               }
               tabla[n][pos] = tabla[n][pos] + 2;
               dir = 'd';
           }
           else
           {
               break;
           }
         }
       }
}
}

for(n = 0; n < p; n++) // imprime la tabla para las diez bolas.
{
   for(z = 0; z < M; z++)
   {
       if(tabla[n][z] == 1)
       {
           printf("*");
       }
       else if(tabla[n][z] == 0)
       {
           printf(".");
       }
       else
        {
           printf("%d",tabla[n][z]/2);
        }
   }
printf("\n");
}
}

//Devuelve la tabla a los valores iniciales (especialmente útil después de usar funciones como la numero tres).

void tablainicial(int tabla[][M], int p)
{
int n,z;
int tablaor[M][M]= {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

for(n = 0; n < p; n++) //for que adjudica a la tabla los valores de la tabla inicial.
{
   for(z = 0; z < M; z++)
   {
       tabla[n][z] = tablaor[n][z];
   }
}
}

int mayor (int a, int b) //función que compara entre dos numeros y elije el mas grande.
{
if(a>b)
   {
    return(a);
   }
else
   {
return (b);
   }
}














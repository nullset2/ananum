//Programa que resuelve un sistema de ecuaciones por metodo tridiagonal
//3 sep 2011 Jose Alfredo Gallegos Chavarria (1383375) (jalfredo.gallegos@gmail.com)

//empezamos incluyendo archivos de cabecera librerias estandar
#include <stdio.h>
#include <stdlib.h>

//inicia ejecucion (main)
int main(int argc, char *argv[])
{
    //declaramos una variable entero para el numero de ecuaciones y variables (n)
    float numEcuaciones = 0;
    int i = 0, j = 0;
    
    //luego usamos este ciclo para validar y entrar datos aceptados para el tamaño
    //de la matriz a usar para tridiagonal
    while(numEcuaciones > 10 || numEcuaciones <= 1){
                        printf(" Entrar numero de ecuaciones (maximo 10): ");
                        scanf("%f", &numEcuaciones);
    }
    
    //ahora creamos una matriz de tamaño n*n+1 (10 > n > 2)
    float TD[(int)numEcuaciones][(int)numEcuaciones + 1];
    
    //inicializamos la matriz con puros ceros
    for(i = 0; i < numEcuaciones; i++)
                        for(j = 0; j < (numEcuaciones + 1); j++)
                              TD[i][j] = 0;
    
    //muestra un prompt adecuado para que el usuario pueble la matriz
    printf("\n\n No. de columna: No. de Variable\n No. de fila:    No. de Ecuacion");
    printf("\n\n Entre los coeficientes de su sistema.");
    printf("\n \(Por favor separe los valores en un mismo renglon con tabulaciones)\n\n");
    
    //y este metodo captura los datos de la matriz, dependiendo del tamano de la matriz
    for(i = 0; i < numEcuaciones; i++){
                        printf("\t");
                        for(j = 0; j < (numEcuaciones + 1); j++){
                              scanf("\t%f", &TD[i][j]);
                        }
    }
    
    //ahora imprimimos la matriz en pantalla..
    printf("\n\n Matriz Entrada...\n\n");
    for(i = 0; i < numEcuaciones; i++){
                        printf("\n");
                        
                        for(j = 0; j < (numEcuaciones + 1); j++)
                              printf("\t%.0f", TD[i][j]);
    }
    
    //validamos que se tiene una matriz entrada adecuada para el metodo tridiagonal
    //es decir, solo la diagonal central, inferior y superior a la central deben tener datos != 0
    for(i = 0; i < numEcuaciones; i++){
                        for(j = 0; j < numEcuaciones; j++){
                              if((!(i == j)) && (!(i == j - 1)) && (!(i == j + 1))){
                                     if(TD[i][j] != 0){
                                         printf("\n\n Matriz no adecuada para metodo tridiagonal!! \n\n");
                                         system("PAUSE");
                                         return 0;
                                     }
                              }
                        }
    }
    
    //resolucion del sistema por metodo tridiagonal
    float r, bCambiado, dCambiado;
    
    for(i = 0; i < numEcuaciones; i++){
                        for(j = 0; j < numEcuaciones; j++){
                              if(i == j + 1){
                                   r = TD[i][j]/TD[i - 1][j];
                                   
                                   bCambiado = TD[i][j + 1] - r * TD[i - 1][j + 1];
                                   dCambiado = TD[i][(int)(numEcuaciones)] - r * TD[i - 1][(int)(numEcuaciones)];
                                   
                                   TD[i][j + 1] = bCambiado;
                                   TD[i][(int)(numEcuaciones)] = dCambiado;
                              }
                        }
    }
    
    //se imprime la matriz finalizada...
    printf("\n\n Matriz Final...\n\n");
    for(i = 0; i < numEcuaciones; i++){
                        printf("\n");
                        for(j = 0; j < (numEcuaciones + 1); j++){
                              printf("\t%.2f", TD[i][j]);
                        }
    }
    
    //y por ultimo se imprime la solucion de las X
    
    printf("\n\n Solucion del sistema...");
    
    float soluciones[(int)numEcuaciones];
    
    for(i = (int)(numEcuaciones - 1); i >= 0; i--){
          if(i == (numEcuaciones - 1)){
               soluciones[i] = (TD[i][((int)numEcuaciones)] / TD[i][i]);
          }
          else{
               soluciones[i] = (TD[i][((int)numEcuaciones)] - (TD[i][i+1]*soluciones[i+1]))/ TD[i][i];
          }
          
               
    }
    
    //salida de las soluciones
    for(i = 0; i < numEcuaciones; i++)
          printf("\n\n x%d = %.2f", (i+1), soluciones[i]);
    
    //espera a que el usuario imprima una tecla, y termina la ejecucion del programa
    printf("\n\n");
    system("PAUSE");	
    return 0;
}

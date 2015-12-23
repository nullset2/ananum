/*Programa para resolver un sistema de ecuaciones n*n
  por medio del metodo de gauss-jordan
		   
		   Análisis Numérico
		   José Alfredo Gallegos Chavarría
		   mat. 1383375
		   20 de febrero de 2012
*/

//directivas de preprocesamiento adecuadas para el compilador
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;			//specificación del namespace
int n = 0;						//tamaño del sistema de ecuaciones

//prototipos de funciones
void entraTamanoMatriz();
void imprimeEncabezado();
void imprimeInstrucciones();

//inicio de ejecucion
int main(){

	while(n <= 1  || n > 5){
		imprimeEncabezado();
		entraTamanoMatriz();
	}
	
	double matrizDatos[n][n + 1]; //he decidido implementarlo como variables estáticas por motivos prácticos
	double vectorAux[n + 1];
	double aux = 0;
	int l = 0, k = 0;
	char opcion = 'N';
	cout << fixed << setprecision(5);
  	
    imprimeEncabezado();
	imprimeInstrucciones();
  	
  	do{
        imprimeEncabezado();
        cout << "Entre datos del sistema: \n\n";
        
		for(int i = 0; i < n; i++){	//captura datos de la matriz de valores
			cout << "\t>>";
			
			for(int j = 0; j < n + 1; j++)
					cin >> matrizDatos[i][j];	//desde entrada estandar
		}
		
	    cout << "\nLos datos estan correctos? (S/N): ";
	    cin >> opcion;
    } while(opcion == 'n' || opcion == 'N');
  	
  	//calculos de Gauss-Jordan
    for(int i = 0; i < n; i++){  //para cada uno de los renglones...
    		for(int j = 0; j < n + 1; j++){ //recorre columna a columna
					if(i == j){
						 if(matrizDatos[i][j] == 0.0000){ cout << "Sistema no compatible para resolución con Gauss-Jordan";
	 	 	  			 					         system("PAUSE"); return 0;
						 }
						 if(matrizDatos[i][j] == 1.0000){ continue; }
				         
						 aux = matrizDatos[i][j];
				         
				         for(int k = 0; k < n + 1; k++){ matrizDatos[i][k] /= aux; }
				         for(int k = 0; k < n + 1; k++){ vectorAux[k] = matrizDatos[i][k]; }
				         
				         for(int k = n - 1; k >= 0; k--){
						 		 if(k == i){ continue; }
					             aux = matrizDatos[k][j];
					             matrizDatos[k][j] = matrizDatos[k][j] - aux * vectorAux[k];
						 }
				  }
		  }
				         
	}
	
	cout << "Salida: " << endl;
    //rutina para imprimir la matriz en pantalla
    for(int i = 0; i < n; i++){	//para cada renglon....
		for(int j = 0; j < n + 1; j++)  //imprime las columnas una tras una...
				cout << " \t " << matrizDatos[i][j];	//muestra la matriz en salida estandar
	
		cout << endl;  //y no olvides saltar el renglón, dado que aqui no estamos entrando datos con saltos de linea	
	}
	cout << endl;
  	
	system("PAUSE");
	return 0;
}

//esta funcion muestra un prompt al usuario con un mensaje adecuado para entrar el valor de n
void entraTamanoMatriz(){
	 
	 cout << "Entre el tamano del sistema de ecuaciones n*n (2 <= n <= 5): ";
	 cin >> n;
	  	
	 if(n <= 1  || n > 5){
	 	  cout << "ERROR: Dato no valido! ";
		  system("PAUSE");
	 }
     system("cls");
}
	 
//funcion por motivos de presentación de informacion en pantalla
void imprimeEncabezado(){
	 system("cls");
	 cout << "\t\t\t      Resolucion de un SE" << endl;
	 cout << "\t\t\t  por Metodo de Gauss-Jordan" << endl;
	 cout << "\t\t\tJose Alfredo Gallegos Chavarria\n";
	 cout << "\t\t\t      (Febrero 29, 2012)\n\n";
}

//funcion para mostrar información util al usuario al momento de empezar a capturar datos
void imprimeInstrucciones(){
  	
  	cout << "Entre la matriz de coeficientes...\n" << endl
		 << "(Debe entrar un dato valido en cada casilla de la matriz," << endl
	 	 << "representando los coeficientes de sus ecuaciones" << endl
		 << "con una tabulacion entre cada par de coeficientes," << endl;
  	
  	cout << "por ejemplo, para el sistema de ecuaciones... " << endl
  	
  		 << "\n\t3*x1 - 0.01*x2 - 0.2*x3 = 7.85" << endl
  		 << "\t0.1*x1 + 7*x2 - 0.3*x3 = -19.3" << endl
  		 << "\t0.3*x1 - 0.2*x2 + 10*x3 = 71.4\n" << endl
  		 
  		 << "...ud. entraria los siguientes datos con espacios entre columnas " << endl
  		 << "y saltos de linea entre renglones..." << endl
  		 << "\n\t3\t-0.01\t-0.2\t7.85" << endl
  		 << "\t0.1\t7\t-0.3\t-19.3" << endl
  		 << "\t0.3\t-0.2\t10\t71.4 )\n" << endl;
  		 
    system("PAUSE");
    system("cls");
    cout << " n = " << n << endl;
  	cout << " Entre la matriz de coeficientes...\n";
}

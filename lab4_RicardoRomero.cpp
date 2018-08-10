#include <iostream>

using namespace std;

void ejer1();
void ejer2();
void llenarMatrix(int**, int);
void imprimirMatrix(int**, int);
void liberarMatrix(int**&, int&);


int main() {
		
	srand(time(NULL));
	int opcion;
	do{
		cout<<"Bienvenido al Menú de Opciones"<<endl;
		cout<<"1.- Ejer 1"<<endl;
		cout<<"2.- Ejer 2"<<endl;
		cout<<"3.- salir"<<endl;
		cin>> opcion;

		switch(opcion) {
			case 1:
				ejer1();
				break;
			case 2:
				ejer2();
				break;
			case 3:
				cout<<"¡TENGA BUEN DIA!"<<endl;
				break;
		}
	}while(opcion != 3);
}

void ejer1() {
	int size;
	int x, y;
	int mainmatrix2[size-1][size-1];

	cout<<"Ingrese el tamaño de la matriz: "<<endl;
	cin>> size;

	int** mainmatrix = new int*[size];

	for(int i = 0; i < size; i++) {
		mainmatrix[i] = new int[size];
	}
	
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			mainmatrix[i][j] = 0;
		}
	}

	llenarMatrix(mainmatrix, size);
	imprimirMatrix(mainmatrix, size);

	cout<<"Ingrese X: "<<endl;
	cin>> x;
	cout<<"Ingrese Y: "<<endl;
	cin>> y;

  	for(int i = x-1; i < size; i++) {
		for(int j = 0; j < size; i++) {
			mainmatrix[i][j] = mainmatrix[i+1][j];
		}
	}

	for(int i = 0; i < size; i++) {
		for(int j = y-1; j < size; i++) {
			mainmatrix[i][j] = mainmatrix[i][j+1];
		}
	}

	for(int i = 0; i < size-1; i++) {
		for(int j = 0; j < size-1; j++) {
			mainmatrix2[i][j] = mainmatrix[i][j];
			cout<<"["<<mainmatrix2[i][j]<<"]";
		}
	}

	for(int i = 0; i < size-1; i++) {
		for(int j = 0; j < size-1; j++) {
			cout<<"["<<mainmatrix2[i][j]<<"]";
		}
	}

}	

void ejer2() {
	
}

void llenarMatrix(int** matrix, int size) {

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 6 + 1;
		}

	}
}

void imprimirMatrix(int** matrix, int size) {
	
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout<<"["<<matrix[i][j]<<"]"; 
		}
		cout<<endl;
	}
}

void liberarMatrix(int**& matrix, int& size) {
	if(matrix != NULL) {
		for(int i = 0; i < size; i++) {
			delete[] matrix[i];
		        matrix[i] = NULL;
				
		}
		
		delete[] matrix;
	        matrix = NULL;
       		size = 0;	       
	}
}



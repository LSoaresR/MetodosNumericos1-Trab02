#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int n = 0;
double** squareMatrixAllocate(int dimensions)
{
    double **matrix = (double**)malloc(dimensions * sizeof(double*));

    for(int i = 0;i < dimensions;i++)
    {
        matrix[i] = (double*)malloc(dimensions * sizeof(double));
    }

    return matrix;
}

double calcularDeterminante(double **M) {
	double det = M[0][0];	
	for( int  i = 1; i < n ; i++) {
		det = det * M[i][i];
	}
	return det;
}

double **MatrizO(double **M) {

	double** matrix = squareMatrixAllocate(n);
    for(int i = 0;i < n;i++) {
    	for(int j =0;j < n; j++){
        	matrix[i][j] = M[i][j];
   		}
	 }
	

    return matrix;
}

double **calcularGauss(double **M) {
	double** matriz = squareMatrixAllocate(n);
	
	double matrix[n][n];
	
	for(int i = 0 ; i < n; i++) {
		for(int j = 0; j < n;j++) {
			matrix[i][j] = M[i][j];
		}
	}
	
	int i = 0;
	int j = 0;
	double pivo = 0;
	double linha = 0;
	double w = 0;
		while(j != n) {	
		pivo = matrix[i][j];
		for(int k = i; k < n; k++) {
			linha = matrix[k+1][j];
			w = linha/pivo; //Wa,b
			//modificar a linha completa			
			for(int l = 0; l < n; l++) {				
				matrix[k+1][l] = matrix[k+1][l] - w*matrix[i][l];
			} 
		}	
		i++; j++;	
	}
	
	for(int i = 0 ; i < n; i++) {
		for(int j = 0; j < n;j++) {
			matriz[i][j] = matrix[i][j];
		}
	}	
	return matriz;
}

int main() {		
	cout << "Entre com o tamanho da matriz ";
	cin >> n;
	double **matriz = squareMatrixAllocate(n);
	double **matrizO = squareMatrixAllocate(n);
	double matrix[n][n];
	
	double v[n]; //vetor com valores de b
	double d[n]; // vetor com soluções x
	
	//Preencher matrix(entrada de dados)
	for(int i = 0 ; i < n; i++) {
		for(int j = 0; j < n;j++) {
			cout << "Entre com a posição A[" << i << "][" << j <<"] :"<< endl;
			cin >> matrix[i][j];
		}
	}
	
	//matriz original
	for(int i = 0 ; i < n; i++) {
		for(int j = 0; j < n;j++) {
			matrizO[i][j] = matrix[i][j];
		}
	}
	
	cout << "\nVALORES DE V";
	for(int i = 0; i < n;i++) {
		cout << "Entre com v[" << i << "] :" <<endl;
		cin >> v[i];
	}
	
	cout << "\nMATRIZ SEM GAUSS"<< endl;
	for(int i = 0 ; i < n; i++) {
		cout << endl;
		for(int j = 0; j < n;j++) {
			cout << " " << matrix[i][j];
		}
	}
	

	//Construir matriz de Gauss

	
	//preencher matriz automatica
	
	for(int i = 0 ; i < n; i++) {
		for(int j = 0; j < n;j++) {
			matriz[i][j] = matrix[i][j];
		}
	}
	matriz = calcularGauss(matriz);
	//Mostrar Matriz
	cout << "\nMATRIZ APOS GAUSS" << endl;
	for(int i = 0 ; i < n; i++) {
		cout << endl;
		for(int j = 0; j < n;j++) {
			cout << " " << matriz[i][j];
		}
	}
	
	
	
	//Calcular Determinante

	
	double det_C = calcularDeterminante(matriz) ;
	
	//Regra de Cramer
	for(int  i = 0; i < n; i++) {
		matriz = MatrizO(matrizO);
		for(int k = 0; k < n; k++) {
			matriz[k][i] = v[k];
		}
		cout << "\nMATRIZ Iteração: "<< i << endl;
		for(int i = 0 ; i < n; i++) {
			cout << endl;
			for(int j = 0; j < n;j++) {
				cout << " " << matriz[i][j];
			}
		}
		matriz = calcularGauss(matriz);
		cout << endl <<calcularDeterminante(matriz) << endl;;
		d[i] = (calcularDeterminante(matriz))/det_C;
		
	}
	
	cout << "\nValores de D: \n";
	for( int i = 0; i < n; i++) {
		cout << d[i] << endl;
	}
	return 0;
}

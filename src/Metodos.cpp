#include "Cramer.cpp"
#include "Gauss.cpp"
#include "GaussJordan.cpp"
#include "Matrix.cpp"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Metodos{

	public:
		//Construtor
		Metodos(){

		}

		void receberDados(){
			int n, i, j, m, v;

			//limpamos o vetor v e a matriz C
			this->v.clear();
			this->C.~Matrix();

			cout << "Digite número de pêndulos: ";
			cin >> n;
			this->C = Matrix(n, n);
			cout << "\nDigite valor do parâmetro para cálculo das amplitudes: ";
			cin >> this->a;
			cout << "\nPreencha a matriz M, linha por linha:" << endl;
			for (i = 1; i <= n; i++){
				for(j = 1; j <= n; j++){
					cout << "m" << i << j << ": ";
					cin >> m;
					this->C(i, j) = m;
				}
			}
			cout << "\nPreencha o vetor v:" << endl;
			for(i = 0; i < n; i++){
				cout << "v" << i << ": ";
				cin >> v;
				this->v.push_back(v);
			}
		}

		void quadroRespostaCramer(){

		}

		void quadroRespostaGauss(){

		}

		void quadroRespostaGaussJordan(){

		}

		void quadroRespostaCalibrado(){

		}

		void quadroRespostaComparativo(){

		}

	private:
		Matrix C;
		vector<double> v;
		double a;

};

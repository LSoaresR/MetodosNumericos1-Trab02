#ifndef CRAMER
#define CRAMER

#include "Matrix.cpp"
#include "Dados.cpp"

#include <iostream>
#include <vector>


class Cramer {
	public:
		
		Cramer();
		//passando a Matriz 'C' e o vetor resultado 'v'
			Cramer(const Matrix& a, vector<double> v, int n) {
			
			vector<Matrix> m;
			double d[n];
			double det = Det(a);
			this->determinantes.push_back(det);
			double det_aux = 0;
		
			for(int j = 1; j <= n; j++) {
				Matrix aux = a;
				for(int k = 1; k <= n ; k++) {
					aux(k,j) = v[k-1];									
				}
				
				this->mat.push_back(aux);

				//agora esse vetor iteração vai ser armazenado pra mostrar depois cada ietreção da determinante, que vai ter tamanho n
				det_aux = Det(aux);
				this->determinantes.push_back(det_aux);
				d[j-1] = (det_aux)/(det);
				this->solucao.push_back(d[j-1]);
								
	        } 
				
	}				
		
		double Det(const Matrix& a)
		{
		  double d = 0;    // value of the determinant
		  int rows = a.GetRows();
		  int cols = a.GetRows();
		
		  if (rows == cols)
		  {
		    // this is a square matrix
		    if (rows == 1)
		    {
		      // this is a 1 x 1 matrix
		      d = a.get(1, 1);
		    }
		    else if (rows == 2)
		    {
		      // this is a 2 x 2 matrix
		      // the determinant of [a11,a12;a21,a22] is det = a11*a22-a21*a12
		      d = a.get(1, 1) * a.get(2, 2) - a.get(2, 1) * a.get(1, 2);
		    }
		    else
		    {
		      // this is a matrix of 3 x 3 or larger
		      for (int c = 1; c <= cols; c++)
		      {
		        Matrix M = a.Minor(1, c);
		        //d += pow(-1, 1+c) * a(1, c) * Det(M);
		        d += (c%2 + c%2 - 1) * a.get(1, c) * Det(M); // faster than with pow()
		      }
		    }
		  }
		  else
		  {
		    throw Exception("Matrix must be square");
		  }
		  return d;
		}
		
		vector<Matrix> getMatrix() {
			return mat;
		}
		
		double getDeterminantes(int i) {
			return determinantes[i];
		}
		
		double getSolucao(int i) {
			return solucao[i];
		}
		
		private:
			vector<Matrix> mat;
			vector<double> determinantes;
			vector<double> solucao;
};

#endif //CRAMER

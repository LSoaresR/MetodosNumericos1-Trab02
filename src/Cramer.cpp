#include "Matrix.cpp"
#include <iostream>
#include <vector>

class Cramer {
	public:
		
		Cramer();
		//passando a Matriz 'C' e o vetor resultado 'v'
			Cramer(const Matrix& a, double *v, int n) {
			dimension = n;
			double d[n];
			double det = Det(a);
			double det_aux = 0;
		
			for(int j = 1; j <= n; j++) {
				Matrix aux = a;
			
				//aux.Print();	
				//std::cout << j;
				for(int k = 1; k <= n ; k++) {
					aux(k,j) = v[k-1];
					//matriz[k-1][j-1] = v[k-1];									
				}
				std::cout << "Passo: ";	
				//	aux.Print();
				//agora esse vetor iteração vai ser armazenado pra mostrar depois cada ietreção da determinante, que vai ter tamanho n
				det_aux = Det(aux);
				//std::cout << det_aux;
				d[j-1] = (det_aux)/(det);
				
	}
			std::cout << "\n";
			for(int i = 0; i < n; i++)
				std::cout << "x[" << i+1 << "]: " << d[i];
			 
		
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
		
		
};

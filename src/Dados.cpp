#ifndef DADOS
#define DADOS

#include <vector>
#include "Matrix.cpp"


using namespace std;

class Dados{
	public:
		//construtores
		Dados(){

		}
		Dados(Matrix C, vector<double> d, vector<double> v){
			this->C = C;
			this->d.swap(d);
			this->v.swap(v);
		}

		//Destrutor
		~Dados(){
			this->C.~Matrix();
			this->d.clear();
			this->v.clear();
		}
	
		//sets
		void setC(Matrix C){
			this->C = C;
		}
		void setD(double d){
			this->d.push_back(d);
		}
		void setV(double v){
			this->v.push_back(v);
		}
		
		//gets
		Matrix getC(){
			return this->C;
		}
		vector<double> getD(){
			return this->d;
		}
		vector<double> getV(){
			return this->v;
		}
		
	private:
		
		Matrix C;
		vector<double> d;
		vector<double> v;
		
};

#endif //DADOS

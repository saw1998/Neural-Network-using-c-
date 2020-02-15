#pragma once

namespace GraceAI{
	class Matrix{
		
		float* data;
		int rows,columns;
		int total;

	public:

		Matrix(int rows,int columns){
			this->rows=rows;
			this->columns=columns;
			this->total=rows*columns;
			data = (float*)_aligned_malloc(sizeof(float)*total,64);  ///


		}

		~Matrix(){
			_aligned_free(data);
		}

		float& operator()(int row,int col){

			return data[row+col*rows];
		}

		void MUL(Matrix &a,Matrix &b){
			if(a.columns!=b.rows){
				throw "Columns of Matrix A must equal rows of Matrix B";
			}

			if(this == &a || this ==&b)
				throw "Destination matrix must be distinct from matrix A and B";

			ind sharedDim = a.colums;

			for(int r=0;r< a.rows;r++){
				for(int c=0;c<b.columns;c++){

					float total =0.0f;
					for(int d=0;d<sharedDim;d++){

						total+=a(r,d) * b(d,c);
					}

					this->operator()(r,c)=total;
				}
			}
		}

		void Hadamard(Matrix% a){

			if(this->rows !=a.rows || this->columns != a.columns)
				throw "Matrix must of the same dimension to Hadamard";

			for(int i=0;i<this->total;i++){

				data[i]*=a.data[i];
			}
		}

		void ADD(Matrix% a){

			if(this->rows !=a.rows || this->columns != a.columns)
				throw "Matrix must of the same dimension to ADD";

			for(int i=0;i<this->total;i++){

				data[i]+=a.data[i];
			}
		}

		void SUB(Matrix% a){

			if(this->rows !=a.rows || this->columns != a.columns)
				throw "Matrix must of the same dimension to SUB";

			for(int i=0;i<this->total;i++){

				data[i]-=a.data[i];
			}
		}

	};
}
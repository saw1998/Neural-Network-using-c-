#pragma once
#include"Matrix.h"

namespace GraceAI{

	class Layer{

	private:
		Matrix* activations;
		Matrix* sums;
		Matrix* weights;
		Matrix* bias;

		Matrix* deltaActivations;
		Matrix* deltaSums;
		Matrix* deltaWeights;
		Matrix* deltaBias;

		int neuronCount;

		Layer* previousLayer;
		Layer* nextLayer;

	public:
		Layer(int neuronCount){
			this->neuronCount=neuronCount;
		}

		~Layer(){
			
		}

		void SetInputLayerActivationMatrix(int neuronCount,int batchSize){

			activations=new Matrix(neuronCount,batchSize);
		}


		void SetPreviousLayer(Layer* previousLayer,int trainingBatchSize){

			activations = new Matrix(neuronCount,trainingBatchSize);
			 
		}

		void FeedForward(){

		}
		void Backprop(){

		}

	};
}
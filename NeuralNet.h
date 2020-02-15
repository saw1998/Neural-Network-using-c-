#pragma once
#include<vector>
#include"Layer.h"
#include"TrainingSet.h"

namespace GraceAI{

	class NeuralNet{

		std::vector<Layer*> layers;
		Trainingset* trainingset;

		int trainingSetBatchSize;

	public:
		NeuralNet(){

		}

		~NeuralNet(){
			
		}

		void Init(int inputNeuronCount, int trainingSetBatchSize, int outputNeuronCount){

			if(layers.size()!=0)
				throw "Neural Net has an input layer already";

			this->trainingSetBatchSize=trainingSetBatchSize;

			Layer* inputLayer=new Layer(inputNeuronCount);

			inputLayer->SetInputLayerActivationMatrix(inputNeuronCount,trainingSetBatchSize);

			layers.push_back(inputLayer);

		}

		void AddLayer(int neuronCount){

			if(layers.size()<1)
				throw "An input layer must be present prior to hidden layers, please call Init";

			Layer* hiddenLayer = new Layer(neuronCount);

			hiddenLayer->SetPreviousLayer(layers.back(),trainingSerBatchSize);
		}

		void FowardProp(){

		}

		void Backprop(){

		}
	};
} 
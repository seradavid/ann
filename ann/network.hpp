#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include "helper.hpp"

class Network
{
private:
	std::vector<std::vector<double>>layers;
	std::vector<std::vector<std::vector<double>>>weights;
	std::vector<std::vector<double>>biases;

	double inputMin;
	double inputMax;
	double outputMin;
	double outputMax;

public:
	enum ACTIVATION { SIGMOID, TANH, RELU };

private:
	ACTIVATION activationFunction;
	double getActivationOutput(double);
	double getActivationDerivative(double);

public:
	Network(int nrInputNeurons, int nrHiddenLayers, int nrOutputNeurons, ACTIVATION = TANH);
	void initializeWeights();

	std::vector<double> predict(std::vector<double>);
	void train(std::vector<std::vector<double>>, std::vector<std::vector<double>>);

	void saveModel(std::string path);
	void loadModel(std::string path);
};
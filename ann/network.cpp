#include "network.hpp"

Network::Network(int nrInputNeurons, int nrHiddenLayers, int nrOutputNeurons, ACTIVATION activationFunction)
{
	layers = std::vector<std::vector<double>>(nrHiddenLayers + 2);
	weights = std::vector<std::vector<std::vector<double>>>(nrHiddenLayers + 1);
	biases = std::vector<std::vector<double>>(nrHiddenLayers + 1);
	errors = std::vector<std::vector<double>>(nrHiddenLayers + 1);

	this->activationFunction = activationFunction;

	layers[0] = std::vector<double>(nrInputNeurons); // input layer
	for (int i = 1; i <= nrHiddenLayers; ++i)
	{
		layers[i] = std::vector<double>((layers[i - 1].size() + nrOutputNeurons) / 2); // hidden layers
	}
	layers[layers.size() - 1] = std::vector<double>(nrOutputNeurons); // output layer

	for (int i = 0; i < nrHiddenLayers + 1; ++i)
	{
		weights[i] = std::vector<std::vector<double>>(layers[i].size());
		for (int j = 0; j < layers[i].size(); ++j)
		{
			weights[i][j] = std::vector<double>(layers[i + 1].size());
		}

		biases[i] = std::vector<double>(layers[i + 1].size());

		errors[i] = std::vector<double>(layers[i + 1].size());
	}

	initializeWeights();
}

void Network::initializeWeights()
{
	srand((unsigned)time(NULL));

	for (int k = 0; k < layers.size() - 1; ++k)
	{
		for (int j = 0; j < layers[k + 1].size(); ++j)
		{
			biases[k][j] = ((double)rand() / RAND_MAX); // initialize to a random number between 0 and 1

			for (int i = 0; i < layers[k].size(); ++i)
			{
				weights[k][i][j] = ((double)rand() / RAND_MAX);
			}
		}
	}
}

double Network::getActivationOutput(double input)
{
	switch (activationFunction)
	{
	case SIGMOID:
		return sigmoid(input);
	case TANH:
		return tanh(input);
	case RELU:
		return relu(input);
	default:
		return relu(input);
	}
}

double Network::getActivationDerivative(double input)
{
	switch (activationFunction)
	{
	case SIGMOID:
		return sigmoidDerivative(input);
	case TANH:
		return tanhDerivative(input);
	case RELU:
		return reluDerivative(input);
	default:
		return reluDerivative(input);
	}
}

std::vector<double> Network::predict(std::vector<double> input)
{
	std::vector<double> result;

	layers[0] = input;

	for (int k = 0; k < layers.size() - 1; ++k)
	{
		std::vector<double> temp = add(multiply(layers[k], weights[k]), biases[k]);

		for (int i = 0; i < layers[k + 1].size(); ++i)
		{
			layers[k + 1][i] = getActivationOutput(temp[i]);
		}
	}

	result = layers[layers.size() - 1];

	return result;
}

void Network::train(std::vector<std::vector<double>> inputs, std::vector<std::vector<double>> outputs, int nrEpochs, int batchSize)
{
	std::pair<double, double> limits;

	limits = findLimits(inputs);
	inputMin = limits.first;
	inputMax = limits.second;

	limits = findLimits(outputs);
	outputMin = limits.first;
	outputMax = limits.second;

	for (int k = 0; k < inputs.size(); k += batchSize)
	{
		// Calculate the error for the output layer
		for (int i = 0; i < errors[errors.size() - 1].size(); ++i)
		{
			errors[errors.size() - 1][i] = 0;
		}

		for (int j = 0; j < batchSize; ++j)
		{
			std::vector<double> predictions = predict(inputs[k + j]);

			for (int i = 0; i < outputs.size(); ++i)
			{
				errors[errors.size() - 1][i] += (outputs[k + j][i] - predictions[i]) * getActivationDerivative(layers[layers.size() - 1][i]);
			}
		}

		for (int i = 0; i < errors[errors.size() - 1].size(); ++i)
		{
			errors[errors.size() - 1][i] /= batchSize;
		}

		// Backpropagate the error
		for (int h = layers.size() - 2; h > 0; --h)
		{

		}
	}
}
#include "helper.hpp"

std::vector<double> scaleDown(std::vector<double> input)
{
	std::vector<double> result;

	return result;
}

std::pair<double, double> findLimits(std::vector<std::vector<double>> input)
{
	double mn, mx;
	mn = mx = input[0][0];

	for (int i = 0; i < input.size(); ++i)
	{
		for (int j = 0; j < input[i].size(); ++j)
		{
			mn = mn < input[i][j] ? mn : input[i][j];
			mx = mx > input[i][j] ? mx : input[i][j];
		}
	}

	return std::make_pair(mn, mx);
}

std::vector<double> multiply(std::vector<double> vector, std::vector<std::vector<double>> matrix)
{
	std::vector<double> result = std::vector<double>(matrix[0].size());
	for (int i = 0; i < result.size(); ++i)
	{
		result[i] = 0;
	}

	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			result[j] += vector[i] * matrix[i][j];
		}
	}

	return result;
}

std::vector<double> add(std::vector<double> vector1, std::vector<double> vector2)
{
	std::vector<double> result = std::vector<double>(vector1.size());

	for (int i = 0; i < vector1.size(); ++i)
	{
		result[i] = vector1[i] + vector2[i];
	}

	return result;
}

double sigmoid(double x)
{
	return ((double)1 / (1 + exp(-x)));
}

double tanh(double x)
{
	return ((exp(x) - exp(-x)) / (exp(x) + exp(-x)));
}

double relu(double x)
{
	if (x >= 0)
	{
		return x;
	}
	else
	{
		return 0;
	}
}

double sigmoidDerivative(double x)
{
	return ((double)x * (1 - x));
}

double tanhDerivative(double x)
{
	return (1 - (x * x));
}

double reluDerivative(double x)
{
	if (x >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
#pragma once

#include <vector>
#include <cmath>

std::vector<double> scaleDown(std::vector<double>);

std::pair<double, double> findLimits(std::vector<std::vector<double>>);

std::vector<double> multiply(std::vector<double>, std::vector<std::vector<double>>);
std::vector<double> add(std::vector<double>, std::vector<double>);

double sigmoid(double);
double tanh(double);
double relu(double);

double sigmoidDerivative(double);
double tanhDerivative(double);
double reluDerivative(double);
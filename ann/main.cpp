#include "network.hpp"

using namespace std;

int main()
{
	Network n = Network(3, 2, 6);

	vector<double> in = vector<double>(3);
	in[0] = 0.2;
	in[1] = 0.85;
	in[2] = 0.37;

	vector<double> out = n.predict(in);

	system("pause");

	return 0;
}
#include "General.h"

vector<vector<char>> readCharMatrix(bool debug)
{
	string line;
	vector<vector<char>> matrix;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (getline(cin, line))
	{
		matrix.push_back(vector<char>(line.begin(), line.end()));
	}
	printMatrix(matrix, debug);

	return matrix;
}

vector<int> readIntVector(bool debug)
{
	char c;
	vector<int> vec;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (cin >> c)
	{
		vec.push_back(c - '0');
	}

	printVector(vec, debug);

	return vec;

}

long long artithmeticSum(long long start, long long stop, long long increment, bool debug)
{
	long long sum, n;

	if (start > stop)
	{
		DebugStream(debug) << "increment " << increment << ": " << start << " < " << stop << " => 0" << endl << endl;
		return 0;
	}

	if (start == stop)
	{
		DebugStream(debug) << "increment " << increment << ": " << start << " == " << stop << " => " << start  << endl << endl;
		return start;
	}


	n = (stop - start) / increment + 1;

	sum = (start + stop) * n / 2;

	DebugStream(debug) << "increment " << increment << ": (" << start << " + " << stop << ")" << " * " << n << " / 2 = " << sum << endl << endl;

	return sum;
}


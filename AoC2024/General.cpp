#include "General.h"

vector<vector<char>> readCharMatrix()
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

	return matrix;
}


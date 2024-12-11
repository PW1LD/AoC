#include "General.h"

void debug(string debugInfo, bool debugOn)
{
	if (debugOn)
	{
		cout << debugInfo << endl;
	}

}

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

void printMatrix(vector<vector<char>> matrix)
{
	for (auto itRow = matrix.begin(); itRow != matrix.end(); ++itRow)
	{
		for (auto itCol = (*itRow).begin(); itCol != (*itRow).end(); ++itCol)
		{
			cout << *itCol;
		}
		cout << endl;
	}
}

void printMatrix(vector<vector<int>> matrix)
{
	for (auto itRow = matrix.begin(); itRow != matrix.end(); ++itRow)
	{
		for (auto itCol = (*itRow).begin(); itCol != (*itRow).end(); ++itCol)
		{
			cout << *itCol;
		}
		cout << endl;
	}
}


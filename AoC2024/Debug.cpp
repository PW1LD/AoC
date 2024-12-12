#include "Debug.h"

using namespace std;

void printMatrix(vector<vector<char>> matrix, string delimeter, bool debugLocal, bool debugGlobal)
{
	if (debugLocal || debugGlobal)
	{
		for (auto itRow = matrix.begin(); itRow != matrix.end(); ++itRow)
		{
			for (auto itCol = (*itRow).begin(); itCol != (*itRow).end(); ++itCol)
			{
				cout << *itCol << delimeter;
			}
			cout << endl;
		}
		cout << endl;
	}
}

void printMatrix(vector<vector<int>> matrix, string delimeter, bool debugLocal, bool debugGlobal)
{
	if (debugLocal || debugGlobal)
	{
		for (auto itRow = matrix.begin(); itRow != matrix.end(); ++itRow)
		{
			for (auto itCol = (*itRow).begin(); itCol != (*itRow).end(); ++itCol)
			{
				cout << *itCol << delimeter;
			}
			cout << endl;
		}
		cout << endl;
	}
}

void printVector(vector<char> vec, string delimeter, bool debugLocal, bool debugGlobal)
{
	if (debugLocal || debugGlobal)
	{
		for (auto it = vec.begin(); it != vec.end(); ++it)
		{
			cout << *it << delimeter;
		}
		cout << endl << endl;
	}
}

void printVector(vector<int> vec, string delimeter, bool debugLocal, bool debugGlobal)
{
	if (debugLocal || debugGlobal)
	{
		for (auto it = vec.begin(); it != vec.end(); ++it)
		{
			cout << *it << delimeter;
		}
		cout << endl << endl;
	}
}
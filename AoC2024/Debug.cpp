#include "Debug.h"

using namespace std;

void printMatrix(vector<vector<char>> matrix, bool debug, string delimeter)
{
	if (debug)
	{
		for (auto itRow = matrix.begin(); itRow != matrix.end(); ++itRow)
		{
			for (auto itCol = (*itRow).begin(); itCol != (*itRow).end(); ++itCol)
			{
				cout << *itCol << delimeter;
			}
			if (delimeter.size())
			{
				cout << "\b \b";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void printMatrix(vector<vector<int>> matrix, bool debug, string delimeter)
{
	if (debug)
	{
		for (auto itRow = matrix.begin(); itRow != matrix.end(); ++itRow)
		{
			for (auto itCol = (*itRow).begin(); itCol != (*itRow).end(); ++itCol)
			{
				cout << *itCol << delimeter;
			}
			if (delimeter.size())
			{
				cout << "\b \b";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void printVector(vector<char> vec, bool debug, string delimeter)
{
	if (debug)
	{
		for (auto it = vec.begin(); it != vec.end(); ++it)
		{
			cout << *it << delimeter;
		}
		if (delimeter.size())
		{
			cout << "\b \b";
		}
		cout << endl << endl;
	}
}

void printVector(vector<int> vec, bool debug, string delimeter)
{
	if (debug)
	{
		for (auto it = vec.begin(); it != vec.end(); ++it)
		{
			cout << *it << delimeter;
		}
		if (delimeter.size())
		{
			cout << "\b \b";
		}
		cout << endl << endl;
	}
}
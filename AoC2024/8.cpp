#include "General.h"
#include <format>

using namespace std;

bool debugOn = true;

bool placeAntiNode(int x, int y, vector<vector<int>>& antiNodes)
{
	if (x >= 0 && x < antiNodes.size() && y >= 0 && y < antiNodes[x].size())
	{
		antiNodes[x][y] = 1;
		return true;
	}
	return false;
}

void placeBack(int x1, int y1, int x2, int y2, vector<vector<int>>& antiNodes)
{
	if (placeAntiNode(2 * x1 - x2, 2 * y1 - y2, antiNodes))
	{
		placeBack(2 * x1 - x2, 2 * y1 - y2, x1, y1, antiNodes);
	}
}

void placeAntiNodes(char c1, int x1, int y1, char c2, int x2, int y2, vector<vector<int>>& antiNodes, bool star1)
{
	if (c1 == c2)
	{
		if (star1)
		{
			placeAntiNode(2 * x1 - x2, 2 * y1 - y2, antiNodes);
			placeAntiNode(2 * x2 - x1, 2 * y2 - y1, antiNodes);
			return;
		}

		placeBack(x1, y1, x2, y2, antiNodes);
		placeBack(x2, y2, x1, y1, antiNodes);
		placeAntiNode(x1, y1, antiNodes);
		placeAntiNode(x2, y2, antiNodes);
	}
}

void checkNode(int x, int y, vector<vector<char>> antennas, vector<vector<int>>& antiNodes, bool star1)
{
	if (antennas[x][y] == '.')
	{
		return;
	}

	char c = antennas[x][y];

	for (int j = y + 1; j < antennas[x].size(); ++j)
	{
		placeAntiNodes(c, x, y, antennas[x][j], x, j, antiNodes, star1);
	}


	for (int i = x + 1; i < antennas.size(); ++i)
	{
		for (int j = 0; j < antennas[i].size(); ++j)
		{
			placeAntiNodes(c, x, y, antennas[i][j], i, j, antiNodes, star1);
		}
	}
}

vector<vector<int>> antiNodeMatrix(vector<vector<char>> antennas)
{
	vector<vector<int>> antiNodes;

	for (auto it = antennas.begin(); it != antennas.end(); ++it)
	{
		antiNodes.push_back(vector<int>((*it).size(), 0));
	}

	return antiNodes;
}

vector<vector<int>> checkNodes(vector<vector<char>> antennas, bool star1 = true)
{
	vector<vector<int>> antiNodes;

	antiNodes = antiNodeMatrix(antennas);

	for (int i = 0; i < antennas.size(); ++i)
	{
		for (int j = 0; j < antennas[i].size(); ++j)
		{
			checkNode(i, j, antennas, antiNodes, star1);
		}
	}

	return antiNodes;
}

int countAntiNodes(vector<vector<int>> antiNodes)
{
	int sum;

	sum = 0;

	for (auto itRow = antiNodes.begin(); itRow != antiNodes.end(); ++itRow)
	{
		for (auto itCol = (*itRow).begin(); itCol != (*itRow).end(); ++itCol)
		{
			sum+= *itCol;
		}
	}

	return sum;
}

int main()
{
	vector<vector<char>> antennas;
	vector<vector<int>> antiNodes;

	antennas = readCharMatrix();

	antiNodes = checkNodes(antennas);
	cout << countAntiNodes(antiNodes) << endl;

	antiNodes = checkNodes(antennas, false);
	cout << countAntiNodes(antiNodes) << endl;
	cout << endl;

	return 0;
}
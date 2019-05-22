#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
#include<thread>
//#include<stdlib.h>
#include <Windows.h>


void FillCountArray(std::string &s1, std::string &s2, int **countArr) {
	int sizeX = s1.size();
	int sizeY = s2.size();

	for (int i = 1; i <= sizeX; ++i)
	{
		for (int j = 1; j <= sizeY; ++j)
		{
			if (s1[i - 1] == s2[j - 1]) {
				countArr[i][j] = countArr[i - 1][j - 1] + 1;
			}
			else {
				countArr[i][j] = (std::max)(countArr[i - 1][j], countArr[i][j - 1]);//std::max加上括号以便与Vsual C++的min/max宏定义区分开
			}
		}
	}

}

std::vector<std::string > results;
void FindAllLCS(std::string &X, std::string &Y, int **countArr, int i, int j, std::string curRes) {


	while (i > 0 && j > 0)
	{
		if (X[i - 1] == Y[j - 1])
		{
			curRes.push_back(X[i - 1]);
			--i;
			--j;
		}
		else
		{
			if (countArr[i - 1][j] > countArr[i][j - 1])
				--i;
			else if (countArr[i - 1][j] < countArr[i][j - 1])
				--j;
			else
			{
				FindAllLCS(X, Y, countArr, i - 1, j, curRes);
				FindAllLCS(X, Y, countArr, i, j - 1, curRes);
				return;
			}
		}
	}
	std::reverse(curRes.begin(), curRes.end());
	results.emplace_back(curRes);
}
int main()
{
	std::string X = "13456778";
	std::string Y = "357486782";
	int sizeX = X.size();
	int sizeY = Y.size();

	int **CountArray = new int *[sizeX + 1];
	for (int i = 0; i < sizeY; ++i)
	{
		CountArray[i] = new int[sizeY + 1];
	}

	for (int i = 0; i <= sizeX; ++i)
	{
		for (int j = 0; j <= sizeY; ++j)
		{
			CountArray[i][j] = 0;
		}
	}

	FillCountArray(X, Y, CountArray);

	for (int i = 0; i <= sizeX; ++i)
	{
		for (int j = 0; j <= sizeY; ++j)
		{
			Sleep(100);
			std::cout << CountArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::string rest;
	FindAllLCS(X, Y, CountArray, sizeX, sizeY, rest);

	for (int i = 0; i < results.size(); ++i)
	{
		std::cout << results[i] << std::endl;
	}

	delete[]CountArray;

	system("pause");
	return 0;
}


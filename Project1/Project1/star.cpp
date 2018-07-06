#include<iostream>

int main()
{
	char arr[4][5] = { NULL };
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < i+1; j++)
		{
			arr[i][j] = '*';
		}
	}

	for (int i = 0; i < 4; i++)
	{
		std::cout << arr[i] << std::endl;
	}


}
#include<iostream>

int main()
{
	int sum = 0;
	for (int i = 1; i < 11; i++)
	{
		sum += i;
	}
	std::cout << "1에서 10까지 더한 결과 : "<<sum;
//	std::cout<<sum;
}
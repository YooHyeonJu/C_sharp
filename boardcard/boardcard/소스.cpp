#include <stdio.h>
#include <stdlib.h>

//char type[4][3][2] = { { { 0,0 },{ 0,1 },{ 1,0 } },{ { 0,0 },{ 0,1 },{ 1,1 } },{ { 0,0 },{ 1,0 },{ 1,1 } },{ { 0,0 },{ 1,0 },{ 1,-1 } } };
char type[4][2][2] = { { { 0,1 },{ 1,0 } },{ { 0,1 },{ 1,1 } },{ { 1,0 },{ 1,1 } },{{ 1,0 },{ 1,-1 } } };

bool exist(char**arr,int h, int w)
{
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (arr[i][j] == '.')
			{
				return true;
			}
		}
	}
	return false;
}

bool check(char**arr, int h, int w)
{
	int i, j;
	int t_1 = 0, t_2 = 0;
	bool flag = false;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
		{
			t_1 = type[i][j][0];
			t_2 = type[i][j][1];
			
			if (arr[h + t_1][w + t_2] == '.')
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
			
		}
		if (flag == true)
		{
			return true;
		}
	}
}

bool recursive(char**arr,int h, int w)
{
	bool flag = false;
	int i, j;
	int cnt = 0;

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (arr[i][j] == '.')
			{
				flag = check(arr, i, j);
			}
		}
	}
	return flag;
}

int main()
{
	int total = 0;
	int Height = 0;
	int Width = 0;
	int i, j , k;
	char**arr = 0;
	int count = 0;
	

	printf("��ü ���� : ");
	scanf_s("%d", &total);

	for (i = 0; i < total; i++)
	{
		printf("Height : ");
		scanf_s("%d", &Height);
		printf("Width : ");
		scanf_s("%d", &Width);
		//���� ����
		arr = (char**)malloc(sizeof(char*)* Height);
		for (j = 0; j < Height; j++)
		{
			arr[j] = (char*)malloc(sizeof(char)*(Width+1));
		}

		//���ڿ� �Է�
		printf("���ڿ� �Է�\n");
		for (j = 0; j < Height; j++)
		{			
			scanf_s("%s", arr[j], sizeof(char)*(Width + 1));
			//printf("%d", count);

			
		}

		//�� ���
		for (j = 0; j < Height; j++)
		{
			for (k = 0; k < Width; k++)
			{
				if (arr[j][k] == '.')
				{
					count++;
				}
			}
			
		}
		//printf("count = %d\n", count);
		if (count % 3 != 0)
		{
			printf("0\n");
			break;
		}
		else
		{
			printf("����Լ�!");
			bool result = recursive(arr,Height,Width);
			if (result)
			{
				printf("����");
			}
			else
			{
				printf("����");
			}
		}
	}

	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

char type[4][3][2] = { { { 0,0 },{ 0,1 },{ 1,0 } },{ { 0,0 },{ 0,1 },{ 1,1 } },{ { 0,0 },{ 1,0 },{ 1,1 } },{ { 0,0 },{ 1,0 },{ 1,-1 } } };

int cnt = 0;

bool exist(char**arr, int h, int w)
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

bool check(char**arr, int Height, int Width, int _h, int _w)
{
	int i, j;
	//int t_1 = 0, t_2 = 0;
	bool flag = true;	//잘못 되었음을 확인

	for (i = 0; i < 4; i++)
	{
		for (j = 1; j <= 2; j++)
		{
			//배열 크기 초과 확인 ->크면 i변경
			if (_h + type[i][j][0]<0 || _h + type[i][j][0]>Height || _w + type[i][j][1]<0 || _w + type[i][j][1]>Width)
			{
				flag = false;
				break;
			}

		}
		if (flag == true)
		{
			if (arr[_h + type[i][1][0]][_w + type[i][1][1]] == '.' && arr[_h + type[i][2][0]][_w + type[i][2][1]] == '.')
			{
				arr[_h + type[i][0][0]][_w + type[i][0][1]] = '1';
				arr[_h + type[i][1][0]][_w + type[i][1][1]] = '1';
				arr[_h + type[i][2][0]][_w + type[i][2][1]] = '1';
				return true;
			}			
		}
		else {
			flag = true;
		}
	}
	return flag;
}

bool recursive(char**arr, int h, int w)
{
	bool flag = false;
	int i, j;
	int count = 0;

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (arr[i][j] == '.')
			{
				flag = check(arr, h, w, i, j);
			}
		}
	}
	return flag;
}

int main()
{
	//int total = 0;
	int Height = 0;
	int Width = 0;
	int  j, k;
	char**arr = 0;
	int count = 0;


	//printf("전체 개수 : ");
	//scanf_s("%d", &total);

	//for (i = 0; i < total; i++)
	//{
	//printf("Height : ");
	//scanf_s("%d", &Height);
	//printf("Width : ");
	//scanf_s("%d", &Width);
	Height = 3;
	Width = 3;
	//공간 생성
	arr = (char**)malloc(sizeof(char*)* Height);
	for (j = 0; j < Height; j++)
	{
		arr[j] = (char*)malloc(sizeof(char)*(Width + 1));
	}

	//문자열 입력
	printf("문자열 입력\n");
	for (j = 0; j < Height; j++)
	{
		scanf_s("%s", arr[j], sizeof(char)*(Width + 1));
		//printf("%d", count);


	}

	//값 출력
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
		//break;
	}
	else
	{
		printf("재귀함수!");
		bool result = recursive(arr, Height, Width);
		if (result)
		{
			for (j = 0; j < Height; j++)
			{
				//scanf_s("%s", arr[j], sizeof(char)*(Width + 1));
				printf("%s", arr[j]);


			}
			//printf("성공");
		}
		else
		{
			printf("실패");
		}
	}
	//}


	return 0;
}

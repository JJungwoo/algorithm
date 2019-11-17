#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int re = 2;
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int arr[100][100] = { 0, };

	int count = 0;
	srand(time(NULL));

	while (re >= 1)
	{
		scanf_s("%d %d\n", &i, &j);

		for (x = 0; x < i; x++)
		{
			for (y = 0; y < j; y++)
			{
				count = rand() % 2;
				if(count == 1)
					arr[y][x] = rand()%2-1;
				
			}
		}

		for (x = 0; x < i; x++)
		{
			for (y = 0; y < j; y++)
			{
				if (arr[y][x] != -1)
				{
					if (arr[y-1][x-1] == -1)
					{
						arr[y][x] += 1;
					}
					if (arr[y-1][x] == -1)
					{
						arr[y][x] += 1;
					}
					if (arr[y-1][x+1] == -1)
					{
						arr[y][x] += 1;
					}
					if (arr[y][x-1] == -1)
					{
						arr[y][x] += 1;
					}
					if (arr[y][x+1] == -1)
					{
						arr[y][x] += 1;
					}
					if (arr[y+1][x-1] == -1)
					{
						arr[y][x] += 1;
					}
					if (arr[y+1][x] == -1)
					{
						arr[y][x] += 1;
					}
					if (arr[y+1][x+1] == -1)
					{
						arr[y][x] += 1;
					}
				}
			}
		}

		for (x = 0; x < i; x++)
		{
			for (y = 0; y < j; y++)
			{
				if (arr[y][x] == -1)
				{
					printf("* ");
				}
				else
					printf(", ");
			}
			puts("");
		}

		puts("");

		for (x = 0; x < i; x++)
		{
			for (y = 0; y < j; y++)
			{
				if (arr[y][x] == -1)
				{
					printf("* ");
				}
				else
					printf("%d ",arr[y][x]);
			}
			puts("");
		}


		for (x = 0; x < i; x++)
		{
			for (y = 0; y < j; y++)
			{
				arr[y][x] = 0;
			}
		}

		getchar();
		i = 0;
		j = 0;
		re -= 1;
	}



	return 0;
}
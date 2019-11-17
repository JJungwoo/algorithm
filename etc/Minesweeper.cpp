#include <stdio.h>

int main()
{
	int a = 0, b = 0, ex = 0;
	int length = 0,temp = 0,i = 0,maxlength = 0;
	
	while (0 == a && 0 == b)
	{
		printf("plz input a two number : ");
		scanf_s("%d %d", &a, &b);
		if (a > b)
		{
			temp = a;
			a = b;
			b = temp;
		}
		for (i = a; i <= b; i++)
		{
			ex = i;
			length++;
			while (1 != ex)
			{
				if (0 == ex % 2)	// ¦��
				{
					ex /= 2;
					length++;
				}
				else
				{
					ex = (ex * 3) + 1;
					length++;
				}
			}
			if (maxlength < length)
			{
				maxlength = length;
			}
			length = 0;
		}
		printf("%d\n", maxlength);
		maxlength = 0;
		a = 0;
		b = 0;
	}
	
	


	return 0;
}
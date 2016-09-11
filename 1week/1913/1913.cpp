#include <stdio.h>

int a[1001][1001];

int main()
{
	int n, i, k, x, y;
	int buho, value, tmp, cnt, check=0;

	scanf("%d", &n);
	scanf("%d", &k);

	x = n / 2 + 1; y = n / 2 + 2;/*아래 for문이 y-1부터이기 때문에 +2로 지정하였다.*/
	i = 1; cnt = 1; buho = -1; value = 1;

	while (i <= n*n)
	{
		if (cnt == 1)
		{


			tmp = y + (buho*value);

			for (y = y - 1; y >= tmp; y--)
			{
				if (i > n*n) break;

				a[y][x] = i;
				i++;
				//printf("(%d %d) : %d\n",y,x,a[y][x]); 
			}

			buho = -1 * buho;
			cnt++;

			if (check == 1) // 처음에만 안돌도록 
			{
				y++;
			}// for문 탈출시 y--이어서 한번 y++해준다.(좌표 이탈 방지) 
		}



		else if (cnt == 2)
		{


			tmp = x + (buho*value);

			if (check == 1)
			{
				x++;
			}

			for (x = x; x <= tmp; x++) // x+1
			{
				if (i > n*n) break;

				a[y][x] = i;
				i++;
				//printf("(%d %d) : %d\n",y,x,a[y][x]); 
			}

			value++;
			cnt++;
			x--;

			check = 1; // 처음 증감 값들 (cnt 1, 2에서 수정 위해 이용) 
		}


		else if (cnt == 3)
		{


			tmp = y + (buho*value);

			for (y = y + 1; y <= tmp; y++) // y+1
			{
				if (i > n*n) break;

				a[y][x] = i;
				i++;
				//printf("(%d %d) : %d\n",y,x,a[y][x]);  
			}

			buho = -1 * buho;
			cnt++;
			y--;
		}

		else if (cnt == 4)
		{


			tmp = x + (buho*value);

			for (x = x - 1; x >= tmp; x--) // x-1
			{
				if (i > n*n) break;

				a[y][x] = i;
				i++;
				//printf("(%d %d) : %d\n",y,x,a[y][x]);   
			}

			value++;
			cnt = 1;
			x++;
		}

	} //while



	for (y = 1; y <= n; y++)
	{
		for (x = 1; x <= n; x++)
		{

			printf("%d ", a[y][x]);

		}
		printf("\n");
	}




	for (y = 1; y <= n; y++)
	{
		for (x = 1; x <= n; x++)
		{
			if (a[y][x] == k)
			{
				printf("%d %d", y, x);
				//  sleep(100000);
				return 0;
			}
		}
	}
} 
/*int main()
{

	int num=0;
	int count = 0;
	int i, j = 0;
	int now = 1;

	scanf("%d", &num);
	count = num;

	/*generating N by N matrix(dynamic allocation)*
	int **z;
	z = (int **)malloc(sizeof(int *)*num);
	z[0] = (int *)malloc(sizeof(int)*num*num);
	for (int k = 1; k<num; k++) 
	{
		z[k] = z[k - 1] + num;
	}
	for (int G = 0; G < num; G++)
	{
		for (int S = 0; S < num; S++)
		{
			z[G][S]=0;
		}
	}
	
	/*Snail' movement*
	if (num % 2 == 0) 
	{
		i = num / 2;
		j = num / 3;
		z[i][j] = now;
		//printf("%d ", z[i][j]);
		now++;
	}
	else if (num % 2 == 1)
	{
		i = num / 2;
		j = num / 2;
		z[i][j] = 1;
		//printf("%d ", z[i][j]);
		now++;
	}
	while (1)
	{
		//시작점 셋팅
		
		if (count > 1)
		{
			//초기화 위로 하나
			//i = i - 1;
			//z[i][j] = now;
			//now++;
			for (i=i-1; j < num-1;j++)
			{/*우로 이동*
				z[i][j] = now;
				++now;
			}
			for (i; i < num-1;i++)
			{/*하단 이동*
				z[i][j] = now;
				++now;
			}

			--count;
		}
		if (count > 1)
		{
			//초기화 아래로 이동
			//now = now;
			//i = i - 1;
			//z[i][j] = now;
			//now++;
			//i = i, j = j;
			for (; j > 0;j--) // 좌로 이동 작성
			{
				i = i, j = j;
				z[i][j] = now;
				//printf("%d ", z[i][j]);
				now++;
			}
			for (i; i >= 0;i--) // 상단 이동 작성
			{
				i = i, j = j;
				z[i][j] = now;
				//printf("%d ", z[i][j]);
				now++;
			}

			--count;
		}
		else break;
	}
	for (int G=0; G < num; G++)
	
	{
		for (int S=0; S < num; S++)
		{
			printf("%d ",z[G][S]);
		}
		
		printf("\n");
	}


	printf("HELL WORLD");
	
	getchar();
	getchar();
	getchar();

	
	/*MEMORY releasing*
	free(z[0]);
	free(z);

	return 0;
}
*/
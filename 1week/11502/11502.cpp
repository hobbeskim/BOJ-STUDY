
#include <stdio.h>
#include<stdlib.h>


int prime[168] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 197, 199,203, 209, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,601, 607, 613, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,809, 811, 821, 823, 827, 829, 837, 853, 857, 859, 863, 877, 881, 883, 887,907, 911, 919, 929,937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

/*Function prototype*/
void sortInArray(int **arr, int N);
int findPrimeCombi(int **arr, int N);

int main(void)
{
	/* BOJ#11502 */

	int N = 0; // ������� �Է� ���� 
	scanf("%d", &N); // ����� �Է�
	
	int **arr;
	arr = (int **) malloc ( sizeof(int *) * N);
	arr[0] = (int *) malloc ( sizeof(int) * N*4 );
	for( int i=1; i<N; i++){
	arr[i] = arr[ i-1 ] + 4;
	}
	

	for (int i = 0; i<N; i++)
	{/*����ڰ� �Է��ϴ� �Ǵ� ��� �� �迭�� ���� */
		scanf("%d", &arr[i][0]);
		//findPrimeCombi(arr, i);
	}
	
	for (int j = 0; j < N; j++) {
		/*arr�� ���� ��ȸ�ϸ� findPrimeCombi ȣ��*/
		findPrimeCombi(arr, j);
	}
	free(arr[0]);
	free(arr);
	return 0;
}
int findPrimeCombi(int **arr, int N)
{/*���� for ���� 1000���� �Ҽ� �迭�� ��ȸ�ϸ� Ž��*/
	int i, j, k;

	for (i = 0; i<168; i++)
	{
		for (j = 0; j<168; j++)
		{
			for (k = 0; k<168; k++)
			{
				if (arr[N][0] == (prime[i] + prime[j] + prime[k]))
				{/*������ �����ϴ� �Ҽ� �߽߰�*/
					arr[N][1] = prime[i];
					arr[N][2] = prime[j];
					arr[N][3] = prime[k];//arr�� �Ҽ� �� ����
					sortInArray(arr, N);//�迭 ����
 					printf("%d %d %d\n", arr[N][1], arr[N][2], arr[N][3]);
					return 0;
				}
				else if (i == 168 && j == 168 && k == 168)
				{//Ž�� ���н�, 0 ���
					arr[N][1] = 0;
					arr[N][2] = 0;
					arr[N][3] = 0;
					printf("%d\n", 0);
					return 1;
				}
			}
		}
	}

}
void sortInArray(int ** arr, int N)
{/*���� ���ǿ� ���� �������� ���� �Լ�*/
	int temp;
	int i, j;

		for (i = 1; i<3; i++)
		{
			for (j = i + 1; j<4; j++)
			{
				if (arr[N][i]>arr[N][j])
				{
					temp = arr[N][j];
					arr[N][j] = arr[N][i];
					arr[N][i] = temp;

				}
			}
		}
}
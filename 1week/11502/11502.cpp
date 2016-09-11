#include <stdio.h>
#include<stdlib.h>

int prime[168];
void sortInArray(int **arr, int N);
int findPrimeCombi(int **arr, int N);

int main(void)
{
	int tmp[1001] = { 0, }, cnt = 0;
	for (int i = 2; i < 1000; ++i) tmp[i] = 1; // 1�� ������ �������� �Ҽ��� ����
	for (int i = 2; i <= 1000 / 2; ++i) {
		for (int j = 2; j <= 1000 / i; ++j) {
			tmp[i*j] = 0;   // ����� �Ҽ����� ���ܽ�Ŵ
		}
	}
	for (int i = 1; i < 1000; ++i) { // �Ҽ��� p�迭�� ����
		if (tmp[i] == 1) {
			prime[cnt++] = i;
		}
	}

	int N = 0; // ������� �Է� ���� 
	scanf("%d", &N); // ����� �Է�

	int **arr;
	arr = (int **)malloc(sizeof(int *)* N);
	arr[0] = (int *)malloc(sizeof(int)* N * 4);
	for (int i = 1; i<N; i++) {
		arr[i] = arr[i - 1] + 4;
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
					printf("%d %d %d\n", prime[i], prime[j], prime[k]);
					return 0;
				}
				else if (i == 167 && j == 167 && k == 167)
				{//Ž�� ���н�, 0 ���
					printf("%d\n", 0);
					return 1;
				}
			}
		}
	}
}
/*�̰� �� ������ϴ��� ����ߴ�. �������� 
2���� �迭 �����迭 �Ἥ Ǯ��� �׷��µ�,
�Է�->���->�Է�->����� �� ���� Ǯ�� ����̶�� �Ѵ�..
�׷� �ٺ������� 2���� �迭�� �ʿ䰡 ������ �ФФФФФ�
�׸��� �˰����� ������ ��������, ó�� ������ prime �迭�� ���۸��ؼ�
����� �迭�� �� �� �־��µ�, ������ Ǯ������ �ʾƼ� ����... �Ҽ���
�̻��ϴ���...�ᱹ �Ҽ� �������ؼ� prime�� �־��� �� �ȴ�.
201609120222*/
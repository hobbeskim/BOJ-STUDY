#include <stdio.h>
#include<stdlib.h>

int prime[168];
void sortInArray(int **arr, int N);
int findPrimeCombi(int **arr, int N);

int main(void)
{
	int tmp[1001] = { 0, }, cnt = 0;
	for (int i = 2; i < 1000; ++i) tmp[i] = 1; // 1을 제외한 나머지를 소수로 가정
	for (int i = 2; i <= 1000 / 2; ++i) {
		for (int j = 2; j <= 1000 / i; ++j) {
			tmp[i*j] = 0;   // 배수를 소수에서 제외시킴
		}
	}
	for (int i = 1; i < 1000; ++i) { // 소수만 p배열에 저장
		if (tmp[i] == 1) {
			prime[cnt++] = i;
		}
	}

	int N = 0; // 사용자의 입력 변수 
	scanf("%d", &N); // 사용자 입력

	int **arr;
	arr = (int **)malloc(sizeof(int *)* N);
	arr[0] = (int *)malloc(sizeof(int)* N * 4);
	for (int i = 1; i<N; i++) {
		arr[i] = arr[i - 1] + 4;
	}

	for (int i = 0; i<N; i++)
	{/*사용자가 입력하는 판단 대상 수 배열에 넣음 */
		scanf("%d", &arr[i][0]);
		//findPrimeCombi(arr, i);
	}

	for (int j = 0; j < N; j++) {
		/*arr의 행을 순회하며 findPrimeCombi 호출*/
		findPrimeCombi(arr, j);
	}
	free(arr[0]);
	free(arr);
	return 0;
}

int findPrimeCombi(int **arr, int N)
{/*삼중 for 문이 1000이하 소수 배열을 순회하며 탐색*/
	int i, j, k;
	for (i = 0; i<168; i++)
	{
		for (j = 0; j<168; j++)
		{
			for (k = 0; k<168; k++)
			{
				if (arr[N][0] == (prime[i] + prime[j] + prime[k]))
				{/*조건을 만족하는 소수 발견시*/
					printf("%d %d %d\n", prime[i], prime[j], prime[k]);
					return 0;
				}
				else if (i == 167 && j == 167 && k == 167)
				{//탐색 실패시, 0 출력
					printf("%d\n", 0);
					return 1;
				}
			}
		}
	}
}
/*이거 참 디버깅하느라 고생했다. ㅋㅋㅋㅋ 
2차원 배열 동적배열 써서 풀어보고 그랬는데,
입력->출력->입력->출력이 더 좋은 풀이 방법이라고 한다..
그럼 근본적으로 2차원 배열이 필요가 없으니 ㅠㅠㅠㅠㅠㅠ
그리고 알고리즘은 문제가 없었지만, 처음 버전에 prime 배열을 구글링해서
끌어온 배열로 싹 다 넣었는데, 도저히 풀리지가 않아서 보니... 소수가
이상하더라...결국 소수 직접구해서 prime에 넣었고 잘 된다.
201609120222*/
#define MAX 100
#include <stdio.h>
int prime[168] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 197, 199,203, 209, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,601, 607, 613, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,809, 811, 821, 823, 827, 829, 837, 853, 857, 859, 863, 877, 881, 883, 887,907, 911, 919, 929,937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

/*Function prototype*/
void sortInArray(int arr[][4], int N);
int findPrimeCombi(int arr[][4], int N);

int main(int argc, const char * argv[])
{
	/* BOJ#11502 */

	int N = 0; // 사용자의 입력 변수 
	int arr[MAX][4]; // 입력 변수 갯수만큼의 행 사용,1열 정보는 입력 number 2,3,4열 정보는 소수 조합

	scanf("%d", &N); // 사용자 입력

	for (int i = 0; i<N; i++)
	{/*사용자가 입력하는 판단 대상 수 배열에 넣음 */
		scanf("%d", &arr[i][0]);
	}

	for (int j = 0; j<N+1; j++)
	{/*arr의 행을 순회하며 findPrimeCombi 호출*/
		findPrimeCombi(arr, j);
	}

	sortInArray(arr, N);
	
	getchar();
	getchar();

	return 0;
}
int findPrimeCombi(int arr[][4], int N)
{/*삼중 for 문이 1000이하 소수 배열을 순회하며 탐색*/
	int i, j, k;

	for (i = 0; i<168; i++)
	{
		for (j = 0; j<168; j++)
		{
			for (k = 0; k<168; k++)
			{
				if (arr[N - 1][0] == (prime[i] + prime[j] + prime[k]))
				{/*조건을 만족하는 소수 발견시*/
					arr[N - 1][1] = prime[i];
					arr[N - 1][2] = prime[j];
					arr[N - 1][3] = prime[k];//arr에 소수 값 저장
					sortInArray(arr, N-1);//배열 정렬
 					printf("%d %d %d \n", arr[N-1][1], arr[N - 1][2], arr[N - 1][3]);
					return 0;
				}
				else if (i == 168 && j == 168 && k == 168)
				{//탐색 실패시, 0 출력
					arr[N - 1][1] = 0;
					arr[N - 1][2] = 0;
					arr[N - 1][3] = 0;
					printf("%d\n", 0);
					return 1;
				}
			}
		}
	}

}
void sortInArray(int arr[][4], int N)
{/*문제 조건에 따른 오름차순 정렬 함수*/
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
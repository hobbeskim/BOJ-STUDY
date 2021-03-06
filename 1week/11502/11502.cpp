#include <stdio.h>
#include<stdlib.h>

int prime[168];
void sortInArray(int **arr, int N);
int findPrimeCombi(int **arr, int N);

int main(void)
{
	int tmp[1001] = { 0, }, cnt = 0;
	for (int i = 2; i < 1000; ++i) tmp[i] = 1; // 1聖 薦須廃 蟹袴走研 社呪稽 亜舛
	for (int i = 2; i <= 1000 / 2; ++i) {
		for (int j = 2; j <= 1000 / i; ++j) {
			tmp[i*j] = 0;   // 壕呪研 社呪拭辞 薦須獣鉄
		}
	}
	for (int i = 1; i < 1000; ++i) { // 社呪幻 p壕伸拭 煽舌
		if (tmp[i] == 1) {
			prime[cnt++] = i;
		}
	}

	int N = 0; // 紫遂切税 脊径 痕呪 
	scanf("%d", &N); // 紫遂切 脊径

	int **arr;
	arr = (int **)malloc(sizeof(int *)* N);
	arr[0] = (int *)malloc(sizeof(int)* N * 4);
	for (int i = 1; i<N; i++) {
		arr[i] = arr[i - 1] + 4;
	}

	for (int i = 0; i<N; i++)
	{/*紫遂切亜 脊径馬澗 毒舘 企雌 呪 壕伸拭 隔製 */
		scanf("%d", &arr[i][0]);
		//findPrimeCombi(arr, i);
	}

	for (int j = 0; j < N; j++) {
		/*arr税 楳聖 授噺馬悟 findPrimeCombi 硲窒*/
		findPrimeCombi(arr, j);
	}
	free(arr[0]);
	free(arr);
	return 0;
}

int findPrimeCombi(int **arr, int N)
{/*誌掻 for 庚戚 1000戚馬 社呪 壕伸聖 授噺馬悟 貼事*/
	int i, j, k;
	for (i = 0; i<168; i++)
	{
		for (j = 0; j<168; j++)
		{
			for (k = 0; k<168; k++)
			{
				if (arr[N][0] == (prime[i] + prime[j] + prime[k]))
				{/*繕闇聖 幻膳馬澗 社呪 降胃獣*/
					printf("%d %d %d\n", prime[i], prime[j], prime[k]);
					return 0;
				}
				else if (i == 167 && j == 167 && k == 167)
				{//貼事 叔鳶獣, 0 窒径
					printf("%d\n", 0);
					return 1;
				}
			}
		}
	}
}
/*戚暗 凧 巨獄焔馬汗虞 壱持梅陥. せせせせ 
2託据 壕伸 疑旋壕伸 潤辞 熱嬢左壱 益隈澗汽,
脊径->窒径->脊径->窒径戚 希 疏精 熱戚 号狛戚虞壱 廃陥..
益軍 悦沙旋生稽 2託据 壕伸戚 琶推亜 蒸生艦 ばばばばばば
益軒壱 硝壱軒葬精 庚薦亜 蒸醸走幻, 坦製 獄穿拭 prime 壕伸聖 姥越元背辞
怪嬢紳 壕伸稽 熟 陥 隔醸澗汽, 亀煽備 熱軒走亜 省焼辞 左艦... 社呪亜
戚雌馬希虞...衣厩 社呪 送羨姥背辞 prime拭 隔醸壱 設 吉陥.
201609120222*/
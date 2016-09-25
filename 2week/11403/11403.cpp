#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Function prototype*/
int ** graphMultiplier(int N, int ** A, int **B);

int main()
{
	int numOfNode = 0;

	/*N 정방행렬의 공간 생성을 위한 이중포인터*/
	int **graphMatrix;
	int **outGraphMatrix;
	int **interGraphMatrix;

	/*N을 입력받음*/
	scanf_s("%d", &numOfNode);

	/*(입력값) graphMatrix를 사용자의 입력에 따라 동적 생성 및 초기화*/
	graphMatrix = (int**)malloc(sizeof(int*)*numOfNode);
	graphMatrix[0] = (int*)malloc(sizeof(int*)*numOfNode*numOfNode);
	for (int i = 1; i < numOfNode; i++)
	{
		graphMatrix[i] = graphMatrix[i - 1] + numOfNode;
	}
	for (int i = 0; i < numOfNode; i++)
	{
		for (int j = 0; j < numOfNode; j++)
		{
			graphMatrix[i][j] = 0;
		}
	}
	/*(출력값) outgraphMatrix를 N에 따라 동적 생성 및 초기화*/
	outGraphMatrix = (int**)malloc(sizeof(int*)*numOfNode);
	outGraphMatrix[0] = (int*)malloc(sizeof(int*)*numOfNode*numOfNode);
	for (int i = 1; i < numOfNode; i++)
	{
		outGraphMatrix[i] = outGraphMatrix[i - 1] + numOfNode;
	}
	for (int i = 0; i < numOfNode; i++)
	{
		for (int j = 0; j < numOfNode; j++)
		{
			outGraphMatrix[i][j] = 0;
		}
	}

	/*graphMatrix에 인접행렬 정보를 입력 받음.*/
	for (int i = 0; i < numOfNode; i++)
	{
		for (int j = 0; j < numOfNode; j++)
		{
			scanf_s("%d", &graphMatrix[i][j]);
		}
	}

	/*행렬^X 승을 잠시 저장할 interGraphMatrix 생성 및 초기 입력 값 전달*/
	interGraphMatrix = (int**)malloc(sizeof(int*)*numOfNode);
	interGraphMatrix[0] = (int*)malloc(sizeof(int*)*numOfNode*numOfNode);
	for (int i = 1; i < numOfNode; i++)
	{
		interGraphMatrix[i] = interGraphMatrix[i - 1] + numOfNode;
	}
	for (int i = 0; i < numOfNode; i++)
	{
		for (int j = 0; j < numOfNode; j++)
		{
			interGraphMatrix[i][j] = graphMatrix[i][j];
		}
	}

	/************************************* 이 부분이 이 문제의 핵심**********************************/
	for (int i = 0; i < numOfNode; i++)
	{
		/*interGraphMatrix의 행,열 값을 outGraphMatrix에 저장 A^(i+1)*/
		for (int j = 0; j < numOfNode; j++)
		{
			for (int l = 0; l < numOfNode; l++)
			{
				outGraphMatrix[j][l] += interGraphMatrix[j][l];
			}
		}

		/*interGraphMatrix의 원 배열을 곱해줌 A^(i+2)*/
		interGraphMatrix = graphMultiplier(numOfNode, interGraphMatrix, graphMatrix);
	}

	/*값 출력, 만약 경우의 수가 많아 행렬의 값이 1보다 클 경우 1로 만들어줌*/
	for (int i = 0; i < numOfNode; i++)
	{
		for (int j = 0; j < numOfNode; j++)
		{
			if (outGraphMatrix[i][j] != 0)
				outGraphMatrix[i][j] = 1;
			printf("%d ", outGraphMatrix[i][j]);
		}
		printf("\n");
	}



	/*동적할당되었던 메모리 반환!*/
	free(graphMatrix[0]);
	free(graphMatrix);


	/*동적할당되었던 메모리 반환!*/
	free(interGraphMatrix[0]);
	free(interGraphMatrix);


	/*동적할당되었던 메모리 반환!*/
	free(outGraphMatrix[0]);
	free(outGraphMatrix);

	return 0;
}

/*NbyN 정방 행렬의 곱 행렬을 구하기 위한 함수*/
int ** graphMultiplier(int N, int ** A, int ** B)
{

	/* 곱 행렬의 정보를 저장한 새 행렬을 생성하고 초기화 합니다.*/
	int ** newGraphMatrix;
	newGraphMatrix = (int**)malloc(sizeof(int*)*N);
	newGraphMatrix[0] = (int*)malloc(sizeof(int*)*N*N);
	for (int i = 1; i < N; i++)
	{
		newGraphMatrix[i] = newGraphMatrix[i - 1] + N;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			newGraphMatrix[i][j] = 0;
		}
	}

	/*행렬의 곱을 구하는 과정 3중 for문 사용 */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				newGraphMatrix[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return newGraphMatrix;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Function prototype*/
int ** graphMultiplier(int N, int ** A, int **B);

int main()
{
	int numOfNode = 0;

	/*N ��������� ���� ������ ���� ����������*/
	int **graphMatrix;
	int **outGraphMatrix;
	int **interGraphMatrix;

	/*N�� �Է¹���*/
	scanf_s("%d", &numOfNode);

	/*(�Է°�) graphMatrix�� ������� �Է¿� ���� ���� ���� �� �ʱ�ȭ*/
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
	/*(��°�) outgraphMatrix�� N�� ���� ���� ���� �� �ʱ�ȭ*/
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

	/*graphMatrix�� ������� ������ �Է� ����.*/
	for (int i = 0; i < numOfNode; i++)
	{
		for (int j = 0; j < numOfNode; j++)
		{
			scanf_s("%d", &graphMatrix[i][j]);
		}
	}

	/*���^X ���� ��� ������ interGraphMatrix ���� �� �ʱ� �Է� �� ����*/
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

	/************************************* �� �κ��� �� ������ �ٽ�**********************************/
	for (int i = 0; i < numOfNode; i++)
	{
		/*interGraphMatrix�� ��,�� ���� outGraphMatrix�� ���� A^(i+1)*/
		for (int j = 0; j < numOfNode; j++)
		{
			for (int l = 0; l < numOfNode; l++)
			{
				outGraphMatrix[j][l] += interGraphMatrix[j][l];
			}
		}

		/*interGraphMatrix�� �� �迭�� ������ A^(i+2)*/
		interGraphMatrix = graphMultiplier(numOfNode, interGraphMatrix, graphMatrix);
	}

	/*�� ���, ���� ����� ���� ���� ����� ���� 1���� Ŭ ��� 1�� �������*/
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



	/*�����Ҵ�Ǿ��� �޸� ��ȯ!*/
	free(graphMatrix[0]);
	free(graphMatrix);


	/*�����Ҵ�Ǿ��� �޸� ��ȯ!*/
	free(interGraphMatrix[0]);
	free(interGraphMatrix);


	/*�����Ҵ�Ǿ��� �޸� ��ȯ!*/
	free(outGraphMatrix[0]);
	free(outGraphMatrix);

	return 0;
}

/*NbyN ���� ����� �� ����� ���ϱ� ���� �Լ�*/
int ** graphMultiplier(int N, int ** A, int ** B)
{

	/* �� ����� ������ ������ �� ����� �����ϰ� �ʱ�ȭ �մϴ�.*/
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

	/*����� ���� ���ϴ� ���� 3�� for�� ��� */
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

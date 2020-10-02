#include "IntQueue.h"
#include <stdio.h>
#include <stdlib.h>

int InitQueue(IntQueue* qp, int nMaxCapacity)
{
	qp->nElement = 0;
	qp->nFrontIdx = 0;
	qp->nRearIdx = 0;
	qp->pnQue = calloc(nMaxCapacity, sizeof(int));
	if (qp->pnQue == NULL)
	{
		qp->nMaxCapacity = 0;
		return 1;
	}
	qp->nMaxCapacity = nMaxCapacity;
	return 0;
}

int EnQueue(IntQueue* qp, int nData)
{
	if (IsQueueFull(qp))
		qp->nFrontIdx = (qp->nFrontIdx + 1) % qp->nMaxCapacity;
	else
		qp->nElement++;
	qp->pnQue[qp->nRearIdx++] = nData;
	qp->nRearIdx %= qp->nMaxCapacity;
	return 0;
}

int DeQueue(IntQueue* qp, int* pnData)
{
	if (IsQueueEmpty(qp))
		return 1;
	else
	{
		qp->nElement--;
		*pnData = qp->pnQue[qp->nFrontIdx++];
		qp->nFrontIdx %= qp->nMaxCapacity;
		return 0;
	}
}

int PeekQueue(const IntQueue* qp, int* pnData)
{
	if (IsQueueEmpty(qp))
		return 1;
	else
	{
		*pnData = qp->pnQue[qp->nFrontIdx];
		return 0;
	}
}

int SearchQueue(const IntQueue* qp, int x)
{
	int idx = 0;
	for (int i = 0; i < qp->nElement; i++)
	{
		idx = (qp->nFrontIdx + i) % qp->nMaxCapacity;
		if (qp->pnQue[idx] == x)
			return idx;
	}
	return -1;
}

void ClearQueue(IntQueue* qp)
{
	qp->nElement = 0;
	qp->nFrontIdx = 0;
	qp->nRearIdx = 0;
	for (int i = 0; i < qp->nMaxCapacity; i++)
	{
		qp->pnQue[i] = 0;
	}
}

void PrintQueue(const IntQueue* qp)
{
	printf("MaxCapacity: %d, nElement: %d, nFrontIdx: %d, nRearIdx: %d\n", qp->nMaxCapacity, qp->nElement, qp->nFrontIdx, qp->nRearIdx);
	int nIdx = 0;
	if (qp->nElement)
	{
		printf("Queue: ");
		for (int i = 0; i < qp->nElement; i++)
		{
			nIdx = (i + qp->nFrontIdx) % qp->nMaxCapacity;
			printf("%d ", qp->pnQue[nIdx]);
		}
		printf("\n");

		printf("Array: ");
		for (int i = 0; i < qp->nMaxCapacity; i++)
		{
			printf("%d ", qp->pnQue[i]);
		}
		printf("\n");
	}
}

int QueueCapacity(const IntQueue* qp)
{
	return qp->nMaxCapacity;
}

int QueueNumberOfElement(const IntQueue* qp)
{
	return qp->nElement;
}

int IsQueueEmpty(const IntQueue* qp)
{
	return qp->nElement == 0;
}

int IsQueueFull(const IntQueue* qp)
{
	return qp->nElement >= qp->nMaxCapacity;
}

void DestroyQueue(IntQueue* qp)
{
	ClearQueue(qp);
	if (qp->pnQue != NULL)
		free(qp->pnQue);
}
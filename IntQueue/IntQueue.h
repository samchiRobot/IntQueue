#ifndef __INTQUEUE_H__
#define __INTQUEUE_H__

typedef struct
{
	int nMaxCapacity;
	int nElement;
	int nFrontIdx;
	int nRearIdx;
	int* pnQue;
}IntQueue;

int InitQueue(IntQueue* qp, int nMaxCapacity);
int EnQueue(IntQueue* qp, int nData);
int DeQueue(IntQueue* qp, int *pnData);
int PeekQueue(const IntQueue* qp, int* pnData);
int SearchQueue(const IntQueue* qp, int x);
void ClearQueue(IntQueue* qp);
void PrintQueue(const IntQueue* qp);

int QueueCapacity(const IntQueue* qp);
int QueueNumberOfElement(const IntQueue* qp);
int IsQueueEmpty(const IntQueue* qp);
int IsQueueFull(const IntQueue* qp);

void DestroyQueue(IntQueue* qp);

#endif
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "IntQueue.h"

#define MAX_QUEUE_SIZE	(32)

int Menu(const IntQueue* qp);

enum eMenuTable
{
	kMenuExit,
	kMenuEnqueue,
	kMenuDequque,
	kMenuPeek,
	kMenuSearch,
	kMenuPrint,
	kMenuClear
};

int main(void)
{
	IntQueue q;
	IntQueue* qp = &q;
	int ret = 0;
	int nMenu = 0;
	int temp = 0;

	if (InitQueue(qp, MAX_QUEUE_SIZE) == 1)
	{
		perror("Failed to initailize queue!\n");
		return 1;
	}
	printf("Initialized!\n");
	PrintQueue(qp);

	while (1)
	{
		nMenu = Menu(qp);
		if (nMenu == kMenuExit)
		{
			printf("Exiting....\n");
			break;
		}

		switch (nMenu)
		{
		case kMenuEnqueue:
			printf("Enque Data: ");
			scanf("%d", &temp);
			if (EnQueue(qp, temp))
				printf("Enqueue Failed! (queue is full)\n");
			else
				printf("Enqueue OK\n");
			break;
		case kMenuDequque:
			if (DeQueue(qp, &temp))
				printf("Dequeue Failed! (queue is empty)\n");
			else
				printf("Dequeue OK, Data: %d\n", temp);
			break;
		case kMenuPeek:
			if (PeekQueue(qp, &temp))
				printf("Peek Failed! (queue is empty)\n");
			else
				printf("Peek OK, Data: %d\n", temp);
			break;
		case kMenuSearch:
			printf("Search Data: ");
			scanf("%d", &temp);
			if (SearchQueue(qp, temp) == -1)
				printf("Data %d not found!\n", temp);
			else
				printf("Data %d found! Array Idx: %d\n", temp, SearchQueue(qp, temp));
			break;
		case kMenuPrint:
			PrintQueue(qp);
			break;
		case kMenuClear:
			ClearQueue(qp);
			printf("Clear OK\n");
			break;
		default:
			break;
		}
	}
	DestroyQueue(qp);
	return 0;
}

int Menu(const IntQueue* qp)
{
	int nMenu = 0;
	while (1)
	{
		printf("\nQueue Status : %d/%d\n", qp->nElement, qp->nMaxCapacity);
		printf("1.Enqueue 2.Dequeue 3.Peek 4.Search 5.Print 6.Clear 0.Exit: ");
		scanf("%d", &nMenu);
		if (nMenu >= kMenuExit && nMenu <= kMenuClear)
			break;
		else
			printf("Invalid menu!\n");
	}
	return nMenu;
}
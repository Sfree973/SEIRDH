#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"head.h"
void BubbleSort(int ID) {
	pfirst = personNode[ID]->Neighbor;
	pend = NULL;
	while (pfirst!=pend) //
	{
		while (pfirst->next!= pend)
		{
			if ((personNode[pfirst->ID]->active) < (personNode[pfirst->next->ID]->active))
			{
				int temp = pfirst->ID;
				pfirst->ID = pfirst->next->ID; 
				pfirst->next->ID=temp; 
			}
			pfirst = pfirst->next;
		}
		pend = pfirst;
		pfirst= personNode[ID]->Neighbor;
	}
}


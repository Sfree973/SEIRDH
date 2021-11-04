#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"head.h"
void initNeighbor()
{
	for (i = 1; i <= N; i++)
	{
		personNode[i]->Neighbor = NULL;
	}
}
void freeNeighbor()
{
	for (i = 1; i <= N; i++)
	{
		p2 = personNode[i]->Neighbor;
		while (p2)
		{
			s2 = p2->next;
			free(p2);
			p2= s2;
		}
	}
}
void becomeNeighbor2(int ID, int toId)
{
	if (ID != toId) {
		p2 = (neighborList2 *)malloc(sizeof(neighborList2));
		p2->ID = toId;
		p2->next = personNode[ID]->Neighbor;
		personNode[ID]->Neighbor = p2;
	}
}
void readBian2(int fromId, int toId) {
	int flag1 = 0, flag2 = 0;
	int fromIdXiaBiao, toIdXiaBiao;
	for (j = 1; j <= N; j++) {
		if (personNode[j]->ID == fromId) {
			fromIdXiaBiao = j;
			flag1 = 1;
		}
		if (personNode[j]->ID == toId) {
			toIdXiaBiao = j;
			flag2 = 1;
		}
		if (flag1 && flag2)
		{
			if (isAlreadyNeighbor(fromIdXiaBiao, toIdXiaBiao)) {
				break;
			}
			else
			{
				becomeNeighbor2(fromIdXiaBiao, toIdXiaBiao);
				becomeNeighbor2(toIdXiaBiao, fromIdXiaBiao);
				break;
			}
		}
	}
}

int isAlreadyNeighbor(int ID, int toID) 
{
	p2 = personNode[ID]->Neighbor;
	while (p2 && p2->ID != toID)
	{
		p2 = p2->next;
	}
	if (!p2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void dataDrivenModel2() {
	startTime2 = bian[0]->timeStamp;
	int Q = 1;
	for (i = 0; i < B; i++) {	
		currentTimeStamp2 = bian[i]->timeStamp;
		if (startTime2 <= currentTimeStamp2 && currentTimeStamp2 < (startTime2 + interTime))
		{
			bian[i]->f = Q;
			continue;
		}
		startTime2 = currentTimeStamp2;
		Q++;
	}
}
void dataDrivenModel3(int D) {
	for (dege = 0; dege < B; dege++) {
		if (F == 1 && bian[dege]->f == F)
		{
			readBian2(bian[dege]->fromId, bian[dege]->toId);
		}
		else if (F == 2 && (bian[dege]->f == 1 || bian[dege]->f == 2))
		{
			readBian2(bian[dege]->fromId, bian[dege]->toId);
		}
		else if (F > 2 && (bian[dege]->f == (F - 2) || bian[dege]->f == (F - 1) || bian[dege]->f == F))
		{
			readBian2(bian[dege]->fromId, bian[dege]->toId);
		}
	}
}

int NeighborOfNode(int ID) {

	kkk = 0;
	p2 = personNode[ID]->Neighbor;
	while (p2)
	{
		kkk++;
		p2 = p2->next;
	}
	return kkk;
}
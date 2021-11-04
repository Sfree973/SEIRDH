#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"head.h"
void epidemicProcess(int F) {
	for (i = 1; i <= N; i++) {
		changeInfectState(i,F);
 	}
}
void updateInfectState() {
	for (i = 1; i <= N; i++) {
		personNode[i]->oldinfectState = personNode[i]->infectState;
	}
}
void changeInfectState(int ID,int F) {    
	dataDrivenModel3(F);
	Number = NeighborOfNode(ID);
	if (personNode[ID]->oldinfectState == 3 ) {
		randomNumber = rand() / (double)(RAND_MAX);
		if (randomNumber<alpha) {
			personNode[ID]->infectState = 8;
			BubbleSort(ID);
			p2 = personNode[ID]->Neighbor;
			double M =0;
			int number = 0;
			M = (Number * delta); 
			personNode[ID]->TNumber = M;
			while (p2)
			{
				if ((personNode[p2->ID]->oldinfectState == 1) && (personNode[p2->ID]->Flag == 0)) {
					personNode[p2->ID]->Flag = 1;
					if (number < personNode[ID]->TNumber)
					{
						personNode[p2->ID]->infectState = 6;
						number++;
					}
					else
					{
						numberOfInfectNeighbor = 0;
						p3 = personNode[p2->ID]->currentNeighbor;
						while (p3)
						{
							if (personNode[p3->ID]->oldinfectState == 3 || personNode[p3->ID]->oldinfectState == 2) {
								numberOfInfectNeighbor++;
							}
							p3 = p3->next;
						}
						randomNumber = rand() / (double)(RAND_MAX);
						if (randomNumber < (1 - pow(1 - lambdaInfect, numberOfInfectNeighbor))) {
							personNode[p2->ID]->infectState = 2;
						}
					}
				}
				else if ((personNode[p2->ID]->oldinfectState == 2) && (personNode[p2->ID]->Flag == 0)) {
					personNode[p2->ID]->Flag = 1;
					if (number < personNode[ID]->TNumber)
					{
						personNode[p2->ID]->infectState = 7;
						number++;
					}
					else
					{
						randomNumber = rand() / (double)(RAND_MAX);
						if (randomNumber < beta)
						{
							personNode[p2->ID]->infectState = 3;
						}
					}
					p3 = personNode[p2->ID]->currentNeighbor;
					while (p3)
					{
						if ((personNode[p3->ID]->oldinfectState == 1) && (personNode[p3->ID]->Flag == 0)) {
							personNode[p3->ID]->Flag = 1;
							p4 = personNode[p3->ID]->currentNeighbor;
							numberOfInfectNeighbor = 0;
							while (p4) {
								if ((personNode[p4->ID]->oldinfectState == 3) || (personNode[p4->ID]->oldinfectState == 2)) {
									numberOfInfectNeighbor++;
								}
								p4 = p4->next;
							}
							randomNumber = rand() / (double)(RAND_MAX);
							if (randomNumber < (1 - pow(1 - lambdaInfect, numberOfInfectNeighbor))) {
								personNode[p3->ID]->infectState = 2;
							}
						}
						p3 = p3->next;
					}
				}
				p2 = p2->next;
			}
		}
		else {
			randomNumber = rand() / (double)(RAND_MAX);
			if (randomNumber < mu) {
				personNode[ID]->infectState = 4;
			}
			else if ((randomNumber > mu) && (randomNumber < (mu + d))) {
				personNode[ID]->infectState = 5;
			}
			else
			{
				personNode[ID]->infectState = 3;
			}
			p = personNode[ID]->currentNeighbor;
			while (p)
			{
				if ((personNode[p->ID]->oldinfectState == 1) && (personNode[p->ID]->Flag == 0)) {
					personNode[p->ID]->Flag = 1;
					numberOfInfectNeighbor = 0;
					p1 = personNode[p->ID]->currentNeighbor;
					while (p1)
					{
						if (personNode[p1->ID]->oldinfectState == 3 || personNode[p1->ID]->oldinfectState == 2) {
							numberOfInfectNeighbor++;
						}

						p1 = p1->next;
					}
					randomNumber = rand() / (double)(RAND_MAX);
					if (randomNumber < (1 - pow(1 - lambdaInfect, numberOfInfectNeighbor))) {
						personNode[p->ID]->infectState = 2;
					}
				}
				else if ((personNode[p->ID]->oldinfectState == 2) && (personNode[p->ID]->Flag == 0)) {
					personNode[p->ID]->Flag = 1;
					randomNumber = rand() / (double)(RAND_MAX);
					if (randomNumber < beta)
					{
						personNode[p->ID]->infectState = 3;
					}
					p1 = personNode[p->ID]->currentNeighbor;
					while (p1)
					{
						if ((personNode[p1->ID]->oldinfectState == 1) && (personNode[p1->ID]->Flag == 0)) {
							personNode[p1->ID]->Flag = 1;
							p5 = personNode[p1->ID]->currentNeighbor;
							numberOfInfectNeighbor = 0;
							while (p5) {
								if (personNode[p5->ID]->oldinfectState == 3 || personNode[p5->ID]->oldinfectState == 2) {
									numberOfInfectNeighbor++;
								}
								p5 = p5->next;
							}
							randomNumber = rand() / (double)(RAND_MAX);
							if (randomNumber < (1 - pow(1 - lambdaInfect, numberOfInfectNeighbor))) {
								personNode[p1->ID]->infectState = 2;
							}
						}
						p1 = p1->next;
					}
				}
				p = p->next;
			}
		}
	}
	else if ((personNode[ID]->oldinfectState == 2) && (personNode[ID]->Flag == 0)) {
		randomNumber = rand() / (double)(RAND_MAX);
		if (randomNumber < beta)
		{
			personNode[ID]->infectState = 3;
		}
		p= personNode[ID]->currentNeighbor;
		while (p)
		{
			if ((personNode[p->ID]->oldinfectState == 1) && (personNode[p->ID]->Flag == 0)) {
				personNode[p->ID]->Flag = 1;
				numberOfInfectNeighbor = 0;
				p1 = personNode[p->ID]->currentNeighbor;
				while (p1)
				{
					if (personNode[p1->ID]->oldinfectState == 3 || personNode[p1->ID]->oldinfectState == 2) {
						numberOfInfectNeighbor++;
					}

					p1 = p1->next;
				}
				randomNumber = rand() / (double)(RAND_MAX);
				if (randomNumber < (1 - pow(1 - lambdaInfect, numberOfInfectNeighbor))) {
					personNode[p->ID]->infectState = 2;
				}
			}
			p = p->next;
		}
	}
	else if (personNode[ID]->oldinfectState == 6) {
		randomNumber = rand() / (double)(RAND_MAX);
		if (randomNumber < tau)
		{
			personNode[ID]->infectState = 1;
		}
	}
	else if (personNode[ID]->oldinfectState == 7) {
		if (randomNumber < beta) {
			personNode[ID]->infectState = 8;
		}
		else if ((randomNumber > beta) && (randomNumber < (tau + beta))) {
			personNode[ID]->infectState = 2;
		}
		else
		{
			personNode[ID]->infectState = 7;
		}
	}
	else if (personNode[ID]->oldinfectState == 8) {
		randomNumber = rand() / (double)(RAND_MAX);
		if (randomNumber < omega)
		{
			personNode[ID]->infectState = 9;
		}
	}
	else if (personNode[ID]->oldinfectState == 9) {
		if (randomNumber < K) {
			personNode[ID]->infectState = 4;
		}
		else if ((randomNumber > K) && (randomNumber < (K + chi))) {
			personNode[ID]->infectState = 5;
		}
		else
		{
			personNode[ID]->infectState = 9;
		}
	}
}

void initialAllAgentInfectState() {
	for (i = 1; i <= N; i++) {
		personNode[i]->infectState = 1;
	}

}
void initialAllAgentFlag() {
	for (i = 1; i <= N; i++) {
		personNode[i]->Flag = 0;
	}

}

void initialAllAgentTNumber() {
	for (i = 1; i <= N; i++) {
		personNode[i]->TNumber = 0;
	}

}

void infectFractionSeeds() {
	BeSelectedInfectSeedsHead = (struct BeSelectedID *)malloc(sizeof(struct BeSelectedID));
	BeSelectedInfectSeedsHead->next = NULL;
	k = 0;
	while (k < infectSeeds*N)
	{
		selectRandnumber = rand() % N+1;

		ppp = BeSelectedInfectSeedsHead->next;
		while (ppp && ppp->ID != selectRandnumber)
		{
			ppp = ppp->next;
		}
		if (!ppp) {
			sss = (struct BeSelectedID *)malloc(sizeof(struct BeSelectedID));
			sss->ID = selectRandnumber;
			sss->next = BeSelectedInfectSeedsHead->next;
			BeSelectedInfectSeedsHead->next = sss;
			personNode[selectRandnumber]->infectState = 3;
			k++;
		}
		else
		{
			continue;
		}

	}

	freeBeSelectedInfectSeedsBiao();
}
void freeBeSelectedInfectSeedsBiao() {
	ppp = BeSelectedInfectSeedsHead->next;
	while (ppp)
	{
		qqq = ppp->next;
		free(ppp);
		ppp = qqq;
	}
	free(BeSelectedInfectSeedsHead);
}
double computeRstateDensity() {
	sumInfectNumber = 0;
	for (i = 1; i <=N; i++)
	{
		if (personNode[i]->infectState == 4) {
			sumInfectNumber++;
		}
	}

	RstateDensity = sumInfectNumber / (double)N;
	return RstateDensity;
}
double computeDstateDensity() {
	sumInfectNumber = 0;
	for (i = 1; i <= N; i++)
	{
		if (personNode[i]->infectState == 5) {
			sumInfectNumber++;
		}
	}

	DstateDensity = sumInfectNumber / (double)N;
	return DstateDensity;
}
void initialRstateandlambdaLianbiao() {
	RstateandlambdaHead = (struct recordRstateandlambda *)malloc(sizeof(struct recordRstateandlambda));
	if (RstateandlambdaHead == NULL) {
		printf("RstateandlambdaHead�����ڴ�ʧ��\n");
	}
	RstateandlambdaHead->next = NULL;
}
void initialDstateandlambdaLianbiao() {
	DstateandlambdaHead = (struct recordDstateandlambda *)malloc(sizeof(struct recordDstateandlambda));
	if (DstateandlambdaHead == NULL) {
		printf("DstateandlambdaHead�����ڴ�ʧ��\n");
	}
	DstateandlambdaHead->next = NULL;
}
void initialAVERstateandlambdaHead() {
	AVERstateandlambdaHead = (struct recordRstateandlambda *)malloc(sizeof(struct recordRstateandlambda));
	AVERstateandlambdaHead->next = NULL;
}

void initialAVEDstateandlambdaHead() {
	AVEDstateandlambdaHead = (struct recordDstateandlambda *)malloc(sizeof(struct recordDstateandlambda));
	AVEDstateandlambdaHead->next = NULL;
}
void insertRstateandlambdaDensity(double lambdaValue, double RDensityValue, int ave) {

	ssss = (struct recordRstateandlambda *)malloc(sizeof(struct recordRstateandlambda));
	ssss->lambda = lambdaValue;
	ssss->Rdensity = RDensityValue;
	ssss->next = RstateandlambdaHead->next;
	RstateandlambdaHead->next = ssss;

}
void insertDstateandlambdaDensity(double lambdaValue, double DDensityValue, int ave) {

	sssss = (struct recordDstateandlambda *)malloc(sizeof(struct recordDstateandlambda));
	sssss->lambda = lambdaValue;
	sssss->Ddensity = DDensityValue;
	sssss->next = DstateandlambdaHead->next;
	DstateandlambdaHead->next = sssss;

}
void insertAVERstateandlambda() {

	sumRstateDensity = 0;
	pppp = RstateandlambdaHead->next;
	ssss = (struct recordRstateandlambda *)malloc(sizeof(struct recordRstateandlambda));
	ssss->lambda = pppp->lambda;

	while (pppp)
	{
		sumRstateDensity += pppp->Rdensity;
		pppp = pppp->next;
	}


	ssss->Rdensity = sumRstateDensity / (double)AVE;

	printf("lambdaȡֵΪ%lfʱ,��ƽ��%d��R̬��Ⱦ�ܶ�Ϊ��%lf\n", ssss->lambda, AVE, ssss->Rdensity);

	ssss->next = AVERstateandlambdaHead->next;
	AVERstateandlambdaHead->next = ssss;
}
void insertAVEDstateandlambda() {

	sumDstateDensity = 0;
	ppppp = DstateandlambdaHead->next;

	sssss = (struct recordDstateandlambda *)malloc(sizeof(struct recordDstateandlambda));
	sssss->lambda = ppppp->lambda;

	while (ppppp)
	{
		sumDstateDensity += ppppp->Ddensity;
		ppppp = ppppp->next;
	}


	sssss->Ddensity = sumDstateDensity / (double)AVE;

	printf("lambdaȡֵΪ%lfʱ,��ƽ��%d��D̬��Ⱦ�ܶ�Ϊ��%lf\n", sssss->lambda, AVE, sssss->Ddensity);

	sssss->next = AVEDstateandlambdaHead->next;
	AVEDstateandlambdaHead->next = sssss;
}
void freeAVERstateandlambdaBiao() {
	pppp = AVERstateandlambdaHead->next;
	while (pppp)
	{
		qqqq = pppp->next;
		free(pppp);
		pppp = qqqq;
	}
	free(AVERstateandlambdaHead);
	free(ssss);
}
void freeAVEDstateandlambdaBiao() {
	ppppp = DstateandlambdaHead->next;
	while (ppppp)
	{
		qqqqq = ppppp->next;
		free(ppppp);
		ppppp = qqqqq;
	}
	free(AVEDstateandlambdaHead);
	free(sssss);
}
void freeRstateandlambdaBiao() {
	pppp = RstateandlambdaHead->next;
	while (pppp)
	{
		qqqq = pppp->next;
		free(pppp);
		pppp = qqqq;
	}
	free(RstateandlambdaHead);
}
void freeDstateandlambdaBiao() {
	ppppp = DstateandlambdaHead->next;
	while (ppppp)
	{
		qqqqq = ppppp->next;
		free(ppppp);
		ppppp = qqqqq;
	}
	free(DstateandlambdaHead);
}
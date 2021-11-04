#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"head.h"
void epidemicProcess()
{
	for (t = 1; t <= step; t++) {
		fireAllAgent();
		initialCurrentNeighbor();
		initialAllAgentFlag();
		
		updateInfectState();
		for (i = 0; i < N; i++) {
			if (personNode[i]->activeState == 1) {

				if (personNode[i]->active > 1) {
					integerPart = (int)(personNode[i]->active);
					decimalPart = personNode[i]->active - integerPart;
					randomNumber = rand() / (double)(RAND_MAX);

					if (randomNumber < decimalPart) {
						selectNodeToContact(i, (integerPart + 1)*m);
					}
					else
					{
						selectNodeToContact(i, integerPart*m);
					}
				}
				else
				{
					selectNodeToContact(i, m);
				}

			}

		}
		
		for (i = 0; i < N; i++) {
			changeInfectState(i);
		}

		computeRstateDensity();
		computeDstateDensity();
		freeCurrentNeighbor();

	}

}
void initialAllAgentInfectState() {

	for (i = 0; i < N; i++) {
		personNode[i]->infectState = 1;
	}

}
void initialAllAgentFlag() {

	for (i = 0; i < N; i++) {
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
		selectRandnumber = rand() % N;
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

void updateInfectState() {
	for ( i = 0; i < N; i++)
	{
		personNode[i]->oldinfectState = personNode[i]->infectState;
	}

}

void changeInfectState(int ID) {
	Number = currentNeighborOfNode(ID);
	if (personNode[ID]->oldinfectState == 3) {
		randomNumber = rand() / (double)(RAND_MAX);
		if (randomNumber < alpha) {
			personNode[ID]->infectState = 8;
			BubbleSort(ID);
			double M = 0;
			int number = 0;
			M = (Number * delta);
			personNode[ID]->TNumber = M;
			p = personNode[ID]->currentNeighbor;
			while (p)
			{
				if ((personNode[p->ID]->oldinfectState == 1) && (personNode[p->ID]->Flag == 0)) {
					personNode[p->ID]->Flag = 1;
					randomNumber = rand() / (double)(RAND_MAX);
					if (number < personNode[ID]->TNumber)
					{
						personNode[p->ID]->infectState = 6;
						number++;
					}
					else
					{
						numberOfInfectNeighbor = 0;
						p1 = personNode[p->ID]->currentNeighbor;
						while (p1)
						{
							if ((personNode[p1->ID]->oldinfectState == 3) || (personNode[p1->ID]->oldinfectState == 2)) {
								numberOfInfectNeighbor++;
							}
							p1 = p1->next;
						}
						randomNumber = rand() / (double)(RAND_MAX);
						if (randomNumber < (1 - pow(1 - lambdaInfect, numberOfInfectNeighbor))) {
							personNode[p->ID]->infectState = 2;
						}
					}
				}
				else if ((personNode[p->ID]->oldinfectState == 2) && (personNode[p->ID]->Flag == 0)) {
					personNode[p->ID]->Flag = 1;
					randomNumber = rand() / (double)(RAND_MAX);
					if (number < personNode[ID]->TNumber)
					{
						personNode[p->ID]->infectState = 7;
						number++;
					}
					else
					{
						randomNumber = rand() / (double)(RAND_MAX);
						if (randomNumber < beta)
						{
							personNode[p->ID]->infectState = 3;
						}
					}
					p1 = personNode[p->ID]->currentNeighbor;
					while (p1) {
						if ((personNode[p1->ID]->oldinfectState == 1) && (personNode[p1->ID]->Flag == 0)) {
							personNode[p1->ID]->Flag = 1;
							numberOfInfectNeighbor = 0;
							p2 = personNode[p1->ID]->currentNeighbor;
							while (p2)
							{
								if ((personNode[p2->ID]->oldinfectState == 3) || (personNode[p2->ID]->oldinfectState == 2)) {
									numberOfInfectNeighbor++;
								}
								p2 = p2->next;
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
						if ((personNode[p1->ID]->oldinfectState == 3) || (personNode[p1->ID]->oldinfectState == 2)) {
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
					while (p1) {
						if ((personNode[p1->ID]->oldinfectState == 1) && (personNode[p1->ID]->Flag == 0)) {
							personNode[p1->ID]->Flag = 1;
							numberOfInfectNeighbor = 0;
							p2 = personNode[p1->ID]->currentNeighbor;
							while (p2)
							{
								if ((personNode[p2->ID]->oldinfectState == 3) || (personNode[p2->ID]->oldinfectState == 2)) {
									numberOfInfectNeighbor++;
								}

								p2 = p2->next;
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
		personNode[ID]->Flag = 1;
		randomNumber = rand() / (double)(RAND_MAX);
		if (randomNumber<beta)
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
						if ((personNode[p1->ID]->oldinfectState == 3) || (personNode[p1->ID]->oldinfectState == 2)) {
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
	if (randomNumber <beta) {
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
	if (randomNumber <K) {
		personNode[ID]->infectState = 4;
	}
	else if ((randomNumber >K) && (randomNumber < (K + chi))) {
		personNode[ID]->infectState = 5;
	}
	else
	{
		personNode[ID]->infectState = 9;
	}
	}
}
double computeRstateDensity() {
	sumInfectNumber = 0;
	for (i = 0; i < N; i++)
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
	for (i = 0; i < N; i++)
	{
		if (personNode[i]->infectState == 5) {
			sumInfectNumber++;
		}
	}

	DstateDensity = sumInfectNumber / (double)N;
	return DstateDensity;
}
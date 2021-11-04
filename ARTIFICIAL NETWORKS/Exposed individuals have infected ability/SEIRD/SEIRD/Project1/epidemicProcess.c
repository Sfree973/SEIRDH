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

		freeCurrentNeighbor();

	}
}
void initialAllAgentInfectState() {

	for (i = 0; i < N; i++) {
		personNode[i]->infectState = 1;
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
	for (i = 0; i < N; i++)
	{
		personNode[i]->oldinfectState = personNode[i]->infectState;
	}

}
void changeInfectState(int ID) {
	if (personNode[ID]->oldinfectState == 3) {
		randomNumber = rand() / (double)(RAND_MAX);
		if (randomNumber < mu) {
			personNode[ID]->infectState = 4;
		}
		else if ((randomNumber>mu) && (randomNumber<(mu + d)))
		{
			personNode[ID]->infectState = 5;
		}
		else
		{
			personNode[ID]->infectState = 3;
		}
	}
	else if (personNode[ID]->oldinfectState == 1)
	{
		numberOfInfectNeighbor = 0;
		p = personNode[ID]->currentNeighbor;
		while (p)
		{
			if ((personNode[p->ID]->oldinfectState == 3)|| (personNode[p->ID]->oldinfectState == 2)) {
				numberOfInfectNeighbor++;
			}

			p = p->next;
		}
		randomNumber = rand() / (double)(RAND_MAX);
		if (randomNumber < (1 - pow(1 - lambdaInfect, numberOfInfectNeighbor))) {
			personNode[ID]->infectState = 2;
		}
	}
	else if (personNode[ID]->oldinfectState == 2) {
		randomNumber = rand() / (double)(RAND_MAX);
		if (randomNumber<beta)
		{
			personNode[ID]->infectState = 3;
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
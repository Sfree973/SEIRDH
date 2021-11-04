#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include"head.h"
int main()
{
	srand((unsigned)time(NULL));
	initialPerson();
	initBian();
	dataDrivenModel();
}
void dataDrivenModel() {
	initCurrentNeighbor();
	initialAVERstateandlambdaHead();
	initialAVEDstateandlambdaHead();
	lambdaInfect = lambdaInfect0;
	while (lambdaInfect <= lambdaMax) {
		initialRstateandlambdaLianbiao();
		initialDstateandlambdaLianbiao();
		for (ave = 1; ave <= AVE; ave++) {
			initialAllAgentInfectState();
			initialAllAgentFlag();
			infectFractionSeeds();
			for (ave2 = 0; ave2 < AVE2; ave2++)
			{
				startTime = bian[0]->timeStamp;
				int countEvent = 0;
				for (b = 0; b < B; b++) {	

					currentTimeStamp = bian[b]->timeStamp;
					if (startTime <= currentTimeStamp && currentTimeStamp < (startTime + interTime))
					{
						readBian(bian[b]->fromId, bian[b]->toId);
						countEvent++;
						continue;
					}
					if (countEvent > 0)
					{
						updateInfectState();
						epidemicProcess();
						freeCurrentNeighbor();
						initCurrentNeighbor();
						initialAllAgentFlag();
						countEvent = 1;
					}
					startTime =currentTimeStamp;
				}
			}
			insertRstateandlambdaDensity(lambdaInfect, computeRstateDensity(), ave);
			insertDstateandlambdaDensity(lambdaInfect, computeDstateDensity(), ave);
		}
		insertAVERstateandlambda();
		freeRstateandlambdaBiao();
		AVERstateandlambdaBiaoIntoFile();
		insertAVEDstateandlambda();
		freeDstateandlambdaBiao();
		AVEDstateandlambdaBiaoIntoFile();									
		lambdaInfect = lambdaInfect + lambdaInter; 
		printf("�µ�lambdaInfect����\n");
	}
	freePersonNode();
	freeAVERstateandlambdaBiao();
	freeAVEDstateandlambdaBiao();
}

void AVERstateandlambdaBiaoIntoFile() {
	FILE *f;
	errno_t err;
	if (err = fopen_s(&f, "lambdaandRdensity.txt", "w") != 0) {
		printf("�޷���");
	}

	pppp = AVERstateandlambdaHead->next;
	while (pppp)
	{
		fprintf(f, "%.4f	%.4f\n", pppp->lambda, pppp->Rdensity);
		pppp = pppp->next;
	}

	fclose(f);
}
void AVEDstateandlambdaBiaoIntoFile() {
	FILE* f;
	errno_t err;
	if (err = fopen_s(&f, "lambdaandDdensity.txt", "w") != 0) {
		printf("�޷���");
	}
	ppppp = AVEDstateandlambdaHead->next;
	while (ppppp)
	{
		fprintf(f, "%.4f	%.4f\n", ppppp->lambda, ppppp->Ddensity);
		ppppp = ppppp->next;
	}

	fclose(f);
}
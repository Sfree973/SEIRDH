#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"head.h"
int main()
{
	srand((unsigned)time(NULL));
	initialPersonNode();
	computeAveActive();
	printf("一阶平均活跃度为%lf，二阶平均活跃度为%lf\n", aveActive1, aveActive2);
	lambda = lambda0;
	initialAVERstateandlambdaHead();
	initialAVEDstateandlambdaHead();
	while (lambda <= lambdaMax) {
		alpha = alpha0;
		while (alpha <= alphaMax) {
			initialRstateandlambdaLianbiao();
			initialDstateandlambdaLianbiao();
			for (ave = 1; ave <= AVE; ave++) {
				initialCurrentNeighbor();
				initialAllAgentInfectState();
				infectFractionSeeds();
				epidemicProcess();
				insertRstateandlambdaDensity(lambda, alpha, computeRstateDensity(), ave);
				insertDstateandlambdaDensity(lambda, alpha, computeDstateDensity(), ave);

			}
			insertAVERstateandlambda();
			insertAVEDstateandlambda();
			freeRstateandlambdaBiao();
			freeDstateandlambdaBiao();
			AVERstateandlambdaBiaoIntoFile();
			AVEDstateandlambdaBiaoIntoFile();

			alpha = alpha + alphaInter;
			printf("新的alpha生成\n");
		}
		lambda=lambda + lambdaInter;
	}
	freePersonNode();
	freeAVERstateandlambdaBiao();
	freeAVEDstateandlambdaBiao();
	
}
void initialRstateandlambdaLianbiao() {
	RstateandlambdaHead = (struct recordRstateandalphaandelta*)malloc(sizeof(struct recordRstateandalphaandelta));
	if (RstateandlambdaHead == NULL) {
		printf("RstateandlambdaHead申请内存失败\n");
	}
	RstateandlambdaHead->next = NULL;
}
void initialDstateandlambdaLianbiao() {
	DstateandlambdaHead = (struct recordDstateandalphaandelta*)malloc(sizeof(struct recordDstateandalphaandelta));
	if (DstateandlambdaHead == NULL) {
		printf("DstateandlambdaHead申请内存失败\n");
	}
	DstateandlambdaHead->next = NULL;
}
void initialAVERstateandlambdaHead() {
	AVERstateandlambdaHead = (struct recordRstateandalphaandelta*)malloc(sizeof(struct recordRstateandalphaandelta));
	AVERstateandlambdaHead->next = NULL;
}

void initialAVEDstateandlambdaHead() {
	AVEDstateandlambdaHead = (struct recordDstateandalphaandelta*)malloc(sizeof(struct recordDstateandalphaandelta));
	AVEDstateandlambdaHead->next = NULL;
}

void insertRstateandlambdaDensity(double lambdaValue, double alphaValue, double RdensityValue, int ave) {

	ssss = (struct recordRstateandalphaandelta*)malloc(sizeof(struct recordRstateandalphaandelta));
	ssss->lambda= lambdaValue;
	ssss->alpha = alphaValue;
	ssss->Rdensity = RdensityValue;
	printf("--------------第%d次结束,lambda值为：%lf,alpha值为：%lf,阈值为%lf，R密度为%lf\n", ave, lambdaValue, alphaValue,lambdac, RdensityValue);
	ssss->next = RstateandlambdaHead->next;
	RstateandlambdaHead->next = ssss;

}
void insertDstateandlambdaDensity(double lambdaValue, double alphaValue, double DdensityValue, int ave) {

	sssss = (struct recordDstateandalphaandelta*)malloc(sizeof(struct recordDstateandalphaandelta));
	sssss->lambda= lambdaValue;
	sssss->alpha = alphaValue;
	sssss->Ddensity = DdensityValue;
	printf("--------------第%d次结束,lambda值为：%lf,alpha值为：%lf,阈值为%lf，D密度为%lf\n", ave, lambdaValue, alphaValue, lambdac, DdensityValue);
	sssss->next = DstateandlambdaHead->next;
	DstateandlambdaHead->next = sssss;

}

void insertAVERstateandlambda() {

	sumRstateDensity = 0;
	pppp = RstateandlambdaHead->next;

	ssss = (struct recordRstateandalphaandelta*)malloc(sizeof(struct recordRstateandalphaandelta));
	ssss->lambda = pppp->lambda;
	ssss->alpha = pppp->alpha;
	while (pppp)
	{
		sumRstateDensity += pppp->Rdensity;
		pppp = pppp->next;
	}
	ssss->Rdensity = sumRstateDensity / (double)AVE;
	printf("lambda取值为%lf时，delta取值为%lf时，总平均%d后R态感染密度为：%lf\n", ssss->lambda, ssss->alpha, AVE, ssss->Rdensity);
	ssss->next = AVERstateandlambdaHead->next;
	AVERstateandlambdaHead->next = ssss;
}

void insertAVEDstateandlambda() {

	sumDstateDensity = 0;
	ppppp = DstateandlambdaHead->next;

	sssss = (struct recordDstateandalphaandelta*)malloc(sizeof(struct recordDstateandalphaandelta));
	sssss->lambda = ppppp->lambda;
	sssss->alpha = ppppp->alpha;
	while (ppppp)
	{
		sumDstateDensity += ppppp->Ddensity;
		ppppp = ppppp->next;
	}
	sssss->Ddensity = sumDstateDensity / (double)AVE;
	printf("lambda取值为%lf时，alpha取值为%lf时，总平均%d后D态感染密度为：%lf\n", sssss->lambda, sssss->alpha, AVE, sssss->Ddensity);
	sssss->next = AVEDstateandlambdaHead->next;
	AVEDstateandlambdaHead->next = sssss;
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

void freeAVERstateandlambdaBiao() {
	pppp = AVERstateandlambdaHead->next;
	while (pppp)
	{
		qqqq = pppp->next;
		free(pppp);
		pppp = qqqq;
	}
	free(AVERstateandlambdaHead);
}

void freeAVEDstateandlambdaBiao() {
	ppppp = AVEDstateandlambdaHead->next;
	while (ppppp)
	{
		qqqqq = ppppp->next;
		free(ppppp);
		ppppp = qqqqq;
	}
	free(AVEDstateandlambdaHead);
}

void AVERstateandlambdaBiaoIntoFile() {
	FILE* f;
	errno_t err;
	if (err = fopen_s(&f, "alphaanddeltaandRdensity.txt", "w") != 0) {
		printf("无法打开");
	}
	pppp = AVERstateandlambdaHead->next;
	while (pppp)
	{
		fprintf(f, "%lf %lf	%lf\n", pppp->lambda, pppp->alpha, pppp->Rdensity);
		pppp = pppp->next;
	}

	fclose(f);
}
void AVEDstateandlambdaBiaoIntoFile() {
	FILE* f;
	errno_t err;
	if (err = fopen_s(&f, "alphaanddeltaandDdensity.txt", "w") != 0) {
		printf("无法打开");
	}
	ppppp = AVEDstateandlambdaHead->next;
	while (ppppp)
	{
		fprintf(f, "%lf %lf	%lf\n", ppppp->lambda, ppppp->alpha, ppppp->Ddensity);
		ppppp = ppppp->next;
	}

	fclose(f);
}
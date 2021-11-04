#define N 410
#define B 17298
#define AVE 100
#define interTime 300 
#define infectSeeds 0.01	
#define mu 0.05	
#define d 0.001 
#define beta 0.07 
#define alpha 0.5 
#define delta 0.5 
#define tau 0.07 
#define omega 0.5 
#define K 0.05 
#define chi 0.0005 
#define AVE2 1
#define lambdaInter 0.1
#define lambdaInfect0  0
#define lambdaMax 1.1       


typedef struct person {
	int ID;
	struct neighborList *currentNeighbor;
	struct neighborList2 *Neighbor;
	int infectState;
	int oldinfectState;
	int cumulativeDegree;
	int Flag;
	double active;
	int TNumber;
}person;
typedef struct Bian {
	int fromId;
	int toId;
	int timeStamp;
	int f;
}Bian;
typedef struct neighborList
{
	int ID;
	struct neighborList *next;
}neighborList;
typedef struct neighborList2
{
	int ID;
	struct neighborList2 *next;
}neighborList2;
typedef struct BeSelectedID 
{
	int ID;
	struct BeSelectedID *next;
}BeSelectedID;
typedef struct recordRstateandlambda {
	double lambda;
	double Rdensity;
	struct recordRstateandlambda *next;
}recordRstateandlambda;
typedef struct recordDstateandlambda {
	double lambda;
	double Ddensity;
	struct recordDstateandlambda *next;
}recordDstateandlambda;
int i, ave, j, k, kk, b, kkk, dege,L;
int randNumberID;
int startTime;
int startTime2;
int interNumber;
int randNumberID, selectRandnumber;
int Number;
double randomNumber;
int numberOfInfectNeighbor;
double lambdaInfect;
double sumRstateDensity;
double sumDstateDensity;
double sumInfectNumber;
double RstateDensity;
double DstateDensity;
int ave2, F;
person *personNode[N + 1];
Bian* bian[B];
neighborList *p, *q, *s, *pp, *qq, *ss, *p1, *t, *tail, * pre, * virtualHead,*p3, *p4, *p5;
neighborList2 *p2, *q2, *s2, *pp2, *qq2, *ss2, *t2, * tail2, *pre2, *virtualHead2, *pfirst, *pend;
BeSelectedID *BeSelectedHead, *ppp, *qqq, *sss, *BeSelectedInfectSeedsHead;
recordRstateandlambda *RstateandlambdaHead,  *pppp, *qqqq, *ssss, *AVERstateandlambdaHead;
recordDstateandlambda *DstateandlambdaHead,  *ppppp, *qqqqq, *sssss, *AVEDstateandlambdaHead;
int  currentTimeStamp, previousTimeStamp, nextTimeStamp, currentTimeStamp2, startTime2;
double TNumber;

void initialPerson();
void initCurrentNeighbor();
void freeCurrentNeighbor();
void initNeighbor();
void freeNeighbor();
int isAlreadyCurrentNeighbor(int ID, int toID);
int isAlreadyNeighbor(int ID, int toID);
void becomeNeighbor(int ID, int toID);
void becomeNeighbor2(int ID, int toID);
void initBian();
void initCumuDegree();
void readBian(int fromId, int toId);
void readBian2(int fromId, int toId);
void dataDrivenModel();
void freePersonNode();

void initialAllAgentInfectState();
void initialAllAgentFlag();
void initialAllAgentTNumber();
void infectFractionSeeds();
void updateInfectState();
void epidemicProcess(int F);
void changeInfectState(int ID,int F);
double computeRstateDensity(); 
double computeDstateDensity();

void initialRstateandlambdaLianbiao();
void initialAVERstateandlambdaHead();
void insertRstateandlambdaDensity(double lambdaValue, double RDensityValue, int ave);
void insertAVERstateandlambda();
void freeAVERstateandlambdaBiao();
void freeRstateandlambdaBiao();
void AVERstateandlambdaBiaoIntoFile();

void initialDstateandlambdaLianbiao();
void initialAVEDstateandlambdaHead();
void insertDstateandlambdaDensity(double lambdaValue, double DDensityValue, int ave);
void insertAVEDstateandlambda();
void freeAVEDstateandlambdaBiao();
void freeDstateandlambdaBiao();
void AVEDstateandlambdaBiaoIntoFile();


void freeBeSelectedInfectSeedsBiao();
void BubbleSort(int ID );
void dataDrivenModel3(int F);
void dataDrivenModel2();
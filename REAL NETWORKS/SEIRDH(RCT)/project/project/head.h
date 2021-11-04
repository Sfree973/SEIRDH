#define N 410
#define B 17298
#define AVE 2000
#define interTime 100
#define infectSeeds 0.01	
#define mu 0.05	
#define d 0.001 
#define beta 0.07 
#define alpha 0.01 
#define delta 0.1 
#define tau 0.07 
#define omega 0.5 
#define K 0.05 
#define chi 0.0005 
#define AVE2 20
#define lambdaInter 0.05
#define lambdaInfect0  0
#define lambdaMax 1.05       

typedef struct person {
	int ID;
	struct neighborList *currentNeighbor;
	int infectState;
	int oldinfectState;
	int cumulativeDegree;
	int Flag;
}person;
typedef struct Bian {
	int fromId;
	int toId;
	int timeStamp;
}Bian;
typedef struct neighborList
{
	int ID;
	struct neighborList *next;
}neighborList;
typedef struct BeSelectedID 
{
	int ID;
	struct BeSelectedID* next;
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
int i, ave, j, k, kk, b;
int randNumberID;
int m;
int startTime;
int interNumber;
int randNumberID, selectRandnumber;

double randomNumber;
int numberOfInfectNeighbor;
double lambdaInfect;
double sumRstateDensity;
double sumDstateDensity;
double sumInfectNumber;
double RstateDensity;
double DstateDensity;
int ave2;
person *personNode[N + 1];
neighborList *p, *q, *s, *pp, *qq, *ss, *p1, *p2;
BeSelectedID *BeSelectedHead, *ppp, *qqq, *sss, *BeSelectedInfectSeedsHead;
recordRstateandlambda *RstateandlambdaHead,  *pppp, *qqqq, *ssss, *AVERstateandlambdaHead;
recordDstateandlambda *DstateandlambdaHead,  *ppppp, *qqqqq, *sssss, *AVEDstateandlambdaHead;
Bian *bian[B];
int  currentTimeStamp, previousTimeStamp, nextTimeStamp;

void initialPerson();
void initCurrentNeighbor();
void freeCurrentNeighbor();
int isAlreadyCurrentNeighbor(int ID, int toID);
void becomeNeighbor(int currentbtXiaBiao, int neighborXiaBiao);
void initBian();
void initCumuDegree();
int currentNeighborOfNode(int ID);
void readBian(int fromId, int toId);
void dataDrivenModel();
void freePersonNode();

void initialAllAgentInfectState();
void initialAllAgentFlag();
void infectFractionSeeds();
void epidemicProcess();
void updateInfectState();
void changeInfectState(int ID);
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
int currentNeighborOfNode(int ID);
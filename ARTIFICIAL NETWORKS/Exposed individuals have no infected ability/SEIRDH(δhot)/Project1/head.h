
#define N 10000	
#define m 5	
#define gamma 2.1	
#define lBound 0.001		
#define uBound 1	
#define AVE 50
#define step 5000

#define infectSeeds 0.01	
#define mu 0.01	
#define d 0.001 
#define beta 0.5 
#define alpha 0.01 
#define tau 0.07 
#define omega 0.5 
#define K 0.05 
#define chi 0.0005 

#define lambdaInter 0.01
#define  lambda0 0
#define lambdaMax 0.51      
#define deltaInter 0.1
#define  delta0 0
#define deltaMax 1     


typedef struct person {
	int ID;
	double active;
	struct neighborList *currentNeighbor;
	int activeState;
	int infectState;
	int Flag;
}person;
typedef struct neighborList
{
	int ID;
	struct neighborList *next;
}neighborList;
typedef struct BeSelectedID 
{
	int ID;
	struct BeSelectedID *next;
}BeSelectedID;

typedef struct recordRstateandalphaandelta {
	double lambda ;
	double delta;
	double Rdensity;
	double lambdac;
	struct recordRstateandalphaandelta* next;
}recordRstateandalphaandelta;
typedef struct recordDstateandalphaandelta {
	double lambda;
	double delta;
	double Ddensity;
	double lambdac;
	struct recordDstateandalphaandelta* next;
}recordDstateandalphaandelta;
struct person *personNode[N];
neighborList *p, *q, *s, *Head, *pp, *qq, *ss, *temp, *p1;
BeSelectedID *BeSelectedHead, *ppp, *qqq, *sss,*BeSelectedInfectSeedsHead;
recordRstateandalphaandelta* RstateandlambdaHead, * s1, * pppp, * qqqq, * ssss, * AVERstateandlambdaHead;
recordDstateandalphaandelta* DstateandlambdaHead, * s3, * ppppp, * qqqqq, * sssss, * AVEDstateandlambdaHead;
int kk;
int i, k,t,ave;
double randomNumber, active, aveActive1, aveActive2, lambdac;
double sumRstateDensity, sumDstateDensity;
int  randNumberID, selectRandnumber;
int  numberOfCurrentNeighb;
double sumInfectNumber;
int numOfActiveState;
int infectNumber;
double RstateDensity, DstateDensity;
int integerPart; 
double decimalPart;
double sumActive;
int numberOfInfectNeighbor;
int immuNumber;
double lambda, delta;

void initialPersonNode();
void initialCurrentNeighbor(); 
void initialBeSelectedID();
void computeAveActive();
void fireAllAgent();
void selectNodeToContact(int ID, int numberOfContact);
int isAlreadyCurrentNeighbor(int ID, int ppID);
void becomeNeighbor(int ID1, int ID2);
void freePersonNode();
void freeCurrentNeighbor();
void freeBeselectedIDandHead();
									 
void initialAllAgentFlag();
void epidemicProcess();
void infectFractionSeeds();
void initialAllAgentInfectState();
void changeInfectState(int ID);
void freeBeSelectedInfectSeedsBiao();
double computeRstateDensity();
double computeDstateDensity();

void initialRstateandlambdaLianbiao();
void initialDstateandlambdaLianbiao();

void insertRstateandlambdaDensity(double lambdaValue, double deltaValue, double RdensityValue, int ave);
void insertDstateandlambdaDensity(double lambdaValue, double deltaValue, double DdensityValue, int ave);

void freeRstateandlambdaBiao();
void freeDstateandlambdaBiao();

void initialAVERstateandlambdaHead();
void initialAVEDstateandlambdaHead();

void insertAVERstateandlambda();
void insertAVEDstateandlambda();

void AVERstateandlambdaBiaoIntoFile();
void AVEDstateandlambdaBiaoIntoFile();

void freeAVERstateandlambdaBiao();
void freeAVEDstateandlambdaBiao();
int currentNeighborOfNode(int ID);

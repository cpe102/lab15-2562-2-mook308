#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *x,int N,int M){

	for(int i=0;i<(N*M);i++){
		double y=rand()%100;
		*x = y/100;
		x++;
	}


}

void showData(double *x,int N,int M){
	for(int i=0;i<(N*M);i++){
		if(i%M == 0 && i != 0){
			cout << " \n";
		}
		cout << *x << " ";
		x++;
	}
	cout << " \n";
}


void findRowSum(const double *x,double *y,int N,int M){
	double sum = 0;
	for(int i=0;i<(N*M);i++){
		if(i%M == 0 && i != 0){
			*y = sum;
			sum = 0;
			y++;
		}else if(i == ((N*M)-1)){
			*y = sum;
			sum = 0;
			y++;
		}
		sum+=*x;
		x++;
	}
}
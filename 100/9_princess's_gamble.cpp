#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int MAX_DATASET = 100;
const int GOLD = 100;

int Parimutuel(int m,int p,int *votingTicket,int sumVoting){
    double dividend = 0;
    if(votingTicket[m-1] != 0){
        dividend = sumVoting * GOLD;
        dividend = dividend * (100-p)/100;
        dividend = dividend/votingTicket[m-1];
    }
    return (int)dividend;
}

int main(int argc, char const *argv[]){
    int n = 0, m = 0, p = 0;
    int votingTicket[MAX_DATASET + 1] = {0};
    int sumVoting = 0;
    int ans = 0;
    while(true){
        scanf("%d %d %d",&n,&m,&p);
        if(n <= 0 || n > MAX_DATASET || m <= 0 || m > n || p < 0 || p > 100){
            break;
        }else{
            sumVoting = 0;
            memset(votingTicket,0,MAX_DATASET+1);
            for(int i = 0; i < n; i++){
                scanf("%d",&votingTicket[i]);
                sumVoting += votingTicket[i];
            }
            ans = Parimutuel(m,p,votingTicket,sumVoting);
            printf("%d\n",ans);
        }
    }
    return 0;
}
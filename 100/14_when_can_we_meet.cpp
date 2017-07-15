#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int date[51][1001];
int dateM[51];

int adjustSchedule(int N,int Q){
    int votedDate[101] = {0};
    int ans = INT_MAX;
    int vote = INT_MIN;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < dateM[i]; j++){
            votedDate[date[i][j]]++;
            if(votedDate[date[i][j]] >= Q && vote < votedDate[date[i][j]]){
                vote = votedDate[date[i][j]];
                ans = date[i][j];
            }else if(votedDate[date[i][j]] >= Q && vote == votedDate[date[i][j]] && ans > date[i][j]){
                ans = date[i][j];
            }
        }
    }
    if(ans > 100){
        ans = 0;
    }
    return ans;
}

int main(int argc, char const *argv[]){
    int N = 0, Q = 0;
    int M = 0;
    int temp;
    while(scanf("%d %d",&N,&Q)!=EOF){
        if(N <= 0 || N > 50 || Q <= 0 || Q > N){
            break;
        }else{
            for(int i = 0; i < N; i++){
                scanf("%d",&M);
                dateM[i] = M;
                for(int j = 0; j < M; j++){
                    scanf("%d",&temp);
                    date[i][j] = temp;
                }
            }
            printf("%d\n",adjustSchedule(N,Q));
        }
    }
    return 0;
}
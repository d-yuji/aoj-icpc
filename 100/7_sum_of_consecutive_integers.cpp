#include <iostream>
#include <cstdio>
int integerCombination(int N){
    int count = 0;
    int sum = 0;
    for(int i = 1; i <= N/2; i++){
        sum = i;
        int j = i + 1;
        while(true){
            if(sum > N){
                break;
            }else if(sum == N){
                count++;
                break;
            }else{
                sum = sum + j;
                j++;
            }
        }
    }
    return count;
}
int main(int argc, char const *argv[]){
    int N;
    while(true){
        scanf("%d",&N);
        if(N < 1 || N > 1000){
            break;
        }else{
            printf("%d\n",integerCombination(N));
        }
    }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>

using namespace std;

int pseudoRandNum(int x,int a,int b,int c){
    return (a * x +b)%c;
}

int stopFrame(int n,int a,int b,int c,int x,int *flame){
    int turn = -1;
    int count = 0;
    int reel = x;
    for(int i = 0; i <= 10000; i++){
        if(flame[count] == reel){
            count++;
        }
        if(count == n){
            turn = i;
            break;
        }
        reel = pseudoRandNum(reel,a,b,c);
    }
    return turn;
}

int main(int argc, char const *argv[]){
    int n = 0, a = 0, b = 0, c = 0, x = 0;
    int flame[10001];

    while(scanf("%d %d %d %d %d",&n,&a,&b,&c,&x) != EOF){
        if(n < 1 || n > 100 || a < 0 || a > 10000 || b < 0 || b > 10000 || c < 1 || c > 10000 || x < 0 || x >= c){
            break;
        }else{
            for(int i = 0; i < n; i++){
                scanf("%d",&flame[i]);
                if(flame[i] < 0 || flame[i] > 10000){
                    printf("error::input value\n");
                    exit(0);
                }
            }
            printf("%d\n",stopFrame(n,a,b,c,x,flame));
        }
    }
    return 0;
}
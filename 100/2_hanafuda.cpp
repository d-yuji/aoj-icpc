#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void shuffle(int *card,int p,int c,int n){
    int copy[51];
    for(int i = 0; i < n; i++){
        copy[i] = card[i];
    }
    for(int i = 0; i < c; i++){
        copy[i] = card[p-1+i];
    }
    for(int i = 0; i < p-1; i++){
        copy[c+i] = card[i];
    }
    for (int i = 0; i < n; i++){
        card[i] = copy[i];
    }
    return;
}

int main(int argc, char const *argv[]){
    int n,r;
    int p,c;
    int card[51] = {0};
    while(true){
        scanf("%d %d",&n,&r);
        if(n == 0 || r == 0){
            break;
        }else{
            for(int i = 0; i < n; i++){
                card[i] = n-i;
            }
            for(int i = 0; i < r; i++){
                scanf("%d %d",&p,&c);
                shuffle(card, p, c, n);
            }
            printf("%d\n",card[0]);
        }
    }
    return 0;
}
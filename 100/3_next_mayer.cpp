#include <iostream>
#include <cstdio>

using namespace std;

void nextturn(int *turn,int n){
    if(*turn >=  n-1){
        *turn = 0;
    }else{
        (*turn)++;
    }
    return;
}

int game(int *candidate,int stone,int n){
    int turn = 0;
    int st = stone;
    while(true){
        if(st == 0){
            st = candidate[turn];
            candidate[turn] = 0;
            // cout << "reset\n";
            nextturn(&turn, n);
        }else if(st == 1 && candidate[turn] == stone -1){
            // cout << "debug\n";
            break;
        }else{
            // cout << "act\n";
            candidate[turn]++;
            st--;
            nextturn(&turn,n);
        }
    }
    return turn;
}

int main(int argc, char const *argv[]){
    int n,p;
    int candidate[51];
    int stone;
    while(true){
        scanf("%d %d",&n,&p);
        if(n < 3 || n > 50 || p < 2 || p > 50){
            break;
        }else{
            for(int i = 0; i < n; i++){
                candidate[i] = 0;
            }
            stone = p;
            printf("%d\n",game(candidate, stone, n));
        }
    }
    return 0;
}
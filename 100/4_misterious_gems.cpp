#include <iostream>
#include <cstdio>
int coordinate[21][21];

int dx[4] = {
    0,1,-1,0
};
int dy[4] = {
    1,0,0,-1
};

bool isExistJ(int x,int y){
    if(coordinate[y][x] == 1){
        coordinate[y][x] = 0;
        return true;
    }else{
        return false;
    }
}

bool search(char *direction, int *distance,int N,int M){
    int x = 10;
    int y = 10;
    int getJ = 0;
    int dir = 0;
    for(int i = 0; i < M; i++){
        switch(direction[i]){
            case 'N' :
                dir = 0;
                break;
            case 'E' :
                dir = 1;
                break;
            case 'W' :
                dir = 2;
                break;
            case 'S' :
                dir = 3;
                break;
        }
        for(int j = 0; j < distance[i]; j++){
            x = x + dx[dir];
            y = y + dy[dir];
            if(isExistJ(x,y)){
                ++getJ;
            }
        }
    }
    //printf("%d\n",getJ );
    if(getJ == N){
        return true;
    }else{
        return false;
    }
}

int main(int argc, char const *argv[]){
    int N,M;
    char direction[31];
    int distance[31];
    int tx,ty;

    while(true){
        scanf("%d",&N);
        if(N <= 0 || N > 20){
            break;
        }else{
            for(int i = 0; i < 20; i++){
                for(int j = 0; j < 20; j++){
                    coordinate[i][j] = 0;
                }
            }
            for(int i = 0; i < N; i++){
                scanf("%d %d",&tx,&ty);
                coordinate[ty][tx] = 1;
            }
            scanf("%d",&M);
            if(M <= 0 || M > 30){
                break;
            }
            char temp;
            for(int i = 0; i < M; i++){
                scanf("%c",&temp);
                scanf("%c",&direction[i]);
                scanf("%d",&distance[i]);
            }
            if(search(direction, distance, N, M)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;
}
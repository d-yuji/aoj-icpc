#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char const *argv[]){
    int n,m;
    int taro[101];
    int hanako[101];
    int sumtaro,sumhanako;
    int anstaro,anshanako;
    while(true){
        scanf("%d %d",&n,&m);
        if(n <= 0 || n > 100 || m <= 0 || m > 100){
            break;
        }else{
            sumtaro = 0;
            sumhanako = 0;
            for(int i = 0; i < n; i++){
                scanf("%d",&taro[i]);
                sumtaro = sumtaro + taro[i];
            }
            for(int i = 0; i < m; i++){
                scanf("%d",&hanako[i]);
                sumhanako = sumhanako + hanako[i];
            }
            anstaro = -1;
            anshanako = -1;
            int diff = sumtaro - sumhanako;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(diff == (2*taro[i] - 2*hanako[j])){
                        if(anstaro+anshanako > taro[i]+hanako[j]){
                            anstaro = taro[i];
                            anshanako = hanako[j];
                        }else if(anstaro == -1 && anshanako == -1){
                            anstaro = taro[i];
                            anshanako = hanako[j];
                        }
                    }
                }
            }
            if(anstaro == -1 && anshanako == -1){
                printf("-1\n");
            }else{
                printf("%d %d\n",anstaro,anshanako );
            }
        }
    }
    return 0;
}
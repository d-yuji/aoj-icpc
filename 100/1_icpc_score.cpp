#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
    int n;
    int s[1000];
    int max,min,sum;
    while(1){
        scanf("%d",&n);
        if(n <= 0){
            break;
        }else{
            max = -1;
            min = 1001;
            sum = 0;
            for (int i = 0; i < n; ++i){
                scanf("%d",&s[i]);
                if(s[i] > max){
                    max = s[i];
                }
                if(s[i] < min){
                    min = s[i];
                }
                sum += s[i];
            }
            printf("%d\n",(sum-min-max)/(n-2));
        }
    }
    return 0;
}
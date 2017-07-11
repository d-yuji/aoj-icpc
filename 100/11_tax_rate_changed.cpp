#include <iostream>
#include <cstdio>

int taxApply(int x,int p){
    return x * (100 + p)/100;
}
int taxCancel(int x,int p){
    return x * 100/(100 + p);
}

int taxRate(int x,int y,int s){
    int tax = 0;
    int sum_x = 0, sum_y = 0;
    for(int i = 1; i <= s; i++){
        for(int j = i; j <= s; j++){
            sum_x = taxApply(i,x) + taxApply(j,x);
            sum_y = taxApply(i,y) + taxApply(j,y);
            if(sum_x == s && sum_y > tax){
                tax = sum_y;
            }else if(sum_x > s){
                break;
            }
        }
    }
    return tax;
}

int main(int argc, char const *argv[]){
    int x = 0,y = 0, s = 0;
    while(true){
        scanf("%d %d %d",&x,&y,&s);
        if(x <= 0 || x >= 100 || y <= 0 || y >= 100 || s <= 10 || s >= 1000){
            break;
        }else{
            printf("%d\n",taxRate(x,y,s));
        }
    }
    return 0;
}
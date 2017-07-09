#include <iostream>
#include <cstdio>

using namespace std;
const int LARGE_MONTH = 20;
const int SMALL_MONTH = 19;
const int LEAP_YEAR = LARGE_MONTH * 10;
const int EVERY_YEAR = LARGE_MONTH * 5 + SMALL_MONTH * 5;

int yearToDay(int year){
    int passYear = year - 1;
    return (passYear/3) * LEAP_YEAR + (passYear - passYear/3) * EVERY_YEAR;
}
int monthToDay(int year,int month){
    int passMonth = month - 1;
    int even = passMonth/2;
    if(year%3 == 0){
        return LARGE_MONTH * passMonth;
    }else{
        return SMALL_MONTH * even + LARGE_MONTH * (passMonth - even);
    }
}
int millennium(int year,int month,int day){
    return (day-1) + yearToDay(year) +  monthToDay(year,month);
}

int main(int argc, char const *argv[]){
    int n;
    int year,month,day;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&year,&month,&day);
        printf("%d\n",millennium(1000,1,1) - millennium(year,month,day));
    }
    return 0;
}
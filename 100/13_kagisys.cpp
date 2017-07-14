#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

const int MAX_ID_NUM = 256;
const int OPEN = 1;
const int CLOSE = -1;

void unlock(string inputKey, vector<string> registeredID, int *openFlag){
    vector<string>::iterator itr = find(registeredID.begin(), registeredID.end(),inputKey);
    if( itr != registeredID.end() ) {
        if(*openFlag == CLOSE){
            cout << "Opened by " << inputKey << endl;
        }else if (*openFlag == OPEN){
            cout << "Closed by " << inputKey << endl;
        }
       *openFlag  = *openFlag * -1;
    }else{
        cout << "Unknown " << inputKey << endl;
    }
    return;
}
int main(int argc, char const *argv[]){
    int N = 0, M = 0;
    int openFlag = CLOSE;
    vector<string> registeredID(MAX_ID_NUM+1);
    string inputKey;

    scanf("%d",&N);
    if(N < 0 || N > MAX_ID_NUM){
        exit(0);
    }
    for(int i = 0; i < N; i++){
        cin >> registeredID[i];
    }
    scanf("%d",&M);
    if(M < 0 || M > MAX_ID_NUM){
        exit(0);
    }
    for(int i = 0; i < M; i++){
        cin >> inputKey;
        unlock(inputKey,registeredID,&openFlag);
    }
    return 0;
}
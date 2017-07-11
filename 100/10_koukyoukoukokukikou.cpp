#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX_MESSAGE_LENGTH = 32;
const char* const RIGHT_TYPE = "qwertasdfgzxcvb";
const char* const LEFT_TYPE = "yuiophjklnm";
const int RIGHT = 1;
const int LEFT = 0;

int typeHand(char key){
    int r_len = strlen(RIGHT_TYPE);
    int l_len = strlen(LEFT_TYPE);
    for(int i = 0; i < r_len; i++){
        if(key == RIGHT_TYPE[i]){
            return RIGHT;
        }
    }
    for(int i = 0; i < l_len;i++){
        if(key == LEFT_TYPE[i]){
            return LEFT;
        }
    }
    return -1;
}

int qwertyType(char *message){
    int count = 0;
    int m_length = strlen(message);
    int hand = typeHand(message[0]);
    int nextHand = -1;
    for(int i = 1; i < m_length; i++){
        nextHand = typeHand(message[i]);
        if(hand != nextHand && nextHand != -1){
            count++;
            hand = nextHand;
        }else if(nextHand == -1){
            printf("not alphabet\n");
            exit(0);
        }
    }
    return count;
}

int main(int argc, char const *argv[]){
    char message[MAX_MESSAGE_LENGTH + 1];
    while(true){
        scanf("%s",message);
        if(strlen(message) <= 0 || strncmp(message,"#",1) == 0){
            break;
        }else{
            printf("%d\n",qwertyType(message));
        }
    }
    return 0;
}
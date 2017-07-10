#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int MAX_MESSAGE_LENGTH = 77;
const int MAX_PROGRESSION = 1025;

char chracterAllocation(char num){
    switch(num){
        case '0':
            return '\0';
            break;
        case '1':
            return '.';
            break;
        case '2':
            return 'a';
            break;
        case '3':
            return 'd';
            break;
        case '4':
            return 'g';
            break;
        case '5':
            return 'j';
            break;
        case '6':
            return 'm';
            break;
        case '7':
            return 'p';
            break;
        case '8':
            return 't';
            break;
        case '9':
            return 'w';
            break;
    }
    return '?';
}
char nextCharacter(char key){
    char next;
    switch(key){
        case '.':
            next = ',';
            break;
        case ',':
            next = '!';
            break;
        case '!':
            next = '?';
            break;
        case '?':
            next = ' ';
            break;
        case ' ':
            next ='.';
            break;
        case 's':
        case 'z':
            next = key -3;
            break;
        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'v':
            next = key - 2;
            break;
        default:
            next = key + 1;
            break;
    }
    return next;
}
void decode(char *progression,char *message){
    int p_length = strlen(progression);
    int message_index = 0;
    char temp;
    for(int i = 0; i < p_length; i++){
        if(message[message_index] == '\0'){
            message[message_index] = chracterAllocation(progression[i]);
        }else if(progression[i] == '0'){
            message_index++;
        }else{
            temp = nextCharacter(message[message_index]);
            message[message_index] = temp;
        }
    }
    return;
}

int main(int argc, char const *argv[]){
    int n = 0;
    char progression[MAX_PROGRESSION];
    char message[MAX_MESSAGE_LENGTH];
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        memset(progression, '\0', MAX_PROGRESSION);
        memset(message, '\0', MAX_MESSAGE_LENGTH);
        scanf("%s",progression);
        decode(progression,message);
        printf("%s\n",message);
    }
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LENGTH 20

/*
Grammar considered

E  -> i E1
E1 -> + i E1 / e


*/


char l;
char* input;
int input_ptr = 0;
char* readString() { // read a string and return its pointer
    char* str = (char*)malloc(sizeof(char)*LENGTH);
    fgets(str,LENGTH,stdin);
    while(strcmp(str,"")==0 || strcmp(str,"\n")==0 || strcmp(str," ")==0) {
        fgets(str,LENGTH,stdin);
    }
    if(str[strlen(str)-1]=='\n') {
        str[strlen(str)-1]='\0';
    }
    return str;
}
void match(char c) {
    if(l == c) {
        input_ptr++;
        l = input[input_ptr];
    }
    else {
        printf("Rejected\n");
        exit(0);
    }
}
void E1() {
    if(l == '+') {
        match('+');
        match('i');
        E1();
    }
    else {
        if(l == '$') {
            printf("Accepted\n");
        }
        else {
            printf("Rejected\n");
        }
    }
}
void E() {
    if(l == 'i') {
        match('i');
        E1();
    }
    else {
        printf("Rejected\n");
    }
}
void main() {
    
    printf("Enter the string ");
    input = readString();
    l=input[input_ptr];
    E();
}
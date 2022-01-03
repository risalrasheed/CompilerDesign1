#include<stdio.h>
#include"inftopost.h"
#include"eval.h"
#include<stdlib.h>

void processString(char* str) {
    if(str[strlen(str)-1]=='\n') {
        str[strlen(str)-1]='\0';
    }
}
struct Value{
    char ch;
    int val;
}values[26];
int values_count=0;
int checkForCh(char* str) {
    int i=0;
    int flag=0;
    
    while(str[i]!='\0') {
        if(str[i]>='a'&&str[i]<='z') {
            int temp_flag=0;
            for(int i=0;i<values_count;i++) {
                if(values[i].ch==str[i]) {
                    str[i]='0'+values[i].val;
                    temp_flag=1;
                    break;
                }
                
            }
            if(temp_flag==0) {
                flag=1;
            }
        }
        i++;
    }
    return flag;
}

void main() {
    FILE* finp=fopen("inp.txt","r");
    FILE* fout=fopen("out.txt","w");
    char* str=(char*)malloc(sizeof(char));
    while(feof(finp)==0) {
        fgets(str,50,finp);
        processString(str);
        int a;
        char* temp_str=(char*)malloc(sizeof(char)*20);
        int i=2;
        while(str[i]!='\0') {
            temp_str[i-2]=str[i];
            i++;

        }
        temp_str[i]='\0';
    
        temp_str=postfix(temp_str);
        //scanf("%d",&a);
        if(checkForCh(temp_str)==0) {
            
            values[values_count].ch=str[0];
            
            values[values_count].val=evaluate(temp_str);
            fprintf(fout,"%c=%d\n",values[values_count].ch,values[values_count].val);
            values_count++;

        }
        else {
            fprintf(fout,"%s\n",str);
        }
    }
    fclose(finp);
    fclose(fout);
}
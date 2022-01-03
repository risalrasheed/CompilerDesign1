#include<stdio.h>
#include<string.h>

void processString(char* str) {
    if(str[strlen(str)-1]=='\n') {
        str[strlen(str)-1]='\0';
    }
}
int checkFor(char* str) {
    int i=0;
    while(i<strlen(str)) {
        while(i<strlen(str)&&str[i]!='f') i++;
        if(str[i+1]!='\0' && str[i+1]=='o') {
            if(str[i+2]!='\0' && str[i+2]=='r') {
                if(str[i+3]!='\0' && (str[i+3]=='(')) {
                    return 1;
                }
            }
        }
        i++;
    }
    return 0;
}

void main() {
    FILE* finp = fopen("inp.c","r");
    FILE* fout = fopen("out.c","w");
    
    int num_unroll=0;
    char str[50];
    
    printf("Enter the number of times unrolling ");
    scanf("%d",&num_unroll);
    while(feof(finp)==0) {
        fgets(str,50,finp);
        processString(str);
        if(checkFor(str)==1) {
            int i=0;
            while(str[i]!=';') i++;
            while(str[i]!=';') i++;
            while(str[i]==' ') i++;

            while(str[i]!='+' && str[i]!='-') i++;
            str[i+1]=str[i+1]+num_unroll-1;
            fprintf(fout,"%s\n",str);

            int beg = ftell(finp);
            int end = ftell(finp);
            while(strcmp(str,"}")!=0) {
                end = ftell(finp);
                fgets(str,50,finp);
                processString(str);
                
            }
            
            for(int i=0;i<num_unroll;i++) {
                fseek(finp,beg,SEEK_SET);
                do {
                    fgets(str,50,finp);
                    processString(str);
                    fprintf(fout,"%s\n",str);
                    
                }while(ftell(finp)!=end);
            }
            fseek(finp,end,SEEK_SET);
            //fgets(str,50,finp);
        }
        else {
            fprintf(fout,"%s\n",str);
        }
    }
    fclose(finp);
    fclose(fout);

}
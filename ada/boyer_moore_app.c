#include<stdio.h>
#include<string.h>
#define size 126

int t[size];
int m;

int max(int a,int b){
    return (a>b)?a:b;
}

void shift(char p[]){
    m=strlen(p);
    for(int i=0;i<size;i++){
        t[i]=m;
    }
    for(int j=0;j<m-1;j++){
        t[p[j]]=m-1-j;
    }
}

int boyer_moore(int src[],int p[]){
    m = strlen(p);
    int n = strlen(p);
    int i;
    i=m-1;
    while(i<n){
        int k=0;
        while((k<=m)&&(p[m-1-k]==src[i-k])){
            k++;
        }
        if(k==m){
            return i-m+1;
        }
        else{
            i=i+max(t[src[i]]-k,1);
        }
    }
}


int main(){
    char src[100],p[100];
    printf("enter the mail");
    gets(src);
    char keywords[4][10] = {'price','money','help','free'};
    int pos;
    int count=0;
    for(int i=0;i<4;i++){
        strcpy(p,keywords[i]);
        shift(p);
        pos=boyer_moore(src,p);
        if(pos>=0){
            count++;
        }
    }
    if(count>3){
        printf("spam");
    }
    else{
        printf("not a spam mail");
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#define MAX 126

int t[MAX];
int m;

int max(int a,int b){
    return (a>b)?a:b;
}

void shift(char p[]){
    m = strlen(p);
    for(int i=0;i<MAX;i++){
        t[i]=m;
    }
    for(int j=0;j<m-1;j++){
        t[p[j]]=m-1-j;
    }
}

int boyer_moore(char src[],char p[]){
    int i=m-1;
    int n = strlen(src);
    while(i<n){
        int k=0;
        while((k<m)&&(p[m-1-k]==src[i-k])){
           k++;
        }
        if(k==m){
            return (i-m+1);
        }
        else{
            i=i+max(t[src[i]]-k,1);
        }
    }
}

int main(){
    char src[100],p[100];
    int pos;
    printf("enter the source string\n");
    gets(src);
    printf("enter the pattern to be searched\n");
    gets(p);
    shift(p);
    pos=boyer_moore(src,p);
    if(pos>=0){
        printf("patter found at position: %d",pos+1);
    }
    else{
        printf("pattern not found");
    }
    return 0;
}

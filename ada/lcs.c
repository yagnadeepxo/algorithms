/* 
    -> take string1 and string2 and find the length of them.
    -> initialize array of size+1 of the 2 strings taken
    -> initlaize first row and col with 0
    -> if string matches do the respective operation
    -> if string doesnt match do the respective operation
    -> now table is created
    -> now go to the end of the table and initialize a charater array and insert the values in it
    -> if there is a diagnol

*/

#include<stdio.h>
#include<string.h>

int max(int a,int b){ 
    return (a>b)?a:b;
}

void lcs(char x[],char y[],int m,int n){
    int L[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                L[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                L[i][j] = L[i-1][j-1]+1;
            }
            else{
                L[i][j] = max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    printf("the longest common subsequence length is %d",L[m][n]);
    int index  = L[m][n];
    char lcs[index+1];
    lcs[index]='\0';
    int i,j;
    while(i>0&&j>0){
        if(x[i]==y[j]){
    
            lcs[index-1] = x[i-1];
            i--;
            j--;
            index--;
        }
        else if(L[i-1][j]>L[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

}

int main(){
    char X[20],Y[20];
    int m,n;
    printf ("Enter 1st Sequence\n");
    gets (X);
    printf ("Enter 2nd Sequence\n");
    gets (Y);
    m = strlen (X);
    n = strlen (Y);
    LCS (X,Y,m,n);
    return 0;
}
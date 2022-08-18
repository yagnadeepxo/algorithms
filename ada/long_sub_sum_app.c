#include <stdio.h>
struct stock
{
 int left;
 int right;
 int sum;
};
struct stock crosssubsum (int *a,int low,int mid,int high)
{
 int leftsum=0,rightsum=0,sum=0,i,j,maxleft=0,maxright=0;
 struct stock res;
 for (i=mid;i>=low;i--)
 {
 sum = sum + a[i];
 if (sum > leftsum)
 {
 leftsum = sum;
 maxleft = i;
 }
 }
 sum = 0;
 for (j=mid+1;j<=high;j++)
 {
 sum = sum + a[j];
 if (sum > rightsum)
  {
 rightsum = sum;
 maxright = j;
 }
 }
 res.left = maxleft;
 res.right = maxright;
 res.sum = leftsum+rightsum;
 return res;
}
struct stock maxsubsum (int *a,int low,int high)
{
 int mid;
 struct stock leftsum,rightsum,crosssum,res;
 if (low == high)
 {
 res.left = low;
 res.right = high;
 res.sum = a[low];
 return res;
 }
 mid = (low+high)/2;
 leftsum = maxsubsum( a,low,mid);
 rightsum = maxsubsum (a,mid+1,high);
 crosssum = crosssubsum (a,low,mid,high);
 if (leftsum.sum >= rightsum.sum && leftsum.sum >=crosssum.sum)
 return leftsum;
 else if (rightsum.sum >= leftsum.sum && rightsum.sum >=crosssum.sum)
 return rightsum;
 else
 return crosssum;
}
int main ()
{
 int n,a[10],i,low,high;
 struct stock maxsum;
 printf ("Enter the no. of Days in Stock Market\n");
 scanf ("%d",&n);
 printf ("Enter the Gain or Loss in Stock Market per Day\n");
 for (i=0;i<n;i++)
 scanf ("%d",&a[i]);
 low =0; high = n-1;
 maxsum = maxsubsum (a,low,high);
 printf ("Maximum Profit in Stock Market lies from Day %d to Day %d\n",maxsum.left+1,maxsum.right+1);
 printf ("Maximum Profit in Stock Market = %d\n",maxsum.sum);
 return 0;
}
// #include <stdio.h>
// void BFS (int a[10][10],int n,int src,int s[10])
// {
//  int f=0,r=-1,q[20],i,v;
//  s[src] = 1;
//  q[++r] = src;
//  while (f <= r)
//  {
//  v = q[f++];
//   for (i=1;i<=n;i++)
//  if (s[i]==0 && a[v][i])
//  {
//  q[++r] = i;
//  s[i] = 1;
//  }
//  }
// }
// int main ()
// {
//  int a[10][10],n,i,j,s[20],src,dest;
//  printf ("Enter no. of Nodes in Graph\n");
//  scanf ("%d",&n);
//  printf ("Enter the connections of Graph in Adjacency Matrix\n");
//  for (i=1;i<=n;i++)
//  for (j=1;j<=n;j++)
//  scanf ("%d",&a[i][j]);
//  printf ("Enter the Source Node\n");
//  scanf ("%d",&src);
//  printf ("Enter the Destination Node\n");
//  scanf ("%d",&dest);
//  printf ("Source Node = %d\n",src);
//  printf ("Destination Node = %d\n",dest);
//  for(i=1;i<=n;i++)
//  s[i]=0;
//  BFS (a,n,src,s);
//  if (s[src]==1 && s[dest]==1)
//  printf ("Destination is Reachable from %d to %d\n",src,dest);
//  else
//  printf ("Destination not Reachable\n");
//  return 0;
// }

#include <stdio.h>
void DFS (int a[10][10],int n,int src,int s[10])
{
 int i;
 s[src] = 1;
 for (i=1;i<=n;i++)
 if (s[i]==0 && a[src][i])
 DFS (a,n,i,s);
}
int main ()
{
 int a[10][10],n,i,j,s[20],src,dest;
 printf ("Enter no. of Nodes in Graph\n");
 scanf ("%d",&n);
 printf ("Enter the connections of Graph in Adjacency Matrix\n");
 for (i=1;i<=n;i++)
 for (j=1;j<=n;j++)
 scanf ("%d",&a[i][j]);
 printf ("Enter the Source Node\n");
 scanf ("%d",&src);
 printf ("Enter the Destination Node\n");
 scanf ("%d",&dest);
 printf ("Source Node = %d\n",src);
 printf ("Destination Node = %d\n",dest);
 for(i=1;i<=n;i++)
 s[i]=0;
 DFS (a,n,src,s);
 if (s[src]==1 && s[dest]==1)
 printf ("Destination is Reachable from %d to %d\n",src,dest);
 else
 printf ("Destination not Reachable\n");
 return 0;
}
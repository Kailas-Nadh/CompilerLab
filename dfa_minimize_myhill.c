//DFA MINIMISATION USING MYHILL NERODE THEOREM
#include <stdio.h>
void main()
{
 int np,ns; int tm[6][2],i,j;int rm[6][6]; int fs[6];
 int prvs_sum=0,new_sum=0;
 printf("Enter the number of input symbols\n");
 scanf("%d",&np);
 printf("Enter the number of states\n");
 scanf("%d",&ns);

 printf("Enter the transition matrix\n");

 for(i=0;i<6;i++)
 {
 for(j=0;j<2;j++)
 {
 printf("Enter the transition for state q%d with input symbol %d\n",i,j);
 scanf("%d",&tm[i][j]);
 }
 }
 printf("Printing transition matrix\n"); //optional
 for(i=0;i<6;i++)
 {
 printf("\n");
 for(j=0;j<2;j++)
 {

 printf("%d ",tm[i][j]);
 }
 }


 for(i=0;i<6;i++)
 {
 printf("Enter 1 if the state q%d is final else 0",i);
 scanf("%d",&fs[i]);
 }

 //REDUCTION BEGINS!!

 for(i=0;i<6;i++) //initialising reduced matrix values to 0 before marking
 {
 for(j=0;j<6;j++)
 {
 rm[i][j]=0;
 }
 }

 // Marking pairs where one belongs to final state and the other belongs to non final

 for(i=0;i<6;i++)
 {
 for(j=0;j<i;j++)
 {
 if(fs[i]==1&&fs[j]==0)
 {
 rm[i][j]=1;
 prvs_sum=prvs_sum+rm[i][j];
 }
 else if(fs[i]==0&&fs[j]==1)
 {
 rm[i][j]=1;
 prvs_sum=prvs_sum+rm[i][j];
 }
 else
 prvs_sum=prvs_sum+rm[i][j];

 }
 }

 //Marking those unmarked pairs by checking equivalent transitions
 while(prvs_sum!=new_sum)
 {

 prvs_sum=new_sum;
 new_sum=0;
 for(i=0;i<6;i++)
 {
 for(j=0;j<i;j++)
 {
 if(rm[i][j]==0)
 {
 int k=tm[i][0];
 int l=tm[j][0];

 int m=tm[i][1];
 int n=tm[j][1];

 if(rm[k][l]==1||rm[m][n]==1)
 {
 rm[i][j]=1;
 new_sum=new_sum+rm[i][j];
 }

 }
 else
 new_sum=new_sum+rm[i][j];

 }
 }

 }

 printf("Printing final reduced matrix");
 for(i=0;i<6;i++)
 {
 printf("\n");
 for(j=0;j<i;j++)
 {
 printf("%d ",rm[i][j]);
 }
 }
}

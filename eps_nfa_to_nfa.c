#include<stdio.h>
int tm[10][10],ntm[10][10];
void main()
{
 int i,j,ns,ninp;
 int m=0,n=0;
 printf("Enter the number of states\n");
 scanf("%d",&ns);
 printf("Enter the number of input symbols including epsilon\n");
 scanf("%d",&ninp);

 printf("Enter the transition matrix\n");

 for(i=0;i<ns;i++)
 {
 for(j=0;j<ninp;j++)
 {
 if(j==ninp-1)
 {
 printf("Enter the transition for state %d on taking input epsilon else enter -1: ",i);
 scanf("%d",&tm[i][j]);
 }

 else
 {
 printf("Enter the transition for state %d on taking input %d: ",i,j);
 scanf("%d",&tm[i][j]);
 }
 

 }
 }

 printf("Printing transition matrix");

 for(i=0;i<ns;i++)
 {

 printf("\n");
 for(j=0;j<ninp;j++)
 {
 printf("%d ",tm[i][j]);
 }}

 //Checking for epsilon moves

 for(i=0;i<ns;i++)
 {


 if(tm[i][2]==-1) //no epsilon move
 {
 for(m=0;m<10;m++)
 ntm[i][m]=tm[i][m];
 }
 else
 {
 n=tm[i][2];
 for(m=0;m<10;m++)
 {
 if(tm[i][m]!=-1)
 ntm[i][m]=tm[i][m]*10+tm[n][m];
 else
 ntm[i][m]=tm[n][m];
 }
 }

 }

 printf("Printing new transition matrix\n");
 for(i=0;i<ns;i++)
 {
 printf("\n");
 for(j=0;j<ninp-1;j++)
 printf("%d ",ntm[i][j]);
 }


}

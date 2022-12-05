#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,totalStates,transTable[10][10],currentState,finalState[5],numofFinal,flag=0;
	char terminal1,terminal2,string[20];
	printf("\n Enter total no of states: ");
	scanf("%d",&totalStates);
	printf("\n Enter terminal1: ");
	scanf(" %c",&terminal1);
	printf("\n Enter terminal2: ");
	scanf(" %c",&terminal2);
	
	for(int i=0;i<totalStates;i++)
	{
		printf("State %d \n",i);
		printf("If the terminal is %c go to state: ",terminal1);
		scanf("%d",&transTable[i][0]);
		printf("If the terminal is %c go to state: ",terminal2);
		scanf("%d",&transTable[i][1]);
		
	}
	printf("\n\n*****TRANSITION TABLE*****\n\n");
	for(i=0;i<totalStates;i++)
	{
		printf("State %d: \t",i);
		for(j=0;j<2;j++)
		{
			printf("%d\t",transTable[i][j]);
		}
		printf("\n\n");
	}
	printf("Enter the initial state: ");
	scanf("%d",&currentState);
	printf("Enter the no of final states: ");
	scanf("%d",&numofFinal);
	printf("Enter the final states: ");
	for(i=0;i<numofFinal;i++)
	{
		scanf("%d",&finalState[i]);
	}
	printf("Enter the string: ");
	scanf("%s",string);
	
	for(i=0;string[i]!='\0';i++)
	{
		if(string[i]=='a'){
		currentState=transTable[currentState][0];
		}
		else if(string[i]=='b'){
		currentState=transTable[currentState][1];
		}
		
	}
	
	for(i=0;i<numofFinal;i++)
	{
		if(currentState=finalState[i]){
		flag=1;
		}
	}
	if(flag==1)
	{
	printf("String accepted...");
	}
	else
	{
	printf("String rejected...");
	}
	
	
	return 0;
}


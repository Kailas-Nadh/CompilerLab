#include<stdio.h>
#include<string.h>

int main()
{
 	char ch,arr[2000];
 	int i;
	FILE *fp;
	fp = fopen ("file.txt","r");
	while(!feof(fp))
	{
		ch=getc(fp);
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=' || ch == '|' || ch == '<' || ch == '>' || ch == '^' || ch == '?' || ch == ':' )
		   {
		   printf(" %c \t operator \n",ch);
		   continue;
		   }
		if(ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == '.' || ch == ',' || ch == '$' || ch == ';' )
			{
			printf(" %c \t special symbols \n",ch);
			continue;
			}
		arr[i]=ch;
		i++;
		if(ch==' ')
		{
			i=i-1;
			arr[i]='\0';
			if(strcmp(arr,"int")==0 || strcmp(arr,"char")==0 || strcmp(arr,"float")==0 )
			{
			printf("%s \t data type \n",arr);
			}
			i=0;
			strcpy(arr,"\0");
		}
	}
	fclose(fp);
	return 0;
}

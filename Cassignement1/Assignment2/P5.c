#include<stdio.h>
int characount(char s[],char c);
void main()
{
	char s[20];
	char c;
	int chara;
	printf("Enter String");
	gets(s);
	printf("Enter a character");
	c=getchar();
	chara=characount(s,c);
	printf("%c apperars %d times",c,chara);
}

int characount(char s[],char c)
{
	int i,count=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==c)
		{
		count++;	
		}
		
	}
	return count;
	
 } 
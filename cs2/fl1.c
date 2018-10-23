#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct directory
{
 char fname[10][10],dname[10];
 int fcnt;
}dir;

void main()
{
 char f[10];
 int ch,found,i;
 printf("\n enter directory name: ");
 scanf("%s",dir.dname);
 dir.fcnt=0;
while(1)
{
 printf("\n1.create file\t2.delete file\t3.display files\t4.search file\nenter your choice::\n");
 scanf("%d",&ch);
 switch(ch)
{
 case 1:
	printf("\n enter filename: ");
	scanf("%s",dir.fname[dir.fcnt]);
	dir.fcnt++;
	printf("\n file created\n");
	break;
case 2:
	found=0;
        printf("\nenter filename: ");
        scanf("%s",f);
	for(i=0;i<dir.fcnt;i++)
          if(strcmp(f,dir.fname[i])==0)
		{
		  strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
		  found=1;
		  dir.fcnt--;
		  break;
		}
	if(found==1)
		printf("\nfile deleted\n");
	else
		printf("\nfile not found\n");
	break;

	
case 3:
	for(i=0;i<dir.fcnt;i++)
		printf("\n%s\n",dir.fname[i]);
	break;
	
case 4: 
	found=0;
        printf("\nenter filename: ");
        scanf("%s",f);
	for(i=0;i<dir.fcnt;i++)
          if(strcmp(f,dir.fname[i])==0)
		{
		  found=1;
		  
		  break;
		}
	if(found==1)
		printf("\nfile found\n");
	else
		printf("\nfile not found\n");
	break;

default:printf("\ninvalid choice\n"); 
	exit(0);
}
}
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct directory
{
 char fname[10][10],dname[10];
 int fcnt;
}dir[10];

void main()
{
 int dcnt=0;
 char f[10],d[10];
int ch,i,found,found1,k;
while(1)
{
 printf("\n1.create directory\t2.create file in directory\t3.delete file from directory\t4.delete directory\t5.display files in a directory\t6.search file in a directory\nenter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nenter directory name: ");
	scanf("%s",dir[dcnt].dname);
        dir[dcnt].fcnt=0;
	dcnt++;
	break;
case 2: printf("\nEnter name of the directory -- ");
	scanf("%s",d);
	for(i=0;i<dcnt;i++)
	if(strcmp(d,dir[i].dname)==0)
	{
		printf("Enter name of the file -- ");
		scanf("%s",dir[i].fname[dir[i].fcnt]);
		dir[i].fcnt++;
		printf("File created");
		break;
	}
	if(i==dcnt)
		printf("Directory %s not found",d);
		break;
case 3: found=0,found1=0;
	printf("\nEnter name of the directory -- ");
	scanf("%s",d);
	for(i=0;i<dcnt;i++)
	{
		if(strcmp(d,dir[i].dname)==0)
		{
			found=1;
			printf("Enter name of the file -- ");
			scanf("%s",f);
			for(k=0;k<dir[i].fcnt;k++)
			{
				if(strcmp(f, dir[i].fname[k])==0)
				{
					found1=1;
					printf("File %s is deleted ",f);
					dir[i].fcnt--;
					strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
					break;
				}
			}
			if(found1==0)
			printf("File %s not found",f);
			
		}
	}
	if(found==0)
	printf("Directory %s not found",d);
	break;

case 4: found=0;
	printf("\nEnter name of the directory -- ");
	scanf("%s",d);
	for(i=0;i<dcnt;i++)
	{
		if(strcmp(d,dir[i].dname)==0)
		{
			found=1;
			printf("Directory %s deleted",dir[i].dname);
			strcpy(dir[i].dname,dir[dcnt].dname);
			for(k=0;k<dir[i].fcnt;k++)
			{
				strcpy(dir[i].fname[k],dir[dcnt].fname[k]);
			}
		}
	}
	if(found==0)
	printf("Directory %s not found",d);
	break;
	

case 5: if(dcnt==0)
		printf("\nNo Directory's ");
	else
	{
		printf("\nDirectory\tFiles");
		for(i=0;i<dcnt;i++)
		{
			printf("\n%s\t\t",dir[i].dname);
			for(k=0;k<dir[i].fcnt;k++)
				printf("\t%s",dir[i].fname[k]);
		}
	}
	break;

case 6: found=0,found1=0;
	printf("\nEnter name of the directory -- ");
	scanf("%s",d);
	for(i=0;i<dcnt;i++)
	{
		if(strcmp(d,dir[i].dname)==0)
		{       found=1;
			printf("Enter the name of the file -- ");
			scanf("%s",f);
			for(k=0;k<dir[i].fcnt;k++)
			{
				if(strcmp(f, dir[i].fname[k])==0)
				{       found1=1;
					printf("File %s is found ",f);
					break;
				}
			}
			if(found1==0)
			printf("File %s not found",f);
			
		}
	}
	if(found==0)
	printf("Directory %s not found",d);
	 break;

default:exit(0);
}
}
}

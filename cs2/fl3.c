#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE 0
#define DIR 1

struct dir
{
  char name[30];
  int type;
  struct dir *child;
  struct dir *parent;
  struct dir *next;
}*root,*pwd;

int main()
{
 struct dir *temp;
struct dir *t;
 char name[30];
 int cmd,i;
 root=(struct dir*)malloc(sizeof(struct dir));
 strcpy(root->name,"root");
 root->type=DIR;
 root->parent=NULL;
 root->child=NULL;
 pwd=root;
while(1)
{
 printf("\n1.list all files(ls)\t2.create directory(mkdir)\t3.create file(vi)\t4.change directory(cd)\t5.pwd\nenter your choice:");
 scanf("%d",&cmd);
 switch(cmd)
 {
  case 1:temp=pwd->child;
	 for(i=1;temp!=NULL;temp=temp->next)
	{
	  printf("%d",i);
	  if(temp->type==FILE)
		printf("(F)");
	  else
		printf("(D)");
	 printf("%s\n",temp->name);
 	}
	break;
case 2:printf("\n enter directory name:");
	scanf("%s",name);
	temp=pwd->child;
	i=0;
	for(;temp!=NULL;temp=temp->next)
	{
 	  if(strcmp(temp->name,name)==0)
		i=1;}	 
 	if(i==1)
		printf("\nname already in use");
	else
	{
	 t=(struct dir*)malloc(sizeof(struct dir));
	 strcpy(t->name,name);
	 t->type=DIR;
	 t->child=NULL;
	 t->next=NULL;
	 t->parent=pwd;
	if(pwd->child==NULL)
		pwd->child=t;
	else
	{
		temp=pwd->child;
		while(temp->next!=NULL)
		  temp=temp->next;
		temp->next=t;
	}}
	break;
case 3:printf("\nenter filename: ");
	scanf("%s",name);
	temp=pwd->child;
	i=0;
	for(;temp!=NULL;temp=temp->next)
	{	
		if(strcmp(temp->name,name)==0)
		 i=1;
	}
	if(i==1)
		printf("\n name already in use");
	else
	{t=(struct dir*)malloc(sizeof(struct dir));
	 strcpy(t->name,name);
	 t->type=FILE;
	 t->child=NULL;
	 t->next=NULL;
	 t->parent=pwd;
	if(pwd->child==NULL)
		pwd->child=t;
	else
	{
		temp=pwd->child;
		while(temp->next!=NULL)
		  temp=temp->next;
		temp->next=t;
	}}
	break;


case 4:		printf("\n enter directory name:");
		scanf("%s",name);
        	temp=pwd->child;
                i=0;
                for(;temp!=NULL;temp=temp->next)
                {
                    if(strcmp(temp->name,name)==0&&temp->type==DIR)
                    {
                        pwd=temp;
                        i=1;
                    }
                }
                if(strcmp(name,"..")==0)
                {
                    pwd=pwd->parent;
                    i=1;
                }
                if(i==0)
                    printf("Cannot find directory\n");
                break;		

case 5: printf("%s",pwd->name);
        temp=pwd->parent;
        while(temp!=NULL)
                {
                    printf("<%s",temp->name);
                    temp=temp->parent;
                }
        break;


default:exit(0);
     
}}}
	
 



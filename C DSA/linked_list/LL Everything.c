#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int info;
struct node *link;
}NODE;

NODE* create(NODE *start)//for creating a list
{
 NODE *temp,*t;
 int n,i;
 printf("Enter no of nodes you want to insert:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  temp=(NODE*) malloc(sizeof(NODE));
  printf("Enter data for node %d:",i+1);
  scanf("%d",&temp->info);
  temp->link=NULL;
  if(start==NULL)
   start=temp;
  else
  {
   t=start;
   while(t->link!=NULL)
    t=t->link;
   t->link=temp;
  }
 }
 return start;
}

void disp(NODE *start)//for printing a list
{
 NODE *t;
 printf("\nElements of the list:");
 for(t=start;t!=NULL;t=t->link)
 {
  if(t->link!=NULL)
   printf("%d->",t->info);
  else
   printf("%d",t->info);
 }
 printf("\n");
}

NODE* append(NODE *start)//append element at end
{
 NODE *t,*temp;
 temp=(NODE*) malloc(sizeof(NODE));
 printf("Enter data to be appended:");
 scanf("%d",&temp->info);
 for(t=start;t->link!=NULL;t=t->link);
 t->link=temp;
 temp->link=NULL;
 return start;
}

NODE* concat(NODE *s1,NODE *s2)//concatenate 2 lists
{
 NODE *t;
 t=s1;
 while(t->link!=NULL)
  t=t->link;
 t->link=s2;
 return s1;
}

NODE* fr(NODE *start)//free all nodes in a list
{
 NODE *t;
 t=start;
 while(t!=NULL)
 {
  t=start;
  start=t->link;
  free(t);
 }
 return start;
}

NODE* rev(NODE *start)//to reverse a list
{
 NODE *t1,*t2,*s;
 for(t1=start;t1->link!=NULL;t1=t1->link);
 s=t1;
 while(t1!=start)
 {
  for(t2=start;t2->link!=t1;t2=t2->link);
  t1->link=t2;
  t1=t2;
 }
 t1->link=NULL;
 return s;
}

NODE* dellast(NODE *start)//delete last element
{
 NODE *t,*t2;
 for(t=start;t->link->link!=NULL;t=t->link);
 t2=t->link;
 free(t2);
 t->link=NULL;
 return start;
}

NODE* deln(NODE *start)//delete nth element
{
 int i=1,n;
 NODE *t,*t2;
 printf("\nEnter pos no of element to be deleted:");
 scanf("%d",&n);
 t=start;
 if(n!=1)
 {
  while(i<n-1)
  {
   t=t->link;
   i++;
  }
  t2=t->link;
  t->link=t2->link;
  free(t2);
 }
 else
 {
  start=t->link;
  free(t);
 }
 return start;
}
NODE* sort(NODE*);
//to combine 2 ordered lists into a single ordered list
NODE* comb(NODE *s1,NODE *s2)
{
 s1=concat(s1,s2);
 s1=sort(s1);
 return s1;
}

NODE* uni(NODE *s1,NODE *s2)//to find the union of 2 lists
{
 NODE *s3,*t,*t2,*t3,*temp;
 int flag=1;
 s3=(NODE*) malloc(sizeof(NODE));
 s3=NULL;
 t=s1;
 while(t!=NULL)
 {
  temp=(NODE*) malloc(sizeof(NODE));
  temp->info=t->info;
  temp->link=NULL;
  if(s3==NULL)
   s3=temp;
  else
  {
   t2=s3;
   while(t2->link!=NULL)
    t2=t2->link;
   t2->link=temp;
  }
  t=t->link;
 }

 t2=s2;
 while(t2!=NULL)
 {
  t=s1;
  flag=1;
  while(t!=NULL)
  {
   if(t->info==t2->info)
   {
    flag=0;
    break;
   }
   t=t->link;
  }
  if(flag==1)
  {
   for(t3=s3;t3->link!=NULL;t3=t3->link);
   temp=(NODE*) malloc(sizeof(NODE));
   temp->info=t2->info;
   t3->link=temp;
   temp->link=NULL;
  }
  t2=t2->link;
 }
 return s3;
}

NODE* inter(NODE *s1,NODE *s2)//to find the intersection of 2 lists
{
 NODE *s3,*t1,*t2,*t3,*temp;
 s3=(NODE*) malloc(sizeof(NODE));
 s3=NULL;
 t1=s1;
 while(t1!=NULL)
 {
  t2=s2;
  while(t2!=NULL)
  {
   if(t1->info==t2->info)
   {
    temp=(NODE*) malloc(sizeof(NODE));
    temp->info=t1->info;
    temp->link=NULL;
    if(s3==NULL)
     s3=temp;
    else
    {
     for(t3=s3;t3->link!=NULL;t3=t3->link);
     t3->link=temp;
    }
    break;
   }
   t2=t2->link;
  }
  t1=t1->link;
 }
 return s3;
}

NODE* insertn(NODE *s)//to insert at nth position
{
 NODE *t,*t2,*temp;
 int n,i=1;
 printf("Enter data:");
 temp=(NODE*) malloc(sizeof(NODE));
 scanf("%d",&temp->info);
 printf("Enter position no at which element has to be inserted:");
 scanf("%d",&n);
 t=s;
 if(n!=1)
 {
  while(i<n-1)
  {
   t=t->link;
   i++;
  }
  t2=t->link;
  t->link=temp;
  temp->link=t2;
 }
 else
 {
  temp->link=s;
  s=temp;
 }
 return s;
}

NODE* del2(NODE *s)//delete every 2nd element in a list
{
 NODE *t1,*t2;
 t1=s;
 while(t1!=NULL)
 {
  t2=t1->link;
  t1->link=t2->link;
  free(t2);
  t1=t1->link;
 }
 return s;
}

NODE* sort(NODE *s)//to place elements in increasing order
{
 NODE *t1,*t2;
 int temp;
 for(t1=s;t1->link!=NULL;t1=t1->link)
 {
  for(t2=t1->link;t2!=NULL;t2=t2->link)
  {
   if(t1->info>t2->info)
   {
    temp=t1->info;
    t1->info=t2->info;
    t2->info=temp;
   }
  }
 }
 return s;
}

int sum(NODE *s)//to find the sum of elements in a list
{
 int sum=0;
 NODE *t;
 for(t=s;t!=NULL;t=t->link)
  sum+=t->info;
 return sum;
}

int elements(NODE *s)//to find the number of elements in a list
{
 int n=0;
 NODE *t;
 for(t=s;t!=NULL;t=t->link)
  n++;
 return n;
}

NODE* copy(NODE *s1)//to make a second copy of the list
{
 NODE *s2,*t,*temp,*t2;
 s2=NULL;
 t=s1;
 while(t!=NULL)
 {
  temp=(NODE*) malloc(sizeof(NODE));
  temp->info=t->info;
  temp->link=NULL;
  if(s2==NULL)
   s2=temp;
  else
  {
   t2=s2;
   while(t2->link!=NULL)
    t2=t2->link;
   t2->link=temp;
  }
  t=t->link;
 }
 return s2;
}

NODE* forward(NODE *s)//to forward a node by n positions
{
 NODE *t1,*t2,*t3;
 int n1,n2,i;
 printf("Enter position of the node you want to move:");
 scanf("%d",&n1);
 printf("Enter no of positions you want to move:");
 scanf("%d",&n2);
  t1=s;
  i=1;
  while(i<n1)
  {
   t1=t1->link;
   i++;
  }
  t2=s;
  i=1;
  while(i<n1+n2)
  {
   t2=t2->link;
   i++;
  }
  t3=s;
  if(t1!=s)
  while(t3->link!=t1)
   t3=t3->link;
  t3->link=t1->link;
  if(t1==s)
   s=s->link;
  t1->link=t2->link;
  t2->link=t1;
 return s;
}


void main()
{
 NODE *s1,*s2;
 int ch;
 s1=NULL;
 s2=NULL;
 while(1)
 {
  printf("Enter choice:\n");
  printf(" 1.Append element at end\n 2.Concatinate two lists\n");
  printf(" 3.Free all nodes in a list\n 4.Reverse a list\n");
  printf(" 5.Delete last element\n 6.Delete nth element\n");
  printf(" 7.Combine two ordered list into single ordered list\n");
  printf(" 8.Find union of two lists\n 9.Find intersection of two lists\n");
  printf("10.Insert after nth element\n11.Delete every second element\n");
  printf("12.Place elements in order\n13.Return sum of data\n");
  printf("14.Return number of elements\n15.Make second copy of list\n");
  printf("16.Move node forward to n positions\n17.Exit\n");
  scanf("%d",&ch);
  if(ch>0&&ch<=16)
   s1=create(s1);
   disp(s1);
  switch(ch)
  {
   case 1:s1=append(s1);break;
   case 2:s2=create(s2);disp(s2);s1=concat(s1,s2);break;

   case 3:s1=fr(s1);
   printf("List freed\n");
   disp(s1);
   break;

   case 4:s1=rev(s1);break;
   case 5:s1=dellast(s1);break;
   case 6:s1=deln(s1);break;
   case 7:s2=create(s2);disp(s2);s1=comb(s1,s2);break;
   case 8:s2=create(s2);disp(s2);s1=uni(s1,s2);break;
   case 9:s2=create(s2);disp(s2);s1=inter(s1,s2);break;
   case 10:s1=insertn(s1);break;
   case 11:s1=del2(s1);break;
   case 12:s1=sort(s1);break;
   case 13:printf("Sum of elements=%d",sum(s1));break;
   case 14:printf("Number of elements=%d",elements(s1));break;

   case 15:
   s2=copy(s1);
   printf("Second list:\n");
   disp(s2);
   break;

   case 16:s1=forward(s1);break;
   case 17:exit(0);break;
   default:printf("Wrong choice.Enter again");break;
  }
  if(ch!=3&&ch!=13&&ch!=14&&ch!=15&&ch>0&&ch<=16)
  {
   printf("\nResult:");
   disp(s1);
  }
   s1=fr(s1);
   s2=fr(s2);
 }
}

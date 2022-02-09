#include<stdio.h>
#include<string.h>
int flag=0;

int cqinsert(int *f,int *r,int q[],int n, int y)
{
  if(*r==n)
{
    *r=1;
 
}
  else{
    *r=*r+1;
}
  
  //overflow
  if(*f==*r){
   printf("OverFlow");
   return 0;
}
  //insert element
else{  
   
   
   if(*f==0)

    *f=1;
    q[*r] = y;
    return q[*r];
}
}

int cqdelete(int q[],int *f,int *r)
{
int y;
   if(*f==0)
{
  printf("Queue Underflow");
  return 0;
}
else
{
  y=q[*f];
  
  if(*f==*r){
   *f=*r=0;
 
}

else{
 *f=*f+1;

}
 return y;
}
}

  void display(int q[],int *f,int *r)
{
  int i;
  for(i=*f; i<=*r; i++)
  {
    printf("%d ",q[i]);
  }
 }


void main()
{
  int add;
  int choice;
  int pushed,poped;
  int n=4;
  int front=0,rear=0;
  int s[n];

 while(1){
       printf("\n1. enqueue; 2.dequeue; 3.display; -1. terminate:");
       scanf("%d",&choice);
       if(choice==1){
          while(1){
               int x;
               printf("enter the element to be pushed:");
               scanf("%d",&x);
        
               pushed=cqinsert(s,&front,&rear,n,x);
              if(pushed == 0)
                break;
            else
               printf("element pushed\n");
}
}

else if(choice==2)
{
   while(1)
{
     poped=cqdelete(s,&front,&rear);
          if(poped==0)
             break;
          else
              printf("\n element popped:%d\n",poped);
  }
 }

else if(choice == 3)
{
  display(s,&front,&rear);
}
else if(choice==-1)
{
  break;
}
}
}

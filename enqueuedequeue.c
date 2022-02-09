#include<stdio.h>
#include<string.h>

int flag=0;

 int enqueue(int Q[],int *F,int *R,int N,int ele)
 {
   if(flag==0){
     *F = *R = 0;
      flag=1;
   }
  if(*R>=N){
    printf("Queue Overflow:");
    return 0;
   }
  else{
      *R=*R+1;
       *F =1;
       Q[*R]=ele;
      return Q[*R];
   }

 }

int dequeue(int Q[],int *F,int *R)
{
  int y;
  if(*F==0){
    printf("Queue Underflow\n");
    return 0;
  }
  else
    if(*F == *R){
     *F =*R =0;
  }
    else{
       y=Q[*F];
       *F = *F +1;
       return y;
     }
  }
 

 void display(int Q[],int *F,int *R){
  int i;
  for(i=*F; i<=*R; i++)
  {
     printf("%d",Q[i]);
 }
}

void main()
{
  int add;
  int choice;
  int n= 3;
  int pushed,poped; 
  int front=0,rear=0;
  int s[n];

  while(1){
        printf("1.Insert element to queue \n 2.Delete element from queue\n 3.Display all elements of queue\n 4.Quit\n");
        scanf("%d",&choice);
        if(choice == 1){
            while(1){
                     int x;
                        printf("Enter element to be pushed:");
                        scanf("%d",&x);
                     
                        pushed = enqueue(s,&front,&rear,n,x);

                         if(pushed ==0)
                              break;
                           else
                              printf("element pushed\n");
        }
   }
 
          else if(choice ==2){
                    while(1){
                          poped= dequeue(s,&front,&rear);
                       if(poped ==0)
                            break;
                        else
                              printf("\nElement poped:%d\n",poped);
          }
   }
         else if(choice == 3){
                   display(s,&front,&rear);
        }
             else if(choice ==-1){
                 break;
     }
}
}

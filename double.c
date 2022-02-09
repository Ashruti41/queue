#include<stdio.h>
#include<stdlib.h>

int MAX= 5;
void insert_rear(int deque_arr[MAX],int *front,int *rear,int Size,int y)
{
    int y;
    if((*front == 0 && *rear == MAX-1) || (*front == *rear+1))
    {   printf("Queue Overflow\n");
        return;}
    if (*front == -1)  
    {   *front = 0;
        *rear = 0;}
    else
    if(*rear == MAX-1)  
        *rear = 0;
    else
        *rear = *rear+1;
         
    printf("Input the element for adding in queue : ");
    scanf("%d", &y);
    deque_arr[*rear] = y ;
}

void insert_front(int deque_arr[MAX],int *front,int *rear,int MAX,int y)
{   int y;
    if((*front == 0 && *rear == MAX-1) || (*front == *rear+1))
    {   printf("Queue Overflow \n");
        return;  }
    if (*front == -1)
    {   *front = 0;
        *rear = 0;    }
    else
    if(*front== 0)
        *front=MAX-1;
    else
        *front=*front-1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &y);
    deque_arr[*front] = y ; 
 }

void delete_front(int deque_arr[MAX],int *front,int *rear)
{   if (*front == -1)
    {   printf("Queue Underflow\n");
        return ;
    }
    printf("Element deleted from queue is : %d\n",deque_arr[*front]);
    if(*front == *rear) 
    {   *front = -1;
        *rear=-1;
    }
    else
        if(*front == MAX-1)
            *front = 0;
        else
            *front = *front+1;
}

void delete_rear(int deque_arr[MAX],int *front,int *rear)
{
    if (*front == -1)
    {
        printf("Queue Underflow\n");
        return ;
    }
    printf("Element deleted from queue is : %d\n",deque_arr[*rear]);
    if(*front == *rear) /*queue has only one element*/
    {
        *front = -1;
        *rear=-1;
    }
    else
        if(*rear == 0)
            *rear=MAX-1;
        else
            *rear=*rear-1;    }

void display_queue(int deque_arr[MAX],int *front,int *rear)
{   
    int front_pos = front,rear_pos = rear;
     
    if(*front == -1)
    {   printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if( front_pos <= rear_pos )
    {   
        while(front_pos <= rear_pos)
        {
            printf("%d ",deque_arr[front_pos]);
            front_pos++;
        }
    }
    else
    {
        while(front_pos <= MAX-1)
        {   printf("%d ",deque_arr[front_pos]);
            front_pos++;    
        }
        front_pos = 0;
        while(front_pos <= rear_pos)
        {   
            printf("%d ",deque_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

void input_que()
{   int choice;
    int s[MAX],y;
    int f=0,r=0;
    do
    {   printf("1.Insert at rear\n");
        printf("2.Delete from front\n");
        printf("3.Delete from rear\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
 
        switch(choice)
        {   case 1:
            insert_rear(s,&f,&r,MAX,y);
            break;
         case 2:
            delete_front(s,&f,&r);
            break;
         case 3:
            delete_rear(s,&f,&r);
            break;
         case 4:
            display_queue(s,&f,&r);
            break;
         case 5:
            break;
         default:
            printf("Wrong choice\n");
        }
    }while(choice!=5);
}

void output_que()
{   int choice;
    int s[MAX],y;
    int f=0,r=0;
    do
    {   printf("1.Insert at rear\n");
        printf("2.Insert at front\n");
        printf("3.Delete from front\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:
            insert_rear(s,&f,&r,MAX,y);
            break;
         case 2:
            insert_front(s,&f,&r,MAX,y);
            break;
         case 3:
            delete_front(s,&f,&r);
            break;
         case 4:
            display_queue(s,&f,&r);
            break;
         case 5:
            break;
         default:
            printf("Wrong choice\n");
        }
    }while(choice!=5);
}

 int main()
{   int choice;
    printf("1.Input restricted dequeue\n");
    printf("2.Output restricted dequeue\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1 :
        input_que();
        break;
     case 2:
        output_que();
        break;
     default:
        printf("Wrong choice\n");
    }
}

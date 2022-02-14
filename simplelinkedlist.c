#include<stdio.h>
#include<stdlib.h>


struct node
{
  int info;
  struct node *link;
};

void display(struct node *);
int count(struct node *);
struct node* insert(int ,struct node *);
struct node* insertend(int , struct node *);
struct node* insert_pos(int ,struct node *);
struct node* delete(struct node *,struct node *);
struct node* copy(struct node *);



void main()
{

struct node *first,*second,*third;
first = (struct node *)malloc(sizeof(struct node));
second = (struct node *)malloc(sizeof(struct node));
third = (struct node *)malloc(sizeof(struct node));


first->info=1;
first->link=second;

second->info=2;
second->link=third;

third->info=3;
third->link=NULL;

//printf("%d %p ",first->info,first->link);
//printf("%d %p %d",second->info,second->link,third->info);
display(first);
first=insert(25,first);
printf("\nafter insertion\n");
display(first);
printf("\ntotal number %d\n",count(first));
printf("\nat the end of the input\n");
first=insertend(30,first);
display(first);
printf("\nenter\n");
first=insert_pos(28,first);
display(first);
printf("\nDelete at first\n");
first=delete(second,first);
display(first);
first=copy(first);
display(first);

}

    void display(struct node *first)
     {
       struct node *save;
       save=first;
       do
        {
        printf("%d,",save->info);
        save=save->link;
        }
         while(save!=NULL);
       }

  int count(struct node *first)
  {
   int c=0;
   struct node *save;
    save=first;
    if(save == NULL)
    return c;
  else
  {
   while(save!=NULL){
    c++;
    save = save->link;
   }
  return c;
 }
}


 struct node* insert(int x,struct node *first)
  {
 struct node *new;
  new= (struct node *)malloc(sizeof(struct node));
 if(new==NULL)
 {
   printf("Overflow\n");
   return 0;
  }
  else
   {
     new->info=x;
     new->link=first;
     return new;
  }
}


struct node* insertend(int x, struct node *first)
{
  struct node *new,*save;
  new= (struct node *)malloc(sizeof(struct node));
  save= first;
  new->info=x;
   if(first == NULL)
  {
    new->link = NULL;
    return new;
  }
  else{
    while(save->link!=NULL)
   {
     save= save->link;
   }
  save->link = new;
  return first;
}
}


struct node* insert_pos(int x,struct node *first)
{
  struct node *new,*save;
  new= (struct node *)malloc(sizeof(struct node));
  save=first;
   new->info=x;
  
   if(first== NULL){
        new->link = NULL;
        return new;
      }
  else{
      if(new->info <= first->info){
           new->link= first;
           return new;
       }
   while(save->link!= NULL && new->info>=save->link->info){  
    save = save->link;
   }
      new->link= save->link;
      
      save->link = new;
        return first;
  }
}


struct node* delete(struct node *x,struct node *first)
{
  if(first == NULL){
    printf("Underflow");
    return 0;
  }
   struct node *new,*save;
   new= (struct node *)malloc(sizeof(struct node));
   save= first;

   while(save !=x && save->link !=NULL){
       new= save;
       save = save->link;
   }
   if(save!=x)
  {
    printf("Element not found");
    return 0;
    }
    if(x==first){
      first=first->link;
      return first;
    }
    else{
      new->link = x->link;
      return first;
     }

   free(x);
}


   struct node* copy(struct node *first)
  {
    struct node *new,*save,*pred,*begin;
    new = (struct node *)malloc(sizeof(struct node));
    if(first == NULL){
     printf("empty\n");
      return NULL;
     }
     
     if(new== NULL){
     printf("underflow");
    }

    new->info = first->info;
    begin = new;
    save= first;

    pred= new;
    while(save->link!=NULL)
    {
      if(new ==NULL){
      printf("underflow");
      return NULL;
    }
     printf("AB");
     new->info = save->info;
     new->link = new;
     pred = new;
     save = save->link; 
    }
    new->link = NULL;
   return begin;
 }
     

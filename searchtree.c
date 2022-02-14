#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *l;
 struct node *r;
};

void inorder(struct node *);

struct node* search(struct node *root,int x)
{
 if(root==NULL || root->data==x)
  return root;
else if(x>root->data)
  return search(root->r,x);
 else
 return search(root->l,x);
}

 struct node* find_minimum(struct node *root)
 {
  if(root==NULL)
  return 0;
  else if(root->l!=NULL)
  return find_minimum(root->l);
 return root;
}

struct node* new_node(int x)
{
  struct node *p;
  p = malloc(sizeof(struct node));
  p->data = x;
  p->l = NULL;
  p->r = NULL;
 return p;
}

struct node* insert(struct node *root,int x)
{
  if(root==NULL)
   return new_node(x);
  else if(x>root->data)
   root->r = insert(root->r,x);
  else
   root->l = insert(root->l,x);
 return root;

}

struct node* delete(struct node *root,int x)
{
  if(root==NULL)
   return 0;
 if(x>root->data)
   root->r = delete(root->r,x);
  else if(x<root->data)
   root->l = delete(root->l,x);
else
{
  if(root->l==NULL && root->r==NULL)
  {
    free(root);
    return NULL;
  }
   else if(root->l==NULL ||root->r==NULL)
  {
    struct node *temp;
    if(root->l==NULL)
     temp = root->r;
   else
     temp = root->l;
   free(root);
  return temp;
}
else
        {
            struct node *temp = find_minimum(root->r);
            root->data = temp->data;
            root->r = delete(root->r, temp->data);
        }
    }
    return root;
}



void inorder(struct node *root)
{
    if(root!=NULL) 
    {
        inorder(root->l); 
        printf(" %d ", root->data);
        inorder(root->r);
    }
}

int main()
{
 struct node *root;
 root = new_node(50);
 insert(root,25);
 insert(root,22);
 insert(root,15);
 insert(root,40);
 insert(root,30);
 insert(root,75);
 insert(root,60);
 insert(root,80);
 insert(root,90);

inorder(root);
printf("\n");

if(search(root,50))
{
printf("found\n");
}
else{
printf("not found");
}
root = delete(root,90);
root = delete(root,75);

inorder(root);
printf("\n");
return 0;
}
 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *l, *r;
};
//function prototype
void printCurrentLevel(struct node* root,int level);
int height(struct node* node);
struct node* newNode(int data);


void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for(i=0;i<=h;i++)
     printCurrentLevel(root,i);
}

void printCurrentLevel(struct node* root,int level)
{
    if(root==NULL)
    return;
    if(level==1)
    printf("%d ",root->data);
    else if(level>1){
        printCurrentLevel(root->l,level-1);
        printCurrentLevel(root->r,level-1);
    }
}

int height(struct node* node)
{
    if(node==NULL)
     return 0;
    else{
        int leftheight = height(node->l);
        int rightheight = height(node->r);
        
        if(leftheight>rightheight)
        return (leftheight+1);
        else
         return (rightheight+1);
    }
}

struct node* newNode(int data)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->l = NULL;
    node->r = NULL;
    return (node);
}

int main()
{
    struct node* root = newNode(1);
    root->l = newNode(2);
    root->r = newNode(3);
    root->l->l = newNode(4);
    root->l->r = newNode(5);
    root->r->r = newNode(7);
    root->l->l->l = newNode(8);
    root->l->l->r = newNode(9);
    root->l->r->l = newNode(10);
    root->l->r->r = newNode(11);
    root->r->l->l = newNode(12);
    root->r->l->r = newNode(13);
    root->r->r->l = newNode(14);
    root->r->r->r = newNode(15);
    
    printLevelOrder(root);
    return 0;
}

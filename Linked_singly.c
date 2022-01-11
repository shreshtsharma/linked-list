#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
     struct node *next;
};
typedef struct node node;
node *insert_at_end(node *head);
node *insert_at_begin(node *head);
node *insert_in_middle(node *head, int pos);
node *delete_begin(node *head);
node *delete_end(node *head);
node *delete_middle(node *head, int pos);
void deleteafter(node*head);
node*  deleteall(node*temp);
void display(node *head);
int main()
{
    node *head = NULL;
    int choice;
    int pos;
    do
    {
        printf("enter your choice\n");
        printf("1.insert at begining\t");
        printf("2.insert at end\t");
        printf("\t3.insert in middle\t");
        printf("4.display\t");
        printf("5.delete a node from begining\t");
        printf("6.delete a node from end\t");
        printf("7.delete a node from middle\t");
        printf("8.delete all nodes after a node\t");
        printf("0.quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insert_at_begin(head);
            break;
        case 2:
            head = insert_at_end(head);
            break;
        case 3:
            printf("enter position at which you want to enter\n");
            scanf("%d", &pos);
            head = insert_in_middle(head, pos);
            break;
        case 4:
            display(head);
            break;
        case 5:
            head = delete_begin(head);
            break;
        case 6:
            head = delete_end(head);
            break;
        case 7:
            printf("enter position to delete\n");
            scanf("%d", &pos);
            head = delete_middle(head, pos);
            break;
        case 8:deleteafter(head);
        break;
        }
    } while (choice);
}
node *insert_at_begin(node *head)
{
    node *new = (node *)malloc(sizeof(node));
    printf("enter data\n");
    scanf("%d", &new->data);
    new->next = head;
    head = new;
    return head;
}
node *insert_at_end(node *head)
{
    node *new = (node *)malloc(sizeof(node));
    printf("enter data\n");
    scanf("%d", &new->data);
    node *temp = head;
    if (head == NULL)
    {
        new->next = head;
        head = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    return head;
}
node *insert_in_middle(node *head, int pos)
{
    node *new = (node *)malloc(sizeof(node));
    printf("enter data\n");
    scanf("%d", &new->data);
    if (pos == 1 || head == NULL)
    {
        new->next = head;
        head = new;
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        new->next = temp->next;
        temp->next = new;
    }
    return head;
}
node *delete_begin(node *head)
{
    if (head == NULL)
        printf("the list is empty\n");
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
node *delete_end(node *head)
{
    if (head == NULL)
    {
        printf("the list is empty\n");
        return head;
    }
    node *temp1 = head;
    while (temp1->next->next != NULL)
    {
        temp1 = temp1->next;
    }
    node *temp2 = temp1->next;
    temp1->next = NULL;
    free(temp2);
    return head;
}
node *delete_middle(node *head, int pos)
{
    if (head == NULL)
    {
        printf("the list is empty\n");
        return head;
    }
    node *temp1 = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp1 = temp1->next;
    }
    node *temp2 = temp1->next;
    temp1->next = temp1->next->next;
    free(temp2);
    return head;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("list is empty!!\n");
    }
    else
    {
        while (head != NULL)
        {
            printf("%d\t", head->data);
            head = head->next;
        }
        printf("\n");
    }
}
void deleteafter(node*head)
{
    node*temp=head;
        int data;
    printf("enter data\n");
    scanf("%d",&data);
   while(temp!=NULL)
   {
    if(temp->data==data)
    {
        break;
    }
    else
    {
        temp=temp->next;
    }

   }
   if(temp==NULL)
   {
       printf("data not found\n");
   }
   else
    deleteall(temp);
    
}
node*  deleteall(node*temp)
{
    if(temp->next==NULL)
    {
        free(temp);
    }
    else
    {
        temp->next=deleteall(temp->next);
        return temp->next;
    }
}
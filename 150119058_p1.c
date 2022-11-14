#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* create_node(){
    node * null_node=(node*) malloc(sizeof(node));;
    null_node->data=0;
    null_node->next=(node*) malloc(sizeof(node));
    null_node->next=NULL;

    return null_node;
}
////////PRİNT THE LL////////////////
void printLinkedlist(struct node *p,FILE *f_out) {
  while (p != NULL) {
    printf("%d", p->data);
    fprintf(f_out,"%d",p->data);
    p = p->next;
  }
  fprintf(f_out,"\n");
}
/////////   REVERSE THE LİSTS /////////////
static void reverse(node** head_ref)
{
    node* prev = NULL;
    node* current = *head_ref;
    node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
/////////// REARRENGİNG THE NUMBER TO BASE NUMBER SYSTEM ///////////////
void even_out(struct node *p,int BASE) {
    int k;
  while (p != NULL) {
    if (p->data>=BASE)
    {
        k=p->data/BASE;
        p->next->data+=k;
        p->data=p->data%BASE;
    }
    p = p->next;
  }
}

//////////////   MULTİPLYİNG     ////////////////
node * based(node*head,node*header){
    node * result=create_node();
    node * result1;
    node * res=result;
    node*head1=head;
    while (header!=NULL)
    {
        result1=res;
        head=head1;
        while (head != NULL)
        {
            node * asd=create_node();
            result1->data+=head->data*header->data;
            head=head->next;
            if (result1->next==NULL)
            {
                result1->next=asd;
            }
            
            result1=result1->next;
        }
        
        header=header->next;
        res=res->next;
    }
    return result;
}



int main()
{   
    int var;
    node * head=create_node();
    node * head1=head;

    node * header=create_node();
    node * header1=header;

    char file_name[50];
    scanf("%s",&file_name);

    FILE *file=fopen(file_name, "r");
//creating linked lists
    do
    {
        if(var=='\n')
            break;
        node * asd=create_node();
        asd->data=var-48;
        head1->next=asd;
        head1=head1->next;
    }while ((var = fgetc (file)) != EOF );
    head=head->next->next;
    var=0;
    do
    {
        if(var=='\n')
            break;
        node * asd=create_node();
        asd->data=var-48;
        header1->next=asd;
        header1=header1->next;
    }while ((var = fgetc (file)) != EOF );
////////// BASE ///////////////////
    var=fgetc(file)-48;
/////////////////////////////////////////
    header=header->next->next;
    reverse(&head);
    reverse(&header);
//checking the lists


node * result =create_node();
result=based(head,header);
even_out(result,var);

reverse(&head);
reverse(&header);
reverse(&result);

FILE *f_out=fopen("150119058_p1_output.txt","a");
printf("\n");
printLinkedlist(head,f_out);
printf("\n");
printLinkedlist(header,f_out);
printf("\n");
printLinkedlist(result,f_out);
}

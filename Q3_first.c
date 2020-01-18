#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int size=0, size2=0;;
int arr1[30];
typedef struct BT_convert
{
   int data;
   struct BT_convert *left, *right;
}BT_convert;

BT_convert *t1, *t2;

struct  BT_convert *insert(struct BT_convert *head, int data[], int l, int e){
   if(l<e){
    printf("\n check");
    struct BT_convert *temp=(BT_convert*)malloc(sizeof(BT_convert));
    temp->data=data[l];
    printf(" arr =%d %d %d ",data[l], l, e);
    temp->left=temp->right=NULL;
    head=temp;
    if((2*l+1)<e)
        head->left=insert(head->left,data,2*l+1,e);
    if(2*l+2<e)
        head->right=insert(head->right,data,2*l+2,e);

   }
   return head;
}

void inorder(BT_convert *head){
    if(head==NULL)
        return;
    inorder(head->left);
    printf("%d ",head->data);
    arr1[size]=head->data;
    size++;
    inorder(head->right);
}
void search(BT_convert *head, int ele);


int main()
{
   FILE *fp1, *fp2;
   fp1=fopen("Input.txt","r");
   fp2=fopen("Output.txt","w");
    BT_convert *start=NULL,  *t3=NULL;
    t1=(BT_convert*)malloc(sizeof(BT_convert));
    t2=(BT_convert*)malloc(sizeof(BT_convert));
    t1->left=t1->right=NULL;
    t2->left=t2->right=NULL;
   if(fp1==NULL  || fp2==NULL){
      printf("Error in file 1 or file 2");
      exit(0);
   }
   int  t, n, i, min, j, count=0, pos;
   n=fgetc(fp1)-48;
   fgetc(fp1);
   int *arr=(int *)malloc(n*sizeof(int));
   printf("%d \n",n);
   for(i=0;i<n;i++)
   { fscanf(fp1,"%d ",&arr[i]);

   }
     for(i=0;i<n;i++)
        printf("%d ",arr[i]);
     printf("\n");
     start=insert(start,arr,0,n);
     printf("\nBinary tree : ");
     inorder(start);

     printf("Also By Array :");
     for(i=0;i<n;i++)
        printf("%d ", arr1[i]);
     printf("\n");

     for(i=0;i<n-1;i++){
        min=arr1[i];
        for(j=i;j<n;j++){
            if(arr1[j]<=min){
               min=arr1[j];
               pos=j;
            }
        }
        
        
        if(arr1[i]!=arr1[pos]){

           count++;
           t3=start;
           search(start,arr1[i]);
           
           t2=t1;
           start=t3;
           search(start, arr1[pos]);
         
           t1->data=t1->data + t2->data;
           t2->data = t1->data - t2->data;
           t1->data = t1->data - t2->data;
           start=t3; 
         }
         t=arr1[i];
         arr[i]=arr1[pos];
         arr1[pos]=t;
     }
      
     printf("\n count=%d \n",count);
     inorder(start);
     fprintf(fp2,"%d ",count); 
     printf("\n Successsfully written ");
    free(fp1);
    free(fp2);

   return 0;
}

void search(BT_convert *head, int ele){
   if(head==NULL)
   {
      return ; 
   }
   if(head->data==ele){
      t1=head;
    
   }
  
   search(head->left,ele);
   
    if(head->data==ele){
      t1=head;
     
   }
   search(head->right, ele);
    if(head->data==ele){
      t1=head;
      
   }
}

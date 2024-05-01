#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;


struct node{
  string name;
  int count;
  struct node*child[10];
  
}*root;//variable

class GT{
  public:
       void get();
       void display(node*ptr);
  GT(){
   root=NULL;
  }
};



void GT :: get(){
    root=new node;
    cout<<"Enter name of book:";
    cin>>root->name;
    cout<<"Enter no of chapters:";
    cin>>root->count;
    
    for(int i=0; i<root->count;i++){
        root->child[i]=new node;
        cout<<"Enter chapter "<<i+1<<" name :";
        cin>>root->child[i]->name;
        cout<<"No. of section :";
        cin>>root->child[i]->count;
        
        for(int j=0; j<root->child[i]->count;j++){
        root->child[i]->child[j]=new node;
        cout<<"Enter section "<<j+1<<" name : ";
        cin>>root->child[i]->child[j]->name;
        cout<<"No. of sub section :";
        cin>>root->child[i]->child[j]->count;
        
        for(int k=0; k<root->child[i]->child[j]->count;k++){
        root->child[i]->child[j]->child[k]=new node;
        cout<<"Enter sub section "<<k+1<<" name : ";
        cin>>root->child[i]->child[j]->child[k]->name;
        
    }
    }
    }
}



void GT :: display(node *ptr)
{
  if(root!=NULL){
   cout<<"Book : "<<ptr->name<<endl<<endl; 
   for(int i=0; i<root->count;i++){
     cout<<"Chapter "<<i+1<<" : "<<ptr->child[i]->name<<endl;
     
     for(int j=0; j<ptr->child[i]->count;j++){
     cout<<"Section "<<j+1<<" : "<<ptr->child[i]->child[j]->name<<endl;
     
      for(int k=0; k<ptr->child[i]->child[j]->count;k++){
     cout<<"sub section "<<k+1<<" : "<<ptr->child[i]->child[j]->child[k]->name<<endl;
     }cout<<"\n\n";
   }cout<<"\n\n";
   }
  }
  else{
     cout<<"First enter the book:";
     }
  }

int main(){
     int choice;
     GT t;
     while(1){
        cout<<"\n1]Create Book \n2]Display book\n3]Exit ";
        cout<<"\n\nEnter your choice :";
        cin>>choice;
        switch(choice){
         case 1 :
          t.get();
          break;
         case 2 :
           t.display(root);
           break;
         case 3:
            break;  
         default:
            cout<<"Wrong choice"; 
            break;
        }
     }
     return 0;
}

#include<iostream>
#define MAX_SIZE 10
using namespace std;

class priority_queue{
    private:
          string queue[MAX_SIZE];
          int priority_val[MAX_SIZE];

          int front , rear;

     public:
            priority_queue(){
                front=-1;
                rear=-1;
            }

     bool is_empty(){return front==-1;}

     bool is_full(){return rear== MAX_SIZE-1;}

     void enqueue(string data, int priority){
        if(is_full()){
            cout<<"the queue is full";
        return;
        }
        if(is_empty()){
            front=rear=0;
            queue[rear]=data;
            priority_val[rear]=priority;
        }
        else{
            int i;
            rear++;
            for( i= rear-1;i>=front;i--){
                if(priority_val[i]<priority){
                    queue[i+1]=queue[i];
                    priority_val[i+1]=priority_val[i];

                }
                else{
                    break;
                }

            }
            queue[i+1]=data;
            priority_val[i+1]=priority;
        }
     }

     string dequeue(){
        if(is_empty()){
            cout<<"The queue is empty ";
        return "";
        }
        string data =queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
        return data;

     }

     int get_priority(){
        if(is_empty()){
            return -1;
        }
        else{
            return priority_val[front];
        }
     }

     void display(){
        if(is_empty()){
            cout<<"queue is empty";
        }
        else{
            for(int i=front;i<rear;i++){
                cout<<"Queue is"<<priority_val[i]<<";"<<queue[i]<<endl;
            }
            cout<<endl;
        }
     }
};

int main(){
    int ch=0;
    priority_queue p;
    cout<<"The priority is as 0=General paiteint , 1 = Non serious paitient 2= Serious paitent";
    string name;
    int priority;
    do{
        cout<<"---------MENU-----------\n1]Add paitent\n2]delete paitent\n3]display paitent\n4]Exit";
        cout<<"Enter your choice";
        cin>>ch;
        switch(ch){
           case 1: cout<<"Enter name of paitent :";
           cin>>name;
           cout<<"Enter the condition of paitent: ";
           cin>>priority;
           p.enqueue(name,priority);
           break;

           case 2: 
                 name=p.dequeue();
                 priority=p.get_priority();
                 cout<<"The paitent "<<name<<"with priority "<<priority<<"is removed";
                 break;

           case 3:
                p.display();
                break;

            case 4:
                 break;

            default:
                 cout<<"Invalid choice";
                 break;
        }
    }while(ch!=4);
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node(int data){
    this->data=data;
    this->next=nullptr;
  }
};

void print(Node *head){
  Node *curr=head;
  while(curr){
    cout<<curr->data<<"->";
    curr=curr->next;
  }
  cout<<"nullptr"<<endl;
}

Node *insertAtHead(Node *head, int data){
  if(!head){
    Node *newNode=new Node(data);
    return newNode;
  }
  Node *newNode=new Node(data);
  newNode->next=head;
  return newNode;
}

Node* insertAtEnd(Node *head, int data){
  if(!head) return new Node(data);
  Node *curr=head;
  while(curr->next){
    curr=curr->next;
  }
  Node *newNode=new Node(data);
  curr->next=newNode;
  newNode->next=nullptr;
  return head;
}

Node *insertAfterValue(Node *head, int data, int value){
  if(!head) return nullptr;
  Node *curr=head;
  bool flag=false;
  while(curr){
    if(curr->data==value){
      Node *newNode=new Node(data);
      newNode->next=curr->next;
      curr->next=newNode;
      curr=curr->next;
      flag=true;
    }
    curr=curr->next;
  }
  if(flag==false){
    cout<<"No such value found..."<<endl;
  }
  return head;
}

Node* deleteHead(Node *head){
  if(!head) return nullptr;
  Node *curr=head->next;
  head=curr;
  return head;
}

Node* deleteTail(Node *head){
  if(!head || !head->next){
    delete head;
    return nullptr;
  }
  Node *temp=head;
  while(temp->next->next){
    temp=temp->next;
  }
  Node *todelete=temp->next;
  temp->next=nullptr;
  delete todelete;
  return head;
}

Node* deleteFromSpecificValue(Node *head, int value){
  if(!head) return nullptr;
  if(head->data==value){
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
  }
  Node *curr=head;
  while(curr){
    if(curr->next->data==value){
      Node *todelete=curr->next;
      curr->next=curr->next->next;
      delete todelete;
      return head;
    }
    curr=curr->next;
  }
  cout<<"No such value exists.."<<endl;
}

int lengthOfList(Node *head){
  if(!head) return 0;
  int l=0;
  Node *curr=head;
  while(curr){
    curr=curr->next;
    l++;
  }
  return l;
}

bool searchInList(Node *head, int value){
  if(!head) return false;
  Node *curr=head;
  while(curr){
    if(curr->data==value){
      return true;
    }
    curr=curr->next;
  }
  return false;
}
int main(){
  Node *head=new Node(1);
  head->next=new Node(2);
  head->next->next=new Node(3);
  head->next->next->next=new Node(4);

  cout<<"\ninitial List: ";
  print(head);

  cout<<"after inserting 5 at head: ";
  head=insertAtHead(head, 5);
  print(head);

  cout<<"after inserting 6 at end: ";
  head=insertAtEnd(head, 6);
  print(head);

  cout<<"after inserting 7 after 3: ";
  head=insertAfterValue(head, 7, 3);
  print(head);
  
  cout<<"after deleting head: ";
  head=deleteHead(head);
  print(head);

  cout<<"after deleting tail: ";
  head=deleteTail(head);
  print(head);

  cout<<"after deleting 3: ";
  head=deleteFromSpecificValue(head, 3);
  print(head);

  cout<<"length of list is: "<<lengthOfList(head)<<endl;
  cout<<"searching 2 in list: "<<searchInList(head, 2);
  return 0;
}
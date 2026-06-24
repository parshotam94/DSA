#include<bits/stdc++.h>
using namespace std;
class LRU{
    private:
    class Node{
        public:
        int key, value;
        Node *prev, *next;
        Node(int key, int value){
            this->key=key;
            this->value=value;
            prev=nullptr;
            next=nullptr;
        }
    };
    Node *head;
    Node *tail;
    int capacity;
    unordered_map<int, Node*>mpp;
    
    void deleteNode(Node *node){
        Node *prevNode=node->prev;
        Node *nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    void insertNode(Node *node){
        Node *temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
    }
    public:
    LRU(int capacity){
        this->capacity=capacity;
        head=new Node(-1, -1);
        tail=new Node(-1, -1);
        head->next=tail;
        tail->prev=head;
    }
        
        int get(int key){
            if(mpp.find(key)==mpp.end()) return -1;
            Node *node=mpp[key];
            deleteNode(node);
            insertNode(node);
            return node->value;
        }
        
        void put(int key, int value){
            //if key exists
            if(mpp.find(key)!=mpp.end()){
                Node *temp=mpp[key];
                deleteNode(temp);
                mpp.erase(key);
                delete temp;
            }
            //if full
            if(mpp.size()==capacity){
                Node *lastNode=tail->prev;
                mpp.erase(lastNode->key);
                deleteNode(lastNode);
                delete lastNode;
            }
            Node *newNode=new Node(key, value);
            insertNode(newNode);
            mpp[key]=newNode;
        }
        void displayMPP(){
            for(auto it: mpp){
                cout<<it.first<<"->" <<it.second->value<<endl;
            }
        }
        ~LRU(){
            Node *curr=head;
            while(curr){
                Node *next=curr->next;
                delete curr;
                curr=next;
            }
    }
};
int main() {
    int capacity;
    cout<<"enter capacity: ";
    cin >> capacity;

    LRU cache(capacity);

    int q;
    cout<<"Enter number of operations: ";
    cin >> q;

    while(q--) {
        string op;
        cout<<"enter operation: ";
        cin >> op;

        if(op == "put") {
            int key, value;
            cin >> key >> value;

            cache.put(key, value);
            cout << "Inserted (" << key << "," << value << ")\n";
        }
        else if(op == "get") {
            int key;
            cin >> key;

            cout << cache.get(key) << endl;
        }
    }
    return 0;
}
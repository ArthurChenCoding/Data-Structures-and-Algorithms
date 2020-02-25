#ifndef FUNCTION_H 
#define FUNCTION_H 
 
using namespace std;

struct Node { 
   int data; 
   struct Node *next; 
};

Node* push(Node*, int);
void print(Node*);
bool isEmpty(Node*);
int size(Node*);
int top(Node*);
Node* pop(Node*);
Node* middle_element(Node*);
Node* remove_middle_element(Node* head, Node* middle_node);

#endif

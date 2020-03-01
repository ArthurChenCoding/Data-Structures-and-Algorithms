#include <iostream>
using namespace std;

#include "function.h"
//test
void print_stack_information(Node* head) {
   cout<< endl << "STACK: ";
   //cout << "data in head: "<<head->data<<endl;
   print(head);
   cout << "SIZE:" + to_string(size(head)) << "\t";
   cout << "IS_EMPTY: " + to_string(isEmpty(head)) << "\t";
   if(head != NULL)
      cout << "TOP: " + to_string(top(head)) << endl << endl;
   else
      cout << endl << endl;
}

int main() {
   struct Node* head = NULL;

   //print_stack_information(head);

   int number_of_elements;
   cout << "Enter the number of elements to input in stack: ";
   cin >> number_of_elements;
   cout << endl;
   for(int i=0; i<number_of_elements; i++) {
      int new_data;
      cout << "Data to PUSH: ";
      cin >> new_data;
	  //cout << "new_data: "<<new_data<<endl;
      head = push(head, new_data);
	  //cout << "data in head: "<<head->data<<endl;
      print_stack_information(head);
   }

   if(head != NULL) {
      int pop_or_not = 0;
      cout << "Press 1 to POP, 0 for NOT: ";
      cin >> pop_or_not;
      if(pop_or_not == 1) {
        head = pop(head);
        print_stack_information(head);
      } else {
        cout << endl;
      }
   }

   if(head != NULL) {
      Node* middle_node = middle_element(head);
      cout << "Middle Element of Linked List: " + to_string(middle_node->data) << endl << endl;

      int remove_middle_or_not = 0;
      cout << "Press 1 to REMOVE MIDDLE, 0 for NOT: ";
      cin >> remove_middle_or_not;
      if(remove_middle_or_not == 1) {
        head = remove_middle_element(head, middle_node);
        print_stack_information(head);
      }
   }

   return 0; 
} 
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
template <class C>
class queue{
    class qnode{
      public:
        C element;
        qnode *next;
		//initializing
        qnode(C e = 0): element( e ), next( NULL ){ }
    };
    qnode *first;
    qnode *last;
  public:
    queue(): first( NULL ), last( NULL ){ }
    inline bool isEmpty() const{
      return first == NULL;
    }
    void enqueue(const C x);
    C dequeue();
	C front(){return first->element;};
    void makeEmpty();
	void display();
};
template <class C>
void queue <C> :: enqueue( const C x ){
  if ( isEmpty( ) ){
    first = new qnode( x );
    last = first;
  }else{
    qnode *p = new qnode( x );
    last->next = p;
    last = last->next;
  }
}
template <class C>
C queue<C>::dequeue( ){
  C x;
  qnode *p;
  if (!isEmpty( )){
    x = first->element;
    p = first;
    first = first->next;
    delete p;
    return x;
  }
}
template <class C>
void queue<C>::makeEmpty( ){
  while ( !isEmpty() )
    dequeue();
}
template <class C>
void queue<C>::display( ){
  if ( isEmpty( ) )
    cout << "\n\nThe queue is empty.";
  for ( qnode *p = first; p != NULL; p = p->next )
    cout << p->element << " ";
}

#endif
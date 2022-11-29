/**
@Author: Tony Czajka 3010647
@File: Stack.cpp
@Date: 10/6/21
@Brief:This is the cpp file for the Stack class which is the data structure that the
	   elevator is modeled off. It is a FOLO type structure.
**/
#include"Stack.h"

template <typename T>
Stack<T>::Stack(){
  m_top=nullptr;
  length=0;
}

template <typename T>
Stack<T>::~Stack(){
  while(isEmpty()==false){
    pop();
  }
}

template <typename T>
bool Stack<T>::isEmpty()const{
  if(m_top==nullptr){
    return(true);
  }
  else{
    return(false);
  }
}

template <typename T>
void Stack<T>::push(const T value){
  if(isEmpty()){
    m_top=new Node<T>(value);
  }
  else{
    Node<T>* temp=new Node<T>(value);
    temp->setNext(m_top);
    m_top=temp;
  }
  length+=1;
}

template <typename T>
void Stack<T>::pop(){
  if(isEmpty()){
    throw(std::runtime_error("Pop attempted on empty Stack."));
  }
  else{
    Node<T>* temp=m_top->getNext();
    delete m_top;
    m_top=temp;
	length-=1;
  }

}

template <typename T>
T Stack<T>::peek()const{
	if(isEmpty()){
		throw(std::runtime_error("Peek attempted on an empty stack."));
		
	}
	else{
		return(m_top->getEntry());
	}
}
template <typename T>
int Stack<T>::getLength()const{
	return(length);
}

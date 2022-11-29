/**
@Author: Tony Czajka 3010647
@File: Queue.cpp
@Date: 10/6/2021
@Brief: This is the cpp file for the Queue class which implements the methods defined in
		the header. These methods allow for the creation of and use of the data structure
		Queue which is a FIFO type structure.
**/

#include <iostream>

template <typename T>
Queue<T>::Queue(){
  m_front=nullptr;
  m_back=nullptr;
  length=0;
}

template <typename T>
Queue<T>::~Queue(){
  while(!isEmpty()){
     dequeue();
  }
}

template <typename T>
void Queue<T>::enqueue(T entry){
  Node<T>* temp=new Node<T>(entry);
  if(isEmpty()){
    m_front=temp;
    m_back=temp;
  }
 else{
	m_back->setNext(temp);
	m_back=temp;
 }
 length++;

}

template <typename T>
void Queue<T>::dequeue(){
	if(isEmpty()){
		throw(std::runtime_error("Dequeue attempted on an empty queue."));
	}
	else if(m_front==m_back){
		m_back=nullptr;
		delete m_front;
		m_front=nullptr;
	}
	else{
		Node<T>* temp=m_front->getNext();
		delete m_front;
		m_front=temp;
	}
	length--;
}

template <typename T>
T Queue<T>::peekFront() const{
	if(!isEmpty()){
		return(m_front->getEntry());
	}
	else{
		throw(std::runtime_error("Peek attempted on an empty queue."));
	}
}

template <typename T>
bool Queue<T>::isEmpty()const{
	if(m_front==nullptr && m_back==nullptr){
		return(true);
	}
	else{
		return(false);
	}
}

template <typename T>
int Queue<T>::getLength()const{
	return(length);
}

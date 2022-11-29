/**
@Author: Tony Czajka 3010647
@File: LinkedList.cpp
@Date: 10/19/21
@Brief:This is an implementation of the LinkedList class, derived from the
      List interface, this defines the functions of a List and the actions that
      can be performed on a list.
**/
#include <iostream>
template<typename T>
LinkedList<T>::LinkedList(){
  m_front=nullptr;
  m_length=0;
}

template<typename T>
LinkedList<T>::~LinkedList(){
	while(m_length!=0){
		remove(0);
	}

}

template<typename T>
void LinkedList<T>::insert(int index, T entry){
  if(index<0 ||index>m_length){
    throw(std::runtime_error("ERROR: Insert attempted at invalid index."));
  }
  std::cout<<"Inserting\n"<<"m_length is: "<<m_length<<'\n';
  Node<T>* newNode = new Node<T>(entry); //might have to delete newNode??
  Node<T>* target = m_front;
  Node<T>* oneBefore=m_front;
  if(m_length==0){ //inserting first node
    m_front=newNode;
	std::cout<<"insert into front\n";
  }
  else if(index==m_length){
	  std::cout<<"Begin insert into back\n";
    for(int i=0;i<m_length-1;i++){
      target=target->getNext();
    }
    target->setNext(newNode);
	std::cout<<"Insert into back\n";
  }
  else if(index==0){ 
    newNode->setNext(m_front);
    m_front=newNode;
  }
  else if(m_length==1&&index==1){
	  std::cout<<"second node about to be inserted\n";
	  m_front->setNext(newNode);
	  std::cout<<"Second node inserted\n";
  }
  else{
    for(int i=0;i<index-1;i++){
      oneBefore=oneBefore->getNext();
    }
    target=oneBefore->getNext();
    oneBefore->setNext(newNode);
    newNode->setNext(target);
  }

  m_length++;
  std::cout<<"M_length is: "<<m_length<<'\n';
 // std::cout<<"Length after insert "<<m_length<<'\n';
  //make sure throw ends the function, otherwise put inside if statements
}

template<typename T>
void LinkedList<T>::remove(int index){ //does this need condition for delting the only item?
  if(index<0 || index>=m_length){
    throw(std::runtime_error("ERROR: Remove attempted at invalid index."));
  }
  else if(index==0&&m_length!=1){ //condition one where deleting the front
    Node<T>* temp=m_front->getNext();
    delete m_front;
    m_front=temp;
  }
  else if(index==0 && m_length==1){
    delete m_front;
    m_front=nullptr;

  }
  else{ //Deleting anything else
    Node<T>* target=m_front;
    Node<T>* oneBefore=m_front;
    for(int i=0;i<index-1;i++){
      oneBefore=oneBefore->getNext();
    }
    target=oneBefore->getNext();
    oneBefore->setNext(target->getNext());
    delete target;
    target=nullptr;
  }

m_length--;
}

template<typename T>
T LinkedList<T>::getEntry(int index)const{
  if(index>=m_length || index<0){
    throw(std::runtime_error("ERROR: Invalid index for attempted getEntry"));
  }
  else{
    Node<T>* jumper;
    jumper=m_front;
    for(int i=0; i<index; i++){
      jumper=jumper->getNext();
    }
    return(jumper->getEntry());
  }

}

template<typename T>
void LinkedList<T>::clear(){
  while(m_length!=0){
    remove(0);
  }

}

template<typename T>
void LinkedList<T>::setEntry(int index, T entry){
  if(index<0||index>=m_length){
    throw(std::runtime_error("ERROR: setEntry attempted at an invalid index"));
  }
  else{
    Node<T>* target=m_front;
    for(int i=0; i<index;i++){
      target=target->getNext();
    }
    target->setEntry(entry);
  }
}

template<typename T>
int LinkedList<T>::length()const{
  return(m_length);
}

template<typename T>
void LinkedList<T>::reverse(){
	if(m_length>1){
		for(int i=m_length-2;i>=0;i--){ 
			insert(m_length, getEntry(i));
			remove(i);
		}
	}
}




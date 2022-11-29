/**
@Author: Tony Czajka 3010647
@File: Bnode.cpp
@Date: 12/1/2021
@Brief:Bnode.cpp Implements the methods of the Binary node class
**/

template <typename T>
Bnode<T>::Bnode(T value){
  m_entry=value;
  left=nullptr;
  right=nullptr;
}

template <typename T>
void Bnode<T>::setLeftPtr(Bnode<T>* temp){
  left=temp;
}

template <typename T>
void Bnode<T>::setRightPtr(Bnode<T>* temp){
  right=temp;
}

template <typename T>
void Bnode<T>::setEntry(T temp){
  m_entry=temp;
}

template <typename T>
Bnode<T>* Bnode<T>::getLeftPtr() const{
  return(left);
}

template <typename T>
Bnode<T>* Bnode<T>::getRightPtr() const{
  return(right);
}

template <typename T>
T Bnode<T>::getEntry() const{
  return(m_entry);
}

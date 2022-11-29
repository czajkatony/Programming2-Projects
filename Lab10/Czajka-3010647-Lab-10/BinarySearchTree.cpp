/**
@Author: Tony Czajka 3010647
@File: BinarySearchTree.cpp
@Date: 12/1/2021
@Brief:BinarySearchTree.cpp | Implements the methods of the class
**/

template <typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::BinarySearchTree(){
  m_root=nullptr;
}

template <typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::~BinarySearchTree(){
  clear();
}

template <typename ItemType, typename KeyType>
Bnode<ItemType>* BinarySearchTree<ItemType, KeyType>::getRoot(){
	return m_root;
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::setRoot(Bnode<ItemType>* newRoot){
	std::cout<<"SETTING ROOT\n";
	m_root=newRoot;
	std::cout<<"ROOT SET\n";
}

template <typename ItemType, typename KeyType>
Bnode<ItemType>* BinarySearchTree<ItemType, KeyType>::copyTree(){
	Bnode<ItemType>* newRoot=copyTreeHelper(m_root);
	return(newRoot);
}

template <typename ItemType, typename KeyType>
Bnode<ItemType>* BinarySearchTree<ItemType, KeyType>::copyTreeHelper(Bnode<ItemType>* root){
  if(root==nullptr){
    return(nullptr);
  }
  else{
    Bnode<ItemType>* temp= new Bnode<ItemType>(root->getEntry());
    temp->setLeftPtr(copyTreeHelper(root->getLeftPtr()));
    temp->setRightPtr(copyTreeHelper(root->getRightPtr()));
	 return temp;
  }

}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::add(ItemType entry){
	try{
		m_root=addHelper(m_root, entry);
	}
	catch(std::runtime_error& e){
		throw(std::runtime_error("Could not add a duplicate to the pokedex."));
	}
}


template <typename ItemType, typename KeyType>
Bnode<ItemType>* BinarySearchTree<ItemType, KeyType>::addHelper(Bnode<ItemType>* root, ItemType entry){
  if(root==nullptr){
    return(new Bnode<ItemType>(entry));
  }
  else if(entry==root->getEntry()){
    throw(std::runtime_error("Duplicates not allowed to be added to Binary Search Tree."));
  }
  else if(entry<root->getEntry()){
    root->setLeftPtr(addHelper(root->getLeftPtr(), entry));
  }
  else if(entry> root->getEntry()){
    root->setRightPtr(addHelper(root->getRightPtr(), entry));
  }
  return(root);
}

template <typename ItemType, typename KeyType>
ItemType BinarySearchTree<ItemType, KeyType>::search(KeyType key)const{
  Bnode<ItemType>* compare=m_root;
  while(compare!=nullptr){
	  if(compare->getEntry()==key){
		  return(compare->getEntry());
	  }
	  else if(compare->getEntry()<key){
		  compare=compare->getRightPtr();
	  }
	  else if(compare->getEntry()>key){
		  compare=compare->getLeftPtr();
	  }
  }
  throw(std::runtime_error("Pokemon with this ID not found."));
}
//============================VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV============================
template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::clear(){
	clearHelper(m_root);
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::clearHelper(Bnode<ItemType>* root){
	if(root==nullptr){
		return;
	}
	clearHelper(root->getLeftPtr());
	clearHelper(root->getRightPtr());
	delete root;
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::remove(KeyType key){
  try{
    ItemType result=search(key);
    m_root=removeHelper(result, m_root);
  }
  catch(std::runtime_error& e){
	  std::cout<<"ERROR: "<<e.what()<<'\n';
  }
}

template <typename ItemType, typename KeyType>
Bnode<ItemType>* BinarySearchTree<ItemType, KeyType>::removeHelper(ItemType key, Bnode<ItemType>* root){
  if(root==nullptr){
    return(root);
  }
  if(root->getEntry()<key){
    root->setRightPtr(removeHelper(key, root->getRightPtr()));
  }
  else if(root->getEntry()>key){
    root->setLeftPtr(removeHelper(key, root->getLeftPtr()));
  }
  else{
    if(root->getRightPtr()==nullptr){
      Bnode<ItemType>* temp=root->getLeftPtr();
      delete root;
      return temp;
    }
    else if(root->getLeftPtr()==nullptr){
      Bnode<ItemType>* temp=root->getRightPtr();
      delete root;
      return temp;
    }
    else{   //root is deleted, has two children
      Bnode<ItemType>* temp=root->getRightPtr();
      while(temp->getLeftPtr()!=nullptr){
        temp=temp->getLeftPtr();
      }
      Bnode<ItemType>* newNode=new Bnode<ItemType>(temp->getEntry());
      newNode->setLeftPtr(root->getLeftPtr());
      newNode->setRightPtr(removeHelper(newNode->getEntry(),newNode->getRightPtr())); //figure out how to get KeyType
      delete root;
      return newNode;
    }
  }
  return(root);
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::visitPreOrder(void visit(ItemType))const{
	visitPreOrderHelper(m_root, visit);
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::visitInOrder(void visit(ItemType))const{
	visitInOrderHelper(m_root, visit);
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::visitPostOrder(void visit(ItemType))const{
	visitPostOrderHelper(m_root, visit);
}


template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::visitPreOrderHelper(Bnode<ItemType>* temp, void visit(ItemType))const{
	if(temp!=nullptr){
		visit(temp->getEntry());
		visitPreOrderHelper(temp->getLeftPtr(),visit);
		visitPreOrderHelper(temp->getRightPtr(),visit);
	}
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::visitInOrderHelper(Bnode<ItemType>* temp, void visit(ItemType))const{
	if(temp!=nullptr){
		visitInOrderHelper(temp->getLeftPtr(),visit);
		visit(temp->getEntry());
		visitInOrderHelper(temp->getRightPtr(),visit);
	}
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::visitPostOrderHelper(Bnode<ItemType>* temp, void visit(ItemType))const{
	if(temp!=nullptr){
		visitPostOrderHelper(temp->getLeftPtr(),visit);
		visitPostOrderHelper(temp->getRightPtr(),visit);
		visit(temp->getEntry());
	}
}

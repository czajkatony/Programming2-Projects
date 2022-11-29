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
Bnode<ItemType>* BinarySearchTree<ItemType, KeyType>::copyTree(Bnode<ItemType>* root){
  if(root==nullptr){
    return(nullptr);
  }
  else{
    Bnode<ItemType>* temp= new Bnode<ItemType>(root->getEntry());
    temp->setLeftPtr(copyTree(root->getLeftPtr()));
    temp->setRightPtr(copyTree(root->getRightPtr()));
  }
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::add(ItemType entry){
	m_root=addHelper(m_root, entry);
}


template <typename ItemType, typename KeyType>
Bnode<ItemType>* BinarySearchTree<ItemType, KeyType>::addHelper(Bnode<ItemType>* root, ItemType entry){
  if(root==nullptr){
    return(new Bnode<ItemType>(entry));
  }
  if(entry==root->getEntry()){
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


//============================VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV============================

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

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::clear(){}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::remove(KeyType key){
	/**
	try{
		m_root=removeHelper(key, m_root);
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
	**/
}

template <typename ItemType, typename KeyType>
Bnode<ItemType>* BinarySearchTree<ItemType, KeyType>::removeHelper(KeyType key, Bnode<ItemType>* temp){
	/**
		if(temp==key){ //base case stuff
			//root is removed
			if(m_root==temp){
				delete temp;
				m_root=nullptr;
				return(m_root);
			}
			//no child not root
			else if(temp->getRightPtr()==nullptr&&temp->getLeftPtr()==nullptr){
				delete temp;
				return(m_root);
			}
			//two children
			else if(temp->getRightPtr()!=nullptr&&temp->getLeftPtr()!=nullptr){}
			//one child
			else if(temp->getRightPtr()==nullptr||temp->getLeftPtr()==nullptr){

			}

		}
		else if(temp>key){
			removeHelper(key, temp->getLeftPtr());
		}
		else if(temp<key){
			removeHelper(key, temp->getRightPtr());
		}
		**/
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

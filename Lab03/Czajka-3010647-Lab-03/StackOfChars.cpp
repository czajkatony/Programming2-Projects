#include "StackOfChars.h"

StackOfChars::StackOfChars()
{  
	m_top=nullptr;
}

StackOfChars::StackOfChars(const StackOfChars& orig) //copy constructor
{
	
}


StackOfChars::~StackOfChars()
{
	while(isEmpty()==false){
			pop();
	}
}

void StackOfChars::operator=(const StackOfChars& rhs)
{

	
}

void StackOfChars::push(char entry)
{
	if(isEmpty()==true)
	{
		m_top=new Node(entry);
	}
	else{
	Node* newTopNode=new Node(entry);
	newTopNode->setNext(m_top);
	m_top=newTopNode;
	}
}

void StackOfChars::pop() //implement the exception
{
	if(isEmpty()==false)
	{
		Node* newTopNode=nullptr;
		newTopNode=m_top->getNext();
		delete m_top;
		m_top=newTopNode;
	}
	else
	{
		throw(std::runtime_error("Pop attempted on empty stack."));
	}
	
}

char StackOfChars::peek()const
{
	if (!isEmpty())
	{
		return(m_top->getEntry());
	}
	else
	{
		throw(std::runtime_error("Peek attempted on an empty stack."));
	}
}

bool StackOfChars::isEmpty() const
{
	if (m_top==nullptr)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}
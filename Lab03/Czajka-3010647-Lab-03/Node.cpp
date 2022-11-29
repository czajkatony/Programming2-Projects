#include "Node.h"


Node::Node(char entry)
{
	m_entry=entry;
}

char Node::getEntry() const
{
	return(m_entry);
}

void Node::setEntry(char entry)
{
	m_entry=entry;
}

Node* Node::getNext() const
{
	return(m_next);
}

void Node::setNext(Node* next)
{
	if(next!=nullptr)
	{
		m_next=next;
	}
	else
	{
		throw(std::runtime_error("setNextpointer points to nothing."));
	}
}


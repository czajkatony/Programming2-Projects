#include "StackTester.h"

StackTester::StackTester()
{
	
}

void StackTester::runTests()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
}

void StackTester::test01()
{
	StackOfChars test;
	std::cout<<"Test 1: Newly created stack is empty: ";
	if(test.isEmpty()==true)
	{
		std::cout<<"Pass\n";
	}
	else
	{
		std::cout<<"Fail\n";
	}
}

void StackTester::test02()
{
	StackOfChars test;
	std::cout<<"Test 2: Pushing onto an empty stack makes it non-empty: ";
	test.push('q');
	if(test.isEmpty()==false)
	{
		std::cout<<"Pass\n";
	}
	else
	{
		std::cout<<"Fail\n";
	}
	
}

void StackTester::test03()
{
	try{
	StackOfChars test;
	std::cout<<"Test 3: Popping all elements makes a stack empty: ";
	test.push('a');
	test.push('b');
	test.push('c');
	for(int i=0;i<3;i++)
	{
		test.pop();
	}
	if(test.isEmpty()==true)
	{
		std::cout<<"Pass\n";
	}
	else
	{
		std::cout<<"Fail\n";
	}
	}
	catch(std::exception& e)
	{
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
}

void StackTester::test04()
{
	StackOfChars test;
	std::cout<<"Test 4: Peek matches the last pushed value: ";
	test.push('a');
	test.push('b');
	test.push('c');
	if(test.peek()=='c')
	{
		std::cout<<"Pass\n";
	}
	else
	{
		std::cout<<"Fail\n";
	}
}

void StackTester::test05()
{
	StackOfChars test;
	std::cout<<"Test 5: Popping makes the next node the new top node: ";
	test.push('a');
	test.push('b');
	test.push('c');
	test.pop();
	if(test.peek()=='b')
	{
		std::cout<<"Pass\n";
	}
	else
	{
		std::cout<<"Fail\n";
	}
}

void StackTester::test06()
{
	StackOfChars test;
	std::cout<<"Test 6: Pushing 4 values puts them on the stack in the correct order: ";
	test.push('a');
	test.push('b');
	test.push('c');
	test.push('d');
	if(test.peek()=='d')
	{
		test.pop();
		if(test.peek()=='c')
		{
			test.pop();
			if(test.peek()=='b')
			{
				test.pop();
				if(test.peek()=='a')
				{
					std::cout<<"Pass\n";
				}
			}
		}
	}
	else
	{
		std::cout<<"Fail\n";
	}
}
//get results to print to output File
//do comments
//create graphs
//short summary of graphs

#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <fstream>

//If returns clock value 0. did it in a single instance
double stackPop(int elements){
  Stack<int>* stack=new Stack<int>();
  for(int i=0;i<elements;i++){
    stack->push(i);
  }
  clock_t start=clock();
  stack->pop();
  clock_t end=clock();
  //std::cout<<"END: "<<end<<" START: "<<start<<"CLOCKS_PER_SEC: "<<CLOCKS_PER_SEC<<'\n';
  double timeTaken=(end-start)/(double)CLOCKS_PER_SEC;
  delete stack;
  return(timeTaken);
}

double stackDestructor(int elements){
  Stack<int>* stack=new Stack<int>();
  for(int i=0;i<elements;i++){
    stack->push(i);
  }
  clock_t start=clock();
  delete stack;
  clock_t end=clock();
  //std::cout<<"END: "<<end<<" START: "<<start<<"CLOCKS_PER_SEC: "<<CLOCKS_PER_SEC<<'\n';
  double timeTaken=(end-start)/(double)CLOCKS_PER_SEC;
  return(timeTaken);
}

double queueEnqueue(int elements){
  Queue<int>* queue=new Queue<int>();
  clock_t start=clock();
  for(int i=0;i<elements;i++){
    queue->enqueue(i);
  }
  clock_t end=clock();
  //std::cout<<"END: "<<end<<" START: "<<start<<"CLOCKS_PER_SEC: "<<CLOCKS_PER_SEC<<'\n';
  double timeTaken=(end-start)/(double)CLOCKS_PER_SEC;
  delete queue;
  return(timeTaken);
}

double listGetEntryFirst(int elements){
  LinkedList<int>* list=new LinkedList<int>();
  for(int i=elements-1;i>=0;i--){
    list->insert(0,i);
//    std::cout<<i<<'\n';
  }
  clock_t start=clock();
  list->getEntry(1);
  clock_t end=clock();
  //std::cout<<"END: "<<end<<" START: "<<start<<"CLOCKS_PER_SEC: "<<CLOCKS_PER_SEC<<'\n';
  double timeTaken=(end-start)/(double)CLOCKS_PER_SEC;
  return(timeTaken);
}

double listGetEntryLast(int elements){
  LinkedList<int>* list=new LinkedList<int>();
  for(int i=elements-1;i>=0;i--){
    list->insert(0,i);
//    std::cout<<i<<'\n';
  }
  clock_t start=clock();
  list->getEntry(elements-1);

  clock_t end=clock();
  //std::cout<<"END: "<<end<<" START: "<<start<<"CLOCKS_PER_SEC: "<<CLOCKS_PER_SEC<<'\n';
  double timeTaken=(end-start)/(double)CLOCKS_PER_SEC;
  return(timeTaken);
}

double printAllList(int elements){
  LinkedList<int>* list=new LinkedList<int>();
  for(int i=elements-1;i>=0;i--){
    list->insert(0,i);
//    std::cout<<i<<'\n';
  }
  clock_t start=clock();
  for(int i=0;i<elements;i++){
    std::cout<<list->getEntry(i)<<'\n';
  }
  clock_t end=clock();
  //std::cout<<"END: "<<end<<" START: "<<start<<"CLOCKS_PER_SEC: "<<CLOCKS_PER_SEC<<'\n';
  double timeTaken=(end-start)/(double)CLOCKS_PER_SEC;
  return(timeTaken);
}

int main(){
	//std::setprecision(10);
	std::ofstream output1;
	std::ofstream output2;
	std::ofstream output3;
	std::ofstream output4;
	std::ofstream output5;
	std::ofstream output6;

//==========Stacks pop=========================================================
output1.open("stacksPop.txt");
  for(int i=1000;i<=100000;i+=1000){
	  output1<<i<<" "<<std::fixed<<std::setprecision(10)<<stackPop(i)<<'\n';
   // std::cout<<"Stack Pop with "<<i<<" elements.\nTime: "<<std::setprecision(10)<<stackPop(i)<<'\n';
  }
  output1.close();
//==========================================================================

//===========================Stacks Destructor================================
output2.open("stacksDestructor.txt");
for(int i=1000;i<=100000;i+=1000){
	output2<<i<<" "<<std::fixed<<std::setprecision(10)<<stackDestructor(i)<<'\n';
 // std::cout<<"Stack Destructor with "<<i<<" elements.\nTime: "<<std::setprecision(10)<<stackDestructor(i)<<'\n';
}
output2.close();
//==========================================================================

//===========================Queues enqueue===================================
output3.open("queuesEnqueue.txt");
for(int i=1000;i<=100000;i+=1000){
	output3<<i<<" "<<std::fixed<<std::setprecision(10)<<queueEnqueue(i)<<'\n';
//  std::cout<<"Queue Enqueue with "<<i<<" elements.\nTime: "<<std::setprecision(10)<<queueEnqueue(i)<<'\n';
}
output3.close();
//==========================================================================

//================================List getEntry at index 1==========================================
output4.open("getEntryAtIndex0.txt");
for(int i=1000;i<=100000;i+=1000){
	output4<<i<<" "<<std::fixed<<std::setprecision(10)<<listGetEntryFirst(i)<<'\n';
 // std::cout<<"getEntry at index 1 with: "<<i<<" elements.\nTime: "<<std::setprecision(10)<<listGetEntryFirst(i)<<'\n';
}
output4.close();
//==========================================================================

//================================List getEntry at last index==========================================
output5.open("getEntryAtLastIndex.txt");
for(int i=1000;i<=100000;i+=1000){
	output5<<i<<" "<<std::fixed<<std::setprecision(10)<<listGetEntryLast(i)<<'\n';
 // std::cout<<"getEntry at last index with: "<<i<<" elements.\nTime: "<<std::setprecision(10)<<listGetEntryLast(i)<<'\n';
}
output5.close();
//==========================================================================

//=========================Printing all elements in a linKedList using getEntry===================================
output6.open("printList.txt");
for(int i=1000;i<=100000;i+=1000){
	output6<<i<<" "<<std::fixed<<std::setprecision(10)<<printAllList(i)<<'\n';
//  std::cout<<"Print all elements in List: "<<i<<" elements.\nTime: "<<std::setprecision(10)<<printAllList(i)<<'\n';
}
output6.close(); 
//==========================================================================

  return(0);
}

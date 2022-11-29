/**
@Author: Tony Czajka 3010647
@File: Browser.cpp
@Date: 10/19/21
@Brief:This is the implementation of the Browser class, which is derived from
			 the browser interface.
**/

template <typename T>
Browser<T>::Browser(){
	history=new LinkedList<std::string>();
	currentIndex=0;
}

template <typename T>
Browser<T>::~Browser(){
	delete history;
}

template <typename T>
void Browser<T>::navigateTo(std::string url){
	if(currentIndex!=0){
		for(int i=0;i<currentIndex;i++){
			history->remove(0);
		}
	}
	history->insert(0,url);
	currentIndex=0;
}

template <typename T>
void Browser<T>::forward(){
	if(history->length()==0){
		throw(std::runtime_error("Forward action attempted on an empty history."));
	}
	if(currentIndex!=0){
		currentIndex--;
	}
	else{
		throw(std::runtime_error("Cannot go further than the newest search entry."));
	}
}

template <typename T>
void Browser<T>::back(){
	if(history->length()==0){
		throw(std::runtime_error("Back action attempted on empty history."));
	}
	if(currentIndex!=(history->length())-1){
		currentIndex++;
	}
	else{
		throw(std::runtime_error("Back attmepted at the oldest known history entry."));
	}
}

template <typename T>
std::string Browser<T>::current()const{
	return(history->getEntry(currentIndex));
}

template <typename T>
void Browser<T>::copyCurrentHistory(LinkedList<std::string>& destination){
	if(history->length()==0){
		throw(std::runtime_error("Attempted to copy an empty history"));
	}
	else{
		for(int i=history->length()-1;i>=0;i--){
			destination.insert(0,history->getEntry(i));
		}
	}
}

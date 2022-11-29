/**
@Author: Tony Czajka 3010647
@File: Browser.h
@Date: 10/19/21
@Brief:This is the header file for the Browser class. It lists all the methods required
			 by the Browser History Interface and the member variables needed to implement these
			 methods.
**/
#ifndef BROWSER_H
#define BROWSER_H
#include "BrowserHistoryInterface.h"
#include "LinkedList.h"


template <typename T>
class Browser
{
	private:
	LinkedList<std::string>* history;
	int items;
	int currentIndex;
	public:
	Browser();
  /**
  * @post All memory allocated by the implementing class should be freed.
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
	~Browser();
  /**
  * @pre none
  * @post the browser navigate to the given url
  * @param url, a string representing a URL
  */
	void navigateTo(std::string url);
	/**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it keeps focus
  *         on the current URL
  * @throw std::runtime_error if forward action is attempted on an empty history, or Attempted
           at the newest search entry.
  */
	void forward();
	/**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
  *         on the current URL
  * @throw std::runtime_error if back is attempted on an empty history or if Attempted
           at the oldest known history entry.
  */
	void back();
  /**
  * @return the current URL
  */
	std::string current()const;
	/**
  * @pre The list being passed in is empty
  * @post The current browser history is copied into the given list
  * @param destination, an empty list of strings
  * @throw std::runtime_error if attempting to copy an empty history.
  */
	void copyCurrentHistory(LinkedList<std::string>& destination);


};
#include "Browser.cpp"
#endif

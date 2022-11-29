/**
@Author: Tony Czajka 3010647
@File: BrowserHistoryInterface.h
@Date: 10/19/21
@Brief:This is the Interface for Browser History, which defines what a Browser class
       needs to have.
**/
#include "ListInterface.h"
#include <string>

class BrowserHistoryInterface
{
  public:
  /**
  * @post All memory allocated by the implementing class should be freed.
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
  virtual ~BrowserHistoryInterface(){}

  /**
  * @pre none
  * @post the browser navigate to the given url
  * @param url, a string representing a URL
  */
  virtual void navigateTo(std::string url) = 0;

  /**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it keeps focus
  *         on the current URL
  * @throw std::runtime_error if forward action is attempted on an empty history, or Attempted
           at the newest search entry.
  */
  virtual void forward() = 0;

  /**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
  *         on the current URL
  * @throw std::runtime_error if back is attempted on an empty history or if Attempted
           at the oldest known history entry.
  */
  virtual void back() = 0;

  /**
  * @return the current URL
  */
  virtual std::string current() const = 0;

  /**
  * @pre The list being passed in is empty
  * @post The current browser history is copied into the given list
  * @param destination, an empty list of strings
  * @throw std::runtime_error if attempting to copy an empty history.
  */
  virtual void copyCurrentHistory(ListInterface<std::string>& destination) = 0;
};

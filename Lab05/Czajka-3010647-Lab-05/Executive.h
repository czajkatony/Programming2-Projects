/**
@Author: Tony Czajka 3010647
@File: Executive.h
@Date: 10/19/21
@Brief:This is the header file for the Executive class, it outlines what methods
       and variables are needed to implement the browser and Linked List classes
       to make this model of a web browser.
**/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Browser.h"
#include <fstream>

class Executive
{
private:
std::string m_filename;
Browser<std::string>* browser;
std::string actionCode;
public:

/**
* @pre none
* @post Executive object is created
* @param filename, a string that describes the filename of the text filename
         read to get the action codes.
* @throw none
*/
Executive(std::string filename);

/**
* @pre none
* @post Executive object is deleted, the Browser object associated with it also
        deleted.
* @param none
* @throw none
*/
~Executive();

/**
* @pre valid Executive object and filename passed in, with valid actionCodes in the file.
* @post Browser and List are editited acordingly
* @param none
* @throw std::runtime_error if an invalid action code is passed by the input file.
*/
void run();

};

#endif

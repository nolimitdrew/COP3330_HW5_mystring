
/* Name: Andrew Stade
Date: 3/26/2019
Section: 2 */


#include <iostream>
using namespace std;

class MyString
{
  friend ostream& operator<< (ostream& os, const MyString& s);
  friend istream& operator>> (istream& is, MyString& s);
  friend istream& getline (istream& is, MyString& s);
  friend istream& getline (istream& is, MyString& s, char delim);

  friend MyString operator+ (const MyString& x, const MyString& y);

  friend bool operator< (const MyString& x, const MyString& y);
  friend bool operator> (const MyString& x, const MyString& y);
  friend bool operator<=(const MyString& x, const MyString& y);
  friend bool operator>=(const MyString& x, const MyString& y);
  friend bool operator==(const MyString& x, const MyString& y);
  friend bool operator!=(const MyString& x, const MyString& y);

public:
  MyString();				// empty string
  MyString(const char* x);		// conversion from c-string
  MyString(int x);			// conversion from int
  ~MyString();				// destructor
  MyString(const MyString& s);		// copy constructor
  MyString& operator=(const MyString& s);   // assignment operator

  MyString& operator+=(const MyString& s);  // concatenation/assignment

  // bracket operators to access char positions
  char& operator[] (unsigned int index);
  const char& operator[] (unsigned int index) const;

  // insert s into the string at position "index"
  MyString& insert(unsigned int index, const MyString& s);

  // find index of the first occurrence of s inside the string
  //  return the index, or -1 if not found
  int indexOf(const MyString& s) const;
  
  int getLength() const;		// return string length
  const char* getCString() const;	// return c-string equiv

  MyString substring(unsigned int x, unsigned int y) const;
  MyString substring(unsigned int x) const;

private:
    int size;
    char* strArr;
  // declare your member data here
};
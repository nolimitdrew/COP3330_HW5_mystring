
/* Name: Andrew Stade
Date: 3/26/2019
Section: 2 */


#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "mystring.h"

using namespace std;

ostream& operator<< (ostream& os, const MyString& s) // Complete
{
    os << s.strArr;
    
    return os;
}

istream& operator>> (istream& is, MyString& s) // Incomplete
{
    int temp = 0;
    int max = 30;
    
    char* tempArr = new char[max];
    char* tempArr2 = new char[max + 1];
        
    is >> tempArr[temp];
        
    for (int i = 0; i < max; i++)
    {
        tempArr2[i] = tempArr[i];
        temp++;
        //delete [] tempArr; // Every delete gives me a memory leak... why
        tempArr = tempArr2;
    }
        
    tempArr[temp] = '\0';
    //delete [] s.strArr;
    s.strArr = tempArr;
    
    return is;
}

istream& getline (istream& is, MyString& s) // Incomplete
{
    int temp = 0;
    int max = 30;
    
    char* tempArr = new char[max];
    
    if(temp < max - 1)
    {
        tempArr[temp] = is.get();
        temp++;
    }
    else
    {
        max++;
        
        char* tempArr2 = new char[max];
                
        for(int i = 0; i < temp; i++)
        {
            tempArr2[i] = tempArr[i];
            tempArr2[temp] = is.get();
            temp++;
            // delete [] tempArr;
            tempArr = tempArr2;
        }
    }
    
    is.ignore();
    max = temp + 1;
    tempArr[temp] = '\0';
    //delete [] s.strArr;
    s.strArr = tempArr;
    s.size = max;
    
    return is;
}

istream& getline (istream& is, MyString& s, char delim) // Incomplete
{
    int temp = 0;
    int max = 30;
    
    char* tempArr = new char[max];
    
    if(temp < max - 1)
    {
        tempArr[temp] = is.get();
        temp++;
    }
    else
    {
        max++;
        
        char* tempArr2 = new char[max];
                
        for(int i = 0; i < temp; i++)
        {
            tempArr2[i] = tempArr[i];
            tempArr2[temp] = is.get();
            //delete [] tempArr;
            tempArr = tempArr2;
        }
    }
    
    is.ignore();
    max = temp + 1;
    tempArr[temp] = '\0';
    //delete [] s.strArr;
    s.strArr = tempArr;
    s.size = max;
    
    return is;
}

MyString operator+ (const MyString& x, const MyString& y) // Complete
{
    MyString s = x;
    s += y;
    
    return s;
}

bool operator< (const MyString& x, const MyString& y) // Complete
{
    int counter = 0;
    
    do
    {
        counter++;
    } while ((x.strArr[counter] != '\0') && (x.strArr[counter] == y.strArr[counter]));
    
    if((x.strArr[counter] - y.strArr[counter]) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool operator> (const MyString& x, const MyString& y) // Complete
{
    if (x <= y)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool operator<=(const MyString& x, const MyString& y) // Complete
{
    if ((x < y) || (x == y))
    {
        return true;
    }
    else
    {
        return false;
    } 
}

bool operator>=(const MyString& x, const MyString& y) // Complete
{
    if (x < y)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool operator==(const MyString& x, const MyString& y) // Complete
{
    for (int i = 0; i < x.size; i++)
    {
        if (x.strArr[i] != y.strArr[i])
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const MyString& x, const MyString& y) // Complete
{
    if (x == y)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// --- Member Functions --- 

MyString::MyString()  // empty string 
{
    size = 1;
    strArr = new char[size];
    strArr[0] = '\0';
}

MyString::MyString(const char* x)  // conversion from c-string
{
    size = strlen(x) + 1;
    strArr = new char[size];
    
    for (int i = 0; i < size; i++)
    {
        strArr[i] = x[i];
    }
    strArr[size-1] = '\0';
}

MyString::MyString(int x)  // conversion from int
{
    int counter = 0;
    int temp = x;
    
    do
    {
        temp = temp / 10;
        counter++;
    } while (temp != 0);
        
    size = counter + 1;
    strArr = new char[size];
    
    do
    {
        strArr[counter - 1] = char((x % 10) + 48);
        x = x / 10;
        counter--;
    } while (counter >= 1);
    
    strArr[size - 1] = '\0';
}

MyString::~MyString()  // destructor (Incomplete)
{
    // delete [] strArr; // if enabled causes a memory leak. strange.
}

MyString::MyString(const MyString& s)  // copy constructor
{
    size = s.size;
    strArr = new char[size];
    
    for (int i = 0; i < size; i++)
    {
        strArr[i] = s.strArr[i];
    }
}

MyString& MyString::operator=(const MyString& s)  // assignment operator
{
    if (*this != s)
    {
        //delete [] strArr;
        
        size = s.size;
        strArr = new char[s.size];
        
        for (int i = 0; i < size - 1; i++)
        {
            strArr[i] = s.strArr[i];
        }
        strArr[size - 1] = '\0';
    }
    
    return *this;
}

MyString& MyString::operator+=(const MyString& s)  // concatenation/assignment
{
    char* tempArr = new char[size + s.size - 1];
    
    for (int i = 0; i < size - 1; i++)
    {
        tempArr[i] = strArr[i];
    }
    for (int i = 0; i < size; i++)
    {
        tempArr[i + size - 1] = s.strArr[i];
    }
    
    size = size + s.size;
    //delete [] strArr;
    strArr = tempArr;
    
    return *this;
}

// bracket operators to access char positions
char& MyString::operator[] (unsigned int index) // Complete
{
    if(index <= size - 2)
    {
        return strArr[index];
    }
    else
    {
        char* tempArr = new char[index + 2];
        
        for (int i = 0; i < size - 1; i++)
        {
            tempArr[i] = strArr[i];
        }
        for (int i = size - 1; i < index + 1; i++)
        {
            tempArr[i] = '\0';
            tempArr[index + 1] = '\0';
            //delete [] strArr;
            strArr = tempArr;
            size = index + 2;
            
            return strArr[index];
        }
    }
}

const char& MyString::operator[] (unsigned int index) const // Complete
{
    if(index <= size - 2)
    {
        return strArr[index];
    }
    else
    {
        return strArr[size - 1];
    }
}

// insert s into the string at position "index"
MyString& MyString::insert(unsigned int index, const MyString& s) // Incomplete
{
    if(index <= size - 1)
    {
        char* strTemp = new char[size + s.size - 1];
        
        for (int i = 0; i < index; i++)
        {
            strTemp[i] = strArr[i];
        }
        for (int i = 0; i < s.size - 1; i++)
        {
            strTemp[i + index] = s.strArr[i];
        }
        for (int i = index + s.size - 1; i < size + s.size - 2; i++)
        {
            strTemp[i] = strArr[i - s.size + 1];
            strTemp[size + s.size - 2] == '\0'; // doesn't work correctly
            //delete [] strArr;
            strArr = strTemp;
            size = size + size - 1;
        }
    }
    else
    {
        char* strTemp = new char[size + s.size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            strTemp[i] = strArr[i];
        }
        for (int i = 0; i < s.size - 1; i++)
        {
            strTemp[size - 1 + i] = s.strArr[i];
            strTemp[size + s.size - 2] == '\0'; // doesn't work correctly
            //delete [] strArr;
            strArr = strTemp;
            size = size + size - 1;
        }
    }
    
    return *this;
}

// find index of the first occurrence of s inside the string
//  return the index, or -1 if not found
int MyString::indexOf(const MyString& s) const // Complete
{
    if(size < s.size)
    {
        return -1;
    }
    else if (size == s.size)
    {
        int temp = 0;
        
        do
        {
            temp++;
        } while ((strArr[temp] == s.strArr[temp]) && (strArr[temp] != '\0'));
        
        if (strArr[temp] == '\0')
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int temp2 = 0;
        
        do
        {
            int count1 = 0;
            int count2 = 0;
            
            do
            {
                temp2++;
            } while ((s[0] != strArr[temp2] && (temp2 < (size - s.size + 1))));
            
            if (temp2 == size - s.size + 1)
            {
                return -1;
            }
            else 
            {
                count2 = temp2;
                
                do
                {
                    count1++;
                    count2++;
                } while ((s[count1] == strArr[count2]) && (s[count1] != '\0'));
                    
                if (s[count1] == '\0')
                {
                    return temp2;
                }
                else
                {
                    temp2++;
                }
            }
        } while (temp2 < (size - s.size + 1));
    }
}
  
int MyString::getLength() const  // return string length
{
    return size - 1;
}

const char* MyString::getCString() const	// return c-string equiv
{
    return strArr;
}

MyString MyString::substring(unsigned int x, unsigned int y) const // Complete
{
    MyString str = substring(x);
    
    if (str.size - 1 <= y)
    {
        return str;
    }
    else
    {
        char* strTemp = new char[y + 1];
        
        for (int i = 0; i < y; i++)
        {
            strTemp[i] = str.strArr[i];
        }
        
        strTemp[y] = '\0';
        //delete [] str.strArr;
        str.strArr = strTemp;
        str.size = y + 1;
        
        return str;
    }
}

MyString MyString::substring(unsigned int x) const // Complete
{
    MyString str;
    
    int temp = size - x;
    if (temp <= 1)
    {
        str.strArr = '\0';
        str.size = 1;
    }
    else
    {
        char* strTemp = new char[temp];
        
        for (int i = 0; i < temp - 1; i++)
        {
            strTemp[i] = strArr[i + x];
        }
        
        strTemp[temp - 1] = '\0';
        //delete [] str.strArr;
        str.strArr = strTemp;
        str.size = temp;
    }
        
    return str; 
}
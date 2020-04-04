#include <iostream>
#include "String.h"

using namespace HomeMadeString;

//constructor
String::String()
{
    elementNum = 0;
    pData = NULL;
}

//copy constructor
String::String(const String &s)
{
    elementNum = s.elementNum;
    pData = s.pData;
}

//conversion constructor
String::String(const char *str)
{
    int counter = 0;
    while (str[counter] != '\0')
    {
        counter++;
    }
    elementNum = counter;

    pData = (char *)malloc(counter * sizeof(char));
    counter = 0;
    while (str[counter] != '\0')
    {
        pData[counter] = str[counter];
        counter++;
    }
}

//special constructor
String::String(const char c, const int times)
{
    pData = (char *)malloc((times + 1) * sizeof(char));
    int i;
    for (i = 0; i < times; i++)
    {
        pData[i] = c;
    }
    pData[i] = '\0';
    elementNum = times;
}

//destructor
String::~String()
{
    elementNum = 0;
    free(pData);
}

void String::getStr(char *pBuff)
{
}

//Writes the string to the given stream
void String::print(std::ostream &os)
{
    for (unsigned int i = 0; i < elementNum; i++)
    {
        os << pData[i];
    }
}

// Returns with the character at the given position, othewise 0
char String::getChar(const int pos)
{
    if ((pos < 0) || (pos > elementNum - 1))
    {
        return 0;
    }
    return (pData[pos]);
}

// Returns with a concatenated string
String String::concatenate(const String string1, const String string2)
{
    char *p1 = string1.pData, *p2 = string2.pData;
    int size1 = 0, size2 = 0;

    while (*p1 != '\0')
    {
        size1++;
        p1++;
    }

    while (*p2 != '\0')
    {
        size2++;
        p2++;
    }
    p1 = string1.pData;
    p2 = string2.pData;
    char *newString = (char *)malloc((size1 + size2) * sizeof(char));

    int i;
    for (i = 0; i < size1; i++)
    {
        newString[i] = string1.pData[i];
    }
    for (int j = 0; j < size2; j++)
    {
        newString[i] = string2.pData[j];
        i++;
    }

    String result(newString);
    return (result);
}

// Compares two strings
bool String::compare(const String string1, const String string2)
{
    if ((string1.pData[0] == '\0') && (string2.pData[0] != '\0'))
        return -1;
    else if ((string1.pData[0] != '\0') && (string2.pData[0] == '\0'))
        return 1;
    else
    {
        char *p1 = string1.pData, *p2 = string2.pData;
        while (*p1 != '\0')
        {
            if (*p1 > *p2)
                return 1;
            else if (*p1 < *p2)
                return -1;
            else if (*p1 == *p2)
            {
                p1++;
                p2++;
            }
        }
        if (*p2 != '\0')
            return -1;
    }
}

// Copies string2 to string1
void String::copy(String &string1, const String string2)
{
    string1.elementNum = string2.elementNum;
    string1.pData = (char *)malloc((string2.elementNum) * sizeof(char));

    char *p = string2.pData;
    int counter = 0;
    while (*p != '\0')
    {
        string1.pData[counter] = *p;
        counter++;
        p++;
    }
}
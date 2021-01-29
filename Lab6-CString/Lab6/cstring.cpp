//
//  cstring.cpp
//  Lab6
//
//  Created by Moeen Khan on 12/2/20.
//

#include <stdio.h>
#include "cstring.h"
using namespace mystring;


char* mystring::strcpy(char *dest, const char *src){
    char *start = dest;

    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0'; // add '\0' at the end
    return start;
}

char* mystring::strcat(char *dest, const char *src){
    char *start = dest;

    while(*dest != '\0'){
        dest++;
    }
    
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0'; // add '\0' at the end
    return start;
}

int mystring::strcmp(const char *str1, const char *str2)
{
    while( ( *str1 != '\0' && *str2 != '\0' ) && *str1 == *str2 )
    {
        str1++;
        str2++;
    }

    if(*str1 == *str2)
    {
        return 0;
    }

    else if(*str1 < *str2)
    {
        return -1;
    }
    else
        return 1;
}

char* mystring::strchr(char *str, int c){

    while(*str != '\0'){
        if(*str == c) return (char*)str;
        str++;
    }
    return NULL;
}

char* mystring::strrchr(char *str, int c){
    char* found = NULL;
    while(*str != '\0'){
        if(*str == c) found = (char*)str;
        str++;
    }
    
    return found;
}

int mystring::strlen(const char *str){
    int len = 0;
    while(*str != 0){
        len++;
        str++;
    }
    return len;
}

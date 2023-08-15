#include <iostream>

#include "Header.h"

 // This number of functions allow to access private variables of an object of class Cls. 
 // Assuming we know the order of declaration of variables in the class.
 // Read/write access is granted as the return value type is refference to a field (T&). 

char& get_c(Cls& cls) {

    char* c = (char*)&cls;
    return *c;
}

double& get_d(Cls& cls) {
    
    double* ptr;
    ptr = (double*)((char*)(&cls)) + 1;
    return *ptr;

}

int& get_i(Cls& cls) {
    
    double* tmp = &get_d(cls);
    tmp += 1;
    int& i = *((int*)tmp);
    return i;
}

//Example
/* 
int main()
{
    Cls myObj('c', 2.33, 28);

    std::cout << get_c(myObj) << std::endl;

    std::cout << get_d(myObj) << std::endl;

    std::cout << get_i(myObj) << std::endl;
    return 0;
}*/

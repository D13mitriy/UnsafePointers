#include <iostream>

#include "Header.h"

 // Эта функция должна предоставить доступ к полю c объекта cls.
 // Обратите внимание, что возвращается ссылка на char, т. е.
 // доступ предоставляется на чтение и запись.

char& get_c(Cls& cls) {

    char* c = (char*)&cls;
    return *c;
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double& get_d(Cls& cls) {
    
    double* ptr;
    ptr = (double*)((char*)(&cls)) + 1;
    return *ptr;

}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
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
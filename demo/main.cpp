#include <iostream>
#include "animal.h"

#include "mylib_Export.h"

int main(int argc, char *argv[]){
    std::cout << "Hello, world!" << "\n"; 

    // Create a new animal instance with name Dog
    Animal animal("Dog");

    // try to call the class's print_name method
    animal.printName();
    return 0;
}

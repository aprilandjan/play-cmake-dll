#include <string>
#include "mylib_Export.h"

// using namespace std;

class Animal {
    private:
    std::string name;
    public:
    mylib_EXPORT Animal(std::string name);
    virtual mylib_EXPORT void printName();
};

#include "Array.hpp"

struct  s_MyStruct {
    int a;
    int b;
};

class   MyClass {
    public :
        int a;
        int b;
};

std::ostream &operator<<( std::ostream &os, const s_MyStruct &s ) { return (os << "[a:" << s.a << " | b:" << s.b << "]"); }

std::ostream &operator<<( std::ostream &os, const MyClass &c ) { return (os << "[a:" << c.a << " | b:" << c.b << "]"); }

template <typename T>
static void printElement( const Array<T> &arr, int size )
{
    std::cout << YELLOW "Array: " RESET "{";
    for (int i = 0; i < size; i++)
            std::cout << arr[i] << (i == size - 1 ? "" : ", ");
    std::cout << "}" << std::endl;
}

int main( void )
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    std::cout << std::endl << MAGENTA "--- Int Array ---" RESET << std::endl;
    Array<int>  intArr(5);
    int         size = static_cast<int>(intArr.size());

    for (int i = 0; i < size; i++)
        intArr[i] = std::rand() % 255;
    std::cout << YELLOW "Size: " << RESET << size <<std::endl;
    printElement(intArr, size);

    std::cout << std::endl << MAGENTA "--- Char Array ---" RESET << std::endl;
    Array<char> charArr(10);
    size = static_cast<int>(charArr.size());

    for (int i = 0; i < size; i++)
        charArr[i] = (std::rand() % 95) + 32;
    std::cout << YELLOW "Size: " << RESET << size <<std::endl;
    printElement(charArr, size);

    std::cout << std::endl << MAGENTA "--- Struct Array ---" RESET << std::endl;
    Array<s_MyStruct>   structArr(3);
    size = static_cast<int>(structArr.size());

    for (int i = 0; i < size; i++)
    {
        structArr[i].a = std::rand() % 255;
        structArr[i].b = std::rand() % 255;
    }
    std::cout << YELLOW "Size: " << RESET << size <<std::endl;
    printElement(structArr, size);

    std::cout << std::endl << MAGENTA "--- Class Array ---" RESET << std::endl;
    Array<MyClass>   classArr(2);
    size = static_cast<int>(classArr.size());

    for (int i = 0; i < size; i++)
    {
        classArr[i].a = std::rand() % 255;
        classArr[i].b = std::rand() % 255;
    }
    std::cout << YELLOW "Size: " << RESET << size <<std::endl;
    printElement(classArr, size);

	std::cout << std::endl << MAGENTA "--- Const Class Array ---" RESET << std::endl;
    const Array<MyClass>	constClassArr(classArr);
    size = static_cast<int>(constClassArr.size());

    std::cout << YELLOW "Size: " << RESET << size <<std::endl;
    printElement(constClassArr, size);

    std::cout << std::endl << MAGENTA "--- Empty Array ---" RESET << std::endl;
    Array<int>  emptyArr;
    
    std::cout << YELLOW  "Size: " RESET << emptyArr.size() << std::endl;
    
    std::cout << std::endl << MAGENTA "--- Index out of Bounds ---" RESET << std::endl;
    try
    {
        std::cout << "emptyArr[0]: " << emptyArr[0] << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << RED << e.what() << std::endl;
    }

    std::cout << std::endl << MAGENTA "--- Copy Constructor ---" RESET << std::endl;
    Array<int>	copyIntArr(intArr);
    size = static_cast<int>(copyIntArr.size());

    std::cout << YELLOW "Size: " << RESET << size <<std::endl;
    printElement(copyIntArr, size);

    std::cout << std::endl << MAGENTA "--- Assignment Operator ---" RESET << std::endl;
    Array<char>	copyCharArr = charArr;
    size = static_cast<int>(copyCharArr.size());

    std::cout << YELLOW "Size: " << RESET << size <<std::endl;
    printElement(copyCharArr, size);

    return (0);
}

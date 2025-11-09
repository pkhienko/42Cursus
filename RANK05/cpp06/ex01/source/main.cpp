#include "Serialization.hpp"

int	main( void )
{
	std::cout << MAGENTA << std::endl << "========= Test Serialization =========" << RESET << std::endl;

	Data	p1 = {"Steve", 21, 1, 'M'};
	Data	p2 = {"Alex", 20, 2, 'F'};
	Data	*ptr1 = &p1;
	Data	*ptr2 = &p2;

	std::cout << BLUE << std::endl << "Original Data Pointers" << RESET << std::endl;
	std::cout << GREEN << "-> " YELLOW "Person1" RESET " (Address): " << MAGENTA << ptr1 << RESET << std::endl;
	std::cout << "     Name: " << ptr1->name << std::endl;
	std::cout << "     Age: " << ptr1->age << std::endl;
	std::cout << "     Id: " << ptr1->id << std::endl;
	std::cout << "     Gender: " <<ptr1->gender << std::endl;
	std::cout << GREEN << "-> " YELLOW "Person2" RESET " (Address): " << MAGENTA << ptr2 << RESET << std::endl;
	std::cout << "     Name: " << ptr2->name << std::endl;
	std::cout << "     Age: " << ptr2->age << std::endl;
	std::cout << "     Id: " << ptr2->id << std::endl;
	std::cout << "     Gender: " <<ptr2->gender << std::endl;

	std::cout << BLUE << std::endl << "Serialize Pointer to uintptr_t" << RESET << std::endl;
	uintptr_t raw1 = Serialization::serialize(ptr1);
	uintptr_t raw2 = Serialization::serialize(ptr2);
	std::cout << YELLOW "Person 1" RESET " (Address): " << MAGENTA << "0x" << std::hex << raw1 << std::dec << RESET << std::endl;
	std::cout << YELLOW "Person 2" RESET " (Address): " << MAGENTA << "0x" << std::hex << raw2 << std::dec << RESET << std::endl;

	std::cout << BLUE << std::endl << "Deserialize uintptr_t to Pointer" << RESET << std::endl;
	Data *deserializedPtr1 = Serialization::deserialize(raw1);
	Data *deserializedPtr2 = Serialization::deserialize(raw2);
	std::cout << YELLOW "Person 1" RESET " (Address): " << MAGENTA << deserializedPtr1 << RESET << std::endl;
	std::cout << YELLOW "Person 2" RESET " (Address): " << MAGENTA << deserializedPtr2 << RESET << std::endl;

	std::cout << BLUE << std::endl << "Accessing data via Deserialized pointer" << RESET << std::endl;
	std::cout << GREEN << "-> " YELLOW "Person1" << RESET << std::endl;
	std::cout << "     Name: " << deserializedPtr1->name << std::endl;
	std::cout << "     Age: " << deserializedPtr1->age << std::endl;
	std::cout << "     Id: " << deserializedPtr1->id << std::endl;
	std::cout << "     Gender: " << deserializedPtr1->gender << std::endl;
	std::cout << GREEN << "-> " YELLOW "Person2" << RESET << std::endl;
	std::cout << "     Name: " << deserializedPtr2->name << std::endl;
	std::cout << "     Age: " << deserializedPtr2->age << std::endl;
	std::cout << "     Id: " << deserializedPtr2->id << std::endl;
	std::cout << "     Gender: " << deserializedPtr2->gender << std::endl;

	std::cout << MAGENTA << std::endl << "========= End of Tests =========" << RESET << std::endl;
	return (0);
}

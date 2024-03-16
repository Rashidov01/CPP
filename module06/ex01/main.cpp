#include "Serialize.hpp"

int	main(void)
{
	Data data;
	data.name = "arashido";
	data.age = 42;

	uintptr_t serializedValue = Serialize::serialize(&data);
	std::cout << "serializedValue  : " << serializedValue << std::endl;
	Data *deserializedValue = Serialize::deserialize(serializedValue);
	std::cout << "&data            : " << &data << std::endl;
	std::cout << "deserializeValue : " << deserializedValue << std::endl;
	std::cout << deserializedValue->name << " " << deserializedValue->age << std::endl;
	return (0);
}
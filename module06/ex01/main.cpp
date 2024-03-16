#include "Serialize.hpp"

int main()
{
	Data data;
	data.s = "Data";
	data.n = 42;

	uintptr_t serializedValue = Serialize::serialize(&data);
	std::cout << "serializedValue  : " << serializedValue << std::endl;
	Data *deserializedValue = Serialize::deserialize(serializedValue);
	std::cout << "&data            : " << &data << std::endl;
	std::cout << "deserializeValue : " << deserializedValue << std::endl;
	std::cout << deserializedValue->s << " + " << deserializedValue->n << std::endl;
	return (0);
}
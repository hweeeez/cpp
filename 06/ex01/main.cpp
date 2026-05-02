#include "Serializer.hpp"

int main()
{
	Data* data = new Data();
	data->x = 42;

	uintptr_t uintval = Serializer::serialize(data);
	Data* uintdata = Serializer::deserialize(uintval);

	std::cout << "OG pointer: " << uintdata << '\n';
	std::cout << "Deserialized pointer: " << uintdata << '\n';
	std::cout << "Deserialized value: " << uintdata->x << '\n';
	std::cout << (data == uintdata ? "They are equal." : "They are NOT equal.") << '\n';
	delete data;
}
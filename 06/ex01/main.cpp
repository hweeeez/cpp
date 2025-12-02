#include "Serializer.hpp"

int main()
{
	Data* data = new Data();

	uintptr_t uintval = Serializer::serialize(data);
	Data* uintdata = Serializer::deserialize(uintval);

	std::cout << (Data*)uintdata << '\n';
	std::cout << (Data*)data << '\n';
}
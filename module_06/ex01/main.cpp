#include "Data.hpp"
#include "main.hpp"

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main(void)
{
	std::cout << "=============================" << std::endl;
	std::cout << "TEST #1" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		Data *data;
		uintptr_t serialized;
		Data *deserialized;

		data = new Data();
		data->x = 22;
		data->y = 0;

		std::cout << "Data" << std::endl;
		std::cout << "address: " << data << std::endl;
		std::cout << "x: " << data->x << ", y: " << data->y << std::endl << std::endl;

		serialized = serialize(data);
		std::cout << "Serialized Data" << std::endl;
		std::cout << serialized << std::endl << std::endl;

		deserialized = deserialize(serialized);
		std::cout << "Deserialized Data" << std::endl;
		std::cout << "address: " << deserialized << std::endl;
		std::cout << "x: " << deserialized->x << ", y: " << deserialized->y << std::endl << std::endl;
	}

	std::cout << "=============================" << std::endl;
	std::cout << "TEST #2" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		Data *data;
		uintptr_t serialized;
		Data *deserialized;

		data = new Data();
		data->x = -50000;
		data->y = 4242;

		std::cout << "Data" << std::endl;
		std::cout << "address: " << data << std::endl;
		std::cout << "x: " << data->x << ", y: " << data->y << std::endl << std::endl;

		serialized = serialize(data);
		std::cout << "Serialized Data" << std::endl;
		std::cout << serialized << std::endl << std::endl;

		deserialized = deserialize(serialized);
		std::cout << "Deserialized Data" << std::endl;
		std::cout << "address: " << deserialized << std::endl;
		std::cout << "x: " << deserialized->x << ", y: " << deserialized->y << std::endl << std::endl;
	}
}
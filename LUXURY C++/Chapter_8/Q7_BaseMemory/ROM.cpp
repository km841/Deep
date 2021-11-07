#include "pch.h"
#include "ROM.h"

ROM::ROM(int size, char arr[], int arr_size) : BaseMemory(size)
{
	for (int i = 0; i < arr_size; i++)
	{
		write(i,  arr[i]);
	}
}

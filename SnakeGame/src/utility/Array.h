#pragma once
#include <initializer_list>

template<typename T>
class Array
{
private:
	T* array;
	unsigned int size;
public:
	Array(): array(nullptr), size(0) { };
	Array(T* array, unsigned int size) : size(size)
	{
		init(array, size);
	}

	Array(Array& other): Array(other.array, other.size) { }

	Array(Array&& other)
	{
		array = other.array;
		size = other.size;
		other.array = nullptr;
		other.size = 0;
	}

	Array(std::initializer_list<T> const& il)
	{
		size = il.size();
		array = new T[size];
		int i = 0;
		for (auto it = il.begin(); it !=il.end(); it++)
		{
			array[i++] = *it;
		}
	}

	void operator=(Array& other)
	{
		clear();
		init(other.array, other.size);
	}
	
	void operator=(Array&& other)
	{
		clear();
		array = other.array;
		size = other.size;
		other.array = nullptr;
		other.size = 0;
	}

	~Array()
	{
		delete[] array;
	}

	T& operator[](int index)
	{
		return array[index];
	}

	operator T*() { return array; }

	inline unsigned int getSize() { return size; }
	inline unsigned int getByteSize() { return sizeof(T) * size; }

private:
	void init(T* array, unsigned int size)
	{
		this->array = new T[size];
		for (int i = 0; i < size; i++) {
			this->array[i] = array[i];
		}
	}
	void clear()
	{
		delete[] array;
		array = nullptr;
		size = 0;
	}
};


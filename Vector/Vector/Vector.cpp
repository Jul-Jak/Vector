#pragma once
template<class T>
class Vector
{
private:
	T* data;
	size_t size;
	size_t capacity;
public:
	Vector()
	{
		data = nullptr;
		size = capacity = 0;
	}

	~Vector()
	{
		delete[]data;
		data = nullptr;
	}

	Vector(int n)
	{
		size = capacity = n;
		data = new T[n];
		for (int i = 0; i < n; i++) data[i] = 0;
	}

	Vector(int n, T* array)
	{
		size = capacity = n;
		data = new T[size];
		for (size_t i = 0; i < size; i++) data[i] = array[i];
	}

	Vector(const Vector& v)
	{
		delete[]data;
		size = v.size;
		capacity = v.capacity;
		T* data = new T[size];
		for (size_t i = 0; i < size; i++) data[i] = v.data[i];
	}

	void push_back(T elem)
	{
		if (size == capacity)
		{
			capacity = 1.5 * size;
			T* temp = new T[capacity];
			for (int i = 0; i < size; i++)	temp[i] = data[i];
			if (data != nullptr)
				delete[] data;
			data = temp;
		}
		data[size++] = elem;
	}

	void pop_back()
	{
		size--;
	}

	void resize(int n)
	{
		T* temp = new T[n];
		unsigned int i;
		if (n > size)
		{
			for (i = 0; i < size; i++) temp[i] = data[i];
			for (i = size; i < n; i++) temp[i] = 0;
		}
		else
			for (i = 0; i < n; i++) temp[i] = data[i];
		if (data != nullptr)
			delete[] data;
		data = temp;
	}

	void insert(T Elem, int index)
	{
		T* temp = new T[size + 1];
		unsigned int i;
		for (int i = 0; i < index; i++) temp[i] = data[i];
		temp[index] = Elem;
		for (i = index; i < size; i++) temp[i + 1] = data[i];
		if (data != nullptr)
			delete[] data;
		data = temp;
	}

	void erase(int index)
	{
		T* temp = new T[capacity];
		for (int i = 0; i < index - 1; i++)
			temp[i] = data[i];
		for (int i = index - 1; i < size; i++)
			temp[i] = data[i + 1];
		delete[]data;
		data = temp;
		size--;
	}

	T& operator[](int index)
	{
		return this->data[index];
	}
	T operator[](int index)const
	{
		return this->data[index];
	}
};
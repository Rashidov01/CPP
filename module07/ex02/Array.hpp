#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>

class Array
{
  private:
	T *elements;
	size_t length;

  public:
	Array() : elements(nullptr), length(0)
	{
	}

	Array(unsigned int n) : length(n)
	{
		elements = new T[length];
		for (size_t i = 0; i < length; ++i)
			elements[i] = T();
	}

	Array(const Array &other) : length(other.length)
	{
		elements = new T[length];
		for (size_t i = 0; i < length; ++i)
			elements[i] = other.elements[i];
	}

	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] elements;
			length = other.length;
			elements = new T[length];
			for (size_t i = 0; i < length; ++i)
				elements[i] = other.elements[i];
		}
		return (*this);
	}

	~Array()
	{
		delete[] elements;
	}

	T &operator[](unsigned int index)
	{
		if (index >= length)
		{
			throw std::out_of_range("Index out of range");
		}
		return (elements[index]);
	}

	size_t size() const
	{
		return (length);
	}
};

#endif
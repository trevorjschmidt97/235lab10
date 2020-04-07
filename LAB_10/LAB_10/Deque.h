#ifndef DEQUE_H
#define DEQUE_H
#include <string>
#include <iostream>
#include <sstream>
#define DEFAULT_CAPACITY 4

using namespace std;

template<typename T>
class Deque
{
private:
	size_t capacity;
	size_t num_items;
	size_t front_index;
	size_t rear_index;
	T* the_data;

	void reallocate()
	{
		size_t new_capacity = 2 * capacity;
		T* new_data = new T[new_capacity];
		size_t j = front_index;

		for (size_t i = 0; i < num_items; i++)
		{
			new_data[i] = the_data[j];
			j = (j + 1) % capacity;
		}

		front_index = 0;
		if (num_items > 1)
		{
			rear_index = num_items - 1;
		}
		capacity = new_capacity;
		std::swap(the_data, new_data);

		delete[] new_data;
	}

public:
	Deque(void) :
		capacity(DEFAULT_CAPACITY),
		num_items(0),
		front_index(0),
		rear_index(DEFAULT_CAPACITY),
		the_data(new T[DEFAULT_CAPACITY]) {}

	virtual ~Deque(void) { delete[] the_data; }

	void setCapacity(size_t capacity)
	{
		this->capacity = capacity;
		delete[] the_data;

		num_items = 0;
		front_index = 0;
		rear_index = capacity - 1;
		the_data = new T[capacity];
	}

	virtual void push_front(const T& value)  /** Insert item at front of deque */
	{
		if (num_items == capacity)
		{
			reallocate();
		}
		num_items++;
		front_index = (front_index - 1) % capacity;
		the_data[front_index] = value;
	}

	virtual void push_back(const T& value)	/** Insert item at rear of deque */
	{
		if (num_items == capacity)
		{
			reallocate();
		}
		num_items++;
		rear_index = (rear_index + 1) % capacity;
		the_data[rear_index] = value;
	}

	virtual void pop_front(void)	/** Remove the front item of the deque */
	{
		num_items--;
		front_index = (front_index + 1) % capacity;

	}
	virtual void pop_back(void)	/** Remove the rear item of the deque */
	{
		num_items--;
		rear_index = (rear_index - 1) % capacity;
	}
	virtual T& front(void)	/** Return the front item of the deque (Do not remove) */
	{
		return the_data[front_index];
	}
	virtual T& back(void)	/** Return the rear item of the deque (Do not remove) */
	{
		return the_data[rear_index];
	}
	virtual size_t size(void) const	/** Return the number of items in the deque */
	{
		return num_items;
	}
	virtual size_t getCapacity(void) const /** Return the capacity of the current data structure */
	{
		return capacity;
	}
	virtual bool empty(void) const	/** Return true if deque is empty */
	{
		return (num_items == 0);
	}
	virtual T& at(size_t index)	/** Return item in deque at index (0 based) */
	{
		return the_data[index];
	}
	virtual std::string toString(void) const	/** Return the deque items */
	{
		stringstream s;
		if (num_items == 0)
		{
			return "Empty";
		}
		for (size_t i = 0; i < num_items - 1; ++i)
		{
			s << the_data[(front_index + i) % capacity] << ",";
		}
		s << the_data[(front_index + num_items - 1) % capacity];
		return s.str();
	}
};
#endif // DEQUE_H
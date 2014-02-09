#ifndef AUTOPTR_H
#define AUTOPTR_H

template<typename T>
class AutoPtr
{
public:
	AutoPtr(T* ptr);
	~AutoPtr();

	T& operator*();
	T* operator->();
	T* release();
	operator bool();

private:
	AutoPtr(const AutoPtr<T>& copy);
	AutoPtr& operator=(AutoPtr<T>& rhs);

	T* ptr_;
};

template<typename T>
AutoPtr<T>::AutoPtr(T* ptr)
	:ptr_(ptr)
{
}

template<typename T>
AutoPtr<T>::~AutoPtr()
{
	delete ptr_;
}

template<typename T>
T& AutoPtr<T>::operator*()
{
	return *ptr_;
}

template<typename T>
T* AutoPtr<T>::operator->()
{
	return ptr_;
}

template<typename T>
T* AutoPtr<T>::release()
{
	T* temp = ptr_;
	ptr_ = 0;
	return temp;
}

template<typename T>
AutoPtr<T>::operator bool()
{
	return ptr_;
}

#endif

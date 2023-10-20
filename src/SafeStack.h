#ifndef _SAFE_STACK
#define _SAFE_STACK

#include <stack>
#include <stdexcept>

/*
 A safe stack that it will throw exception(domain_error in <stdexcept>) instead of causing segument fault.
 It will check underflow.
 It won't check overflow because it depends on implemetion.
*/
template <typename T>
class SafeStack
{
private:
	std::stack<T> s;

public:
	
	SafeStack() {}
	SafeStack(std::stack<T> target) : s(target) {}
	// C++ syntax doesn't allow declare constructor as a friend
	SafeStack(SafeStack<T>&) = delete;
	virtual ~SafeStack() {}
	
	// C++ syntax doesn't allow declare operator= as a friend
	SafeStack& operator=(const SafeStack&) = delete;
	
	bool empty() const
	{
		return s.empty();
	}
	
	void push(T val)
	{
		s.push(val);
	}
	
	void pop()
	{
		if (empty()) throw std::domain_error("pop when stack is empty");
		else s.pop();
	}
	
	T& top()
	{
		if (empty()) throw std::domain_error("top when stack is empty");
		return s.top();
	}
	
};

#endif

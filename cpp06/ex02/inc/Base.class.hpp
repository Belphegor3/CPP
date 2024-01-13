#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

class Base{
	public:
		virtual ~Base(){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
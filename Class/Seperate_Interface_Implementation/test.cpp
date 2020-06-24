/*
 * Filename: test.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/06/22 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-06-22
 * LastChange: 2020-06-22
 *    Version: v0.0.01
 *
 */
#include <iostream>
//#include <string.h>
#include <typeinfo>
#include "Person.h"
using namespace std;

int main(){
	string name="peter";
	Person P(name);
	const type_info &nInfo = typeid(P.getName());
	cout << nInfo.name()<<endl;
	cout << typeid(double).name()<<endl;
	printf("Hello %s, how old are you?\n",name);// name will display as mess code.
												//cause:https://blog.csdn.net/qq_37032670/article/details/77505841
	printf("Hello %s, how old are you?\n",name.c_str());
	printf("Hello %s, how old are you?\n",P.getName().c_str());
	cout << P.getName() << endl;
	cout << P.getName().c_str() << endl;
}

//using Date = std::string;//仅供示例，因此不实现Date类了
//using Address = std::string;

//class PersonImpl {
//public:
//PersonImpl(const std::string &name, const Date& birthday, const Address& addr) {
//this->theName = name;
//this->theBirthDate = birthday;
//this->theAddress = addr;
//}

//std::string name() const { return theName; }
//std::string birthDate() const { return theBirthDate; }
//std::string address() const { return theAddress; }

//private:
//std::string theName;
//Date theBirthDate;
//Address theAddress;
//};

//class Person {
//public:
//Person(const std::string &name, const Date& birthday, const Address& addr);

//std::string name() const;
//std::string birthDate() const;
//std::string address() const;

//private:
//std::shared_ptr<PersonImpl> pImpl;//Person的实现部分，使用指针，将Person类变成只有接口的类， 而把实现部分放到另一个类中实现，并引用这个类对象的指针来进行操作
//};

//Person::Person(const std::string &name, const Date& birthday, const Address& addr):
//pImpl(new PersonImpl(name,birthday,addr)){
//}

//std::string Person::name() const {
//return pImpl->name();
//}

//std::string Person::birthDate() const {
//return pImpl->birthDate();
//}

//std::string Person::address() const {
//return pImpl->address();
//}

//void showInfo(Person &p) {
//std::cout << "---Person Info---" << std::endl;
//std::cout << "Name: " << p.name() << std::endl;
//std::cout << "Birthday: " << p.birthDate() << std::endl;
//std::cout << "Address: " << p.address() << std::endl;
//std::cout << "---The End-------" << std::endl;
//}

//int main(){
//Person p("Jack", "10/09/2010", "NewYork");
//showInfo<Person>(p);
//return 0;
//}

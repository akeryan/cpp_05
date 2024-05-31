/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:41:37 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 12:51:28 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Form.hpp"

Form::Form():	_name("Default"), _isSigned(false), 
				_gradeToSign(150), _gradeToExecute(150) 
{ 
	std::cout << "Form default constructor is called" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute):
				_name(name), _isSigned(false), _gradeToSign(gradeToSign), 
				_gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor is called, form \"" << this->getName() << "\" is attempted to be created" << std::endl;
	try {
		if (name.empty()) {
			throw (EmptyStringException());
		}
		if (gradeToExecute < 1 || gradeToSign < 1) {
			throw (GradeTooHighException());
		}
		if (gradeToExecute > 150 || gradeToSign > 150) {
			throw (GradeTooLowException());
		}
	}
	catch (GradeTooLowException) {
		std::cout	<< "<EXCEPTION> Form " << name 
					<< " failed to be created: grade " << gradeToSign
					<< " is too LOW and needs to be higher" << std::endl;
		throw ;
	}
	catch (GradeTooHighException) {
		std::cout	<< "<EXCEPTION> Form " << name 
					<< " failed to be created: grade " << gradeToExecute 
					<< " is too HIGH and needs to be lower" << std::endl;
		throw ;
	}
	catch (EmptyStringException) {
		std::cout	<< "<EXCEPTION> Form " << name 
					<< " failed to be created, since the name is an empty string " << std::endl;
		throw ;
	}
	std::cout << "Form " << name << " is created" << std::endl;
}

Form::Form(const Form &obj):	_name(obj.getName()), 
								_gradeToSign(obj.getGradeToExecute()),
								_gradeToExecute(obj.getGradeToExecute())
{
	std::cout << "Form copy constructor is called" << std::endl;
	*this = obj;
}

const Form &Form::operator=(const Form &other)
{
	if (this != &other) {
		this->_isSigned = other.getSignatureStatus();
	}
	return *this;
}

Form::~Form() 
{
	std::cout << "Form destructor is called, object \"" << this->getName() << "\" destroyed" << std::endl;
}

std::string Form::getName(void) const
{
	return this->_name;
}

bool Form::getSignatureStatus(void) const
{
	return this->_isSigned;
}

int Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

int Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

void Form::beSigned(const Bureaucrat &be)
{
	if (be.getGrade() > this->getGradeToSign()) {
		throw (Form::GradeTooLowException());
	}
	this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &osObj, const Form &obj)
{
	osObj	<< "Form name: " << obj.getName() 
			<< ", grade to sign: " << obj.getGradeToSign()
			<< ", grade to execute: " << obj.getGradeToExecute()
			<< ", is signed?: " << obj.getSignatureStatus();
	return osObj;
}






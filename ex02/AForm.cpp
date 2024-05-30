/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:49:01 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/30 19:33:21 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AForm.hpp"

AForm::AForm():	_name("Default"), _isSigned(false), 
				_gradeToSign(150), _gradeToExecute(150) 
{ 
	std::cout << "Abstract_Form default constructor is called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute):
				_name(name), _isSigned(false), _gradeToSign(gradeToSign), 
				_gradeToExecute(gradeToExecute)
{
	std::cout << "Abstract_Form constructor is called, form \"" << this->getName() << "\" is attempted to be created" << std::endl;
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
	std::cout << "AForm \"" << name << "\" is created" << std::endl;
}

AForm::AForm(const AForm &obj):	_name(obj.getName()), 
								_gradeToSign(obj.getGradeToExecute()),
								_gradeToExecute(obj.getGradeToExecute())
{
	std::cout << "Form copy constructor is called" << std::endl;
	*this = obj;
}

const AForm &AForm::operator=(const AForm &other)
{
	if (this != &other) {
		this->_isSigned = other.getSignatureStatus();
	}
	return *this;
}

AForm::~AForm() 
{
	std::cout	<< "AForm destructor is called, object \"" << this->getName() 
				<< "\" destroyed" << std::endl;
}

std::string AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getSignatureStatus(void) const
{
	return this->_isSigned;
}

int AForm::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

int AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

std::ostream &operator<<(std::ostream &osObj, const AForm &obj)
{
	osObj	<< "Form name: " << obj.getName() 
			<< ", grade to sign: " << obj.getGradeToSign()
			<< ", grede to execute: " << obj.getGradeToExecute()
			<< ", is signed?: " << obj.getSignatureStatus();
	return osObj;
}

void AForm::setSignatureStatus(const bool status)
{
	this->_isSigned = status;
}

int AForm::execute(Bureaucrat const &executor) const
{
	try {
		std::cout << "AForm's execute() function called" << std::endl;
		if (this->getSignatureStatus() == false) {
			std::cout	<< "Unable to execute form \"" << this->getName() 
						<< "\" since it is not signed" << std::endl;
			return 1;
		} else if (executor.getGrade() > this->getGradeToExecute())
			throw (AForm::GradeTooLowException());
		this->_execute();
	} catch (AForm::GradeTooLowException) {
		std::cout	<< "<EXCEPTION>: The form \"" << this->getName()
					<< "\" cannot be signed since " << executor.getName()
					<< " required to have higher grade" << std::endl;
		throw ;
	}
	return 0;
}

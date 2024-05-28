/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 09:33:10 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/28 17:07:35 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) 
{
	std::cout <<"Bureaucrat default constructor called: _name = 'Default', _grade = 150" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name)
{
	std::cout << "Bureaucrat constructor called: _name: " << name << ", _grade: " << grade << std::endl;
	if(name.empty()) {
		throw EmptyStringException();
	}
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	this->_grade = grade;
}

const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &obj) {
		this->_grade = obj.getGrade();
	}
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = obj;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor for \"" << this->getName() << "\" is called" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
	std::cout << "IncrementGrade for \"" << this->getName() << "\" is called" << std::endl;
	if (this->_grade == 1)
		throw GradeTooHighException("Grade has the highest value (1), and cannot be incremented further");
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	std::cout << "DecrementGrade for \"" << this->getName() << "\" is called" << std::endl;
	if (this->_grade ==150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout	<< "Bueraucrat " << this->getName()
					<< "signed " << form.getName()
					<< std::endl;
	} catch (GradeTooLowException) {
		std::cout	<< "Bureaucrat " << this->getName()
					<< " couldn't sign " << form.getName()
					<< " because " << this->getName()
					<< " needs to have grade >= " << form.getGradeToSign()
					<< std::endl;
		throw ;		
	}
}

std::ostream &operator<<(std::ostream &osObj, const Bureaucrat &obj) {
	osObj	<< "Bueraucrat name: " << obj.getName() 
			<< ", grade: " << obj.getGrade() 
			<< "." << std::endl;
	return osObj;
}


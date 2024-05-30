/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:07:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/30 19:36:30 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default construcor was called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const std::string target): 
	AForm(name, 145, 137)
{
	std::cout	<< "ShrubberyCreationForm construcor called: " 
				<< "object \"" << name << "\" is created" << std::endl;
	if (target == "")
		throw (AForm::EmptyStringException());
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other) 
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &be)
{
	if (be.getGrade() > this->getGradeToSign())
		throw (AForm::GradeTooLowException());
	this->setSignatureStatus(true);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
} 

void ShrubberyCreationForm::setTarget(const std::string target)
{
	if (target == "")
		throw (AForm::EmptyStringException());
	else
		this->setTarget(target);
}

void ShrubberyCreationForm::_execute(void) const
{
	std::string filename = this->getTarget() + "_shrubbery";
	std::string	tree = "          &&& &&  & &&\n      && &--&-|& ()|- @, &&\n      &--(-&-&||-& -_-)_&-_&\n   &() &--&|()|-&-- '% & ()\n  &_-_&&_- |& |&&-&__%_-_& &&\n&&   && & &| &| -& & % ()& -&&\n ()&_---()&-&-|&&-&&--%---()~\n     &&     -|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n";
	std::ofstream file(filename.c_str());
	
	if (file.is_open()) {
		file << tree;
	} else {
		std::cout << "ERROR: file failed to open in ShrubberyCreationForm::_execute()" << std::endl;
	}
}
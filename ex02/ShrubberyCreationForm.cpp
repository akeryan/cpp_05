/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:07:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/30 15:25:02 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default construcor was called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name): AForm(name, 145, 137)
{
	std::cout << "ShrubberyCreationForm construcor was called: " << name << std::endl;
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
	if (be.getGrade() != this->getGradeToSign()) {
		throw (AForm::GradeTooLowException());
	}
	this->_isSigned = true;
}


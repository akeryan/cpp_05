/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:37:40 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 19:11:17 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::forms[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
	funcs[0] = &Intern::shrubbery;
	funcs[1] = &Intern::robotomy;
	funcs[2] = &Intern::presidential;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

const Intern &Intern::operator=(const Intern &obj)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)obj;
	return *this;
}

Intern::Intern(const Intern &obj)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = obj;
}

AForm *Intern::shrubbery(const std::string formTarget)
{
	AForm *ptr = new ShrubberyCreationForm(formTarget);
	return ptr; 
}

AForm *Intern::robotomy(const std::string formTarget)
{
	AForm *ptr = new RobotomyRequestForm(formTarget);
	return ptr; 
}

AForm *Intern::presidential( const std::string formTarget)
{
	AForm *ptr = new PresidentialPardonForm(formTarget);
	return ptr; 
}

AForm *Intern::makeForm(const std::string formName, const std::string formTarget)
{
	AForm *formPtr = NULL;

	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			formPtr = (this->*funcs[i])(formTarget);
		}
	}
	if (!formPtr)
		throw (FormCreationFailureException());
	return formPtr;
}


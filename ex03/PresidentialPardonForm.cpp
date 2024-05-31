/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:14:03 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 16:20:32 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Default", 25, 5)
{
	std::cout << "PresidentialPardonForm Default construcor was called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): 
	AForm("Presidential", 25, 5)
{
	std::cout	<< "PresidentialPardonForm construcor called: " 
				<< "object \"" << this->getName() 
				<< " with target \"" << target 
				<< "\" is attempted to be created" << std::endl;
	if (target == "") {
		throw (AForm::EmptyStringException());
	}
	this->_target = target;
	std::cout	<< "PresidentialPardonForm object \"" << this->getName()
				<< "\" with target \"" << target << "\" is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other) 
{
	std::cout << "PresidentialPardonForm copy constructor called\n";
	this->_target = other.getTarget();
}

const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout	<< "PresidentialPardonForm destructor called, object \"" << this->getName() 
				<< "\" with target \"" << this->getTarget()
				<< "\" destroyed" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
} 

void PresidentialPardonForm::setTarget(const std::string target)
{
	if (target == "")
		throw (AForm::EmptyStringException());
	else
		this->setTarget(target);
}

void PresidentialPardonForm::_execute(void) const
{
	std::cout	<< "Presidential \"" << this->getTarget()
				<< "\" has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &osObj, const PresidentialPardonForm &obj) {
		osObj	<< static_cast<const AForm&>(obj) 
				<< ", target: " << obj.getTarget();
	return osObj;
}

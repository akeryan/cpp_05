/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:52:24 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 16:05:59 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Default", 72, 45)
{
	std::cout << "RobotomyRequestForm Default construcor was called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): 
	AForm("Robotomy", 72, 45)
{
	std::cout	<< "RobotomyRequestForm construcor called: " 
				<< "object \"" << this->getName() 
				<< " with target \"" << target 
				<< "\" is attempted to be created" << std::endl;
	if (target == "") {
		throw (AForm::EmptyStringException());
	}
	this->_target = target;
	std::cout	<< "RobotomyRequestForm object \"" << this->getName()
				<< "\" with target \"" << target << "\" is created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other) 
{
	std::cout << "RobotomyRequestForm copy constructor called\n";
	this->_target = other.getTarget();
}

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout	<< "RobotomyRequestForm destructor called, object \"" << this->getName() 
				<< "\" with target \"" << this->getTarget()
				<< "\" destroyed" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
} 

void RobotomyRequestForm::setTarget(const std::string target)
{
	if (target == "")
		throw (AForm::EmptyStringException());
	else
		this->setTarget(target);
}

void RobotomyRequestForm::_execute(void) const
{
	time_t current_time = time(NULL);
	if (current_time % 2) {
		std::cout	<< "Robotomy \"" << this->getTarget()
					<< "\" has been robotomized successfully" << std::endl;
	} else {
		std::cout	<< "Robotomy of \"" << this->getTarget()
					<< "\" failed" << std::endl;
	}
	
}

std::ostream &operator<<(std::ostream &osObj, const RobotomyRequestForm &obj) {
		osObj	<< static_cast<const AForm&>(obj) 
				<< ", target: " << obj.getTarget();
	return osObj;
}

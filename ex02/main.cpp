/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:37:54 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 16:07:46 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat a("Boris", 10);
	//ShrubberyCreationForm sh2("Street");
	//std::cout << "STREET TAFGET: " << sh2.getTarget() << std::endl;
	//std::cout << sh2 << std::endl;
	//AForm *fPtr = new ShrubberyCreationForm("Park");

// Printing ShrubberyCreationForm through AForm pointer 
	//if (ShrubberyCreationForm *shPtr = dynamic_cast<ShrubberyCreationForm *>(fPtr)) {
		//std::cout << *shPtr << std::endl;
	//} else {
		//std::cout << "Failed to cast AForm* to ShrubberyCreationForm*" << std::endl;
	//}

	//a.signForm(*fPtr);
	//a.executeForm(*fPtr);

	RobotomyRequestForm r("roboto");
	a.signForm(r);
	a.executeForm(r);

	return 0;
}
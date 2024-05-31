/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:37:54 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 17:09:28 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try {
		Bureaucrat a("Boris", 2);
		AForm *shPtr = new ShrubberyCreationForm("Park");
		AForm *rPtr = new RobotomyRequestForm("Robo");
		AForm *pPtr = new PresidentialPardonForm("Bill");

		std::cout << std::endl << "SHRUBBERY FORM >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
	// Printing and Executing ShrubberyCreationForm through AForm pointer 
		if (ShrubberyCreationForm *newPtr = dynamic_cast<ShrubberyCreationForm *>(shPtr)) {
			std::cout << *shPtr << std::endl;
		} else {
			std::cout << "Failed to cast AForm* to ShrubberyCreationForm*" << std::endl;
		}
		a.signForm(*shPtr);
		a.executeForm(*shPtr);
		
		std::cout << std::endl << "ROBOTOMY FORM >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
		a.signForm(*rPtr);
		a.executeForm(*rPtr);	

		std::cout << std::endl << "PRESIDENTIAL FORM >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
		a.signForm(*pPtr);
		a.executeForm(*pPtr);

		std::cout << std::endl << "DONE ----------------------------------------------------" << std::endl;
	
		delete shPtr;
		delete rPtr;
		delete pPtr;
	} catch (std::exception &e) {
		std::cout << std::endl << "<EXCEPTION>: Caught in main(): " << e.what() << std::endl;
	}


	return 0;
}
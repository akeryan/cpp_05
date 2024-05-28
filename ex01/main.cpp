/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:37:54 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/28 19:36:28 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	try {
		Bureaucrat a("Boris", 3);
		Form form1("Form_1", 5, 2);
		std::cout << form1 << std::endl;
		std::cout	<< "Form info: form_name: " << form1.getName() 
					<< ", is_signed?: " << form1.getSignatureStatus()
					<< ", grade_to_sign: " << form1. getGradeToSign()
					<< ", grade_to_execute: " << form1.getGradeToExecute()
					<< std::endl;
		std::cout << std::endl;

	//Form creation with out of range grade to sign
		Form form_2("Form_2", 160, 30);
		std::cout << std::endl;

	//Form creation with out of range grade to execute 
		Form form_3("Form_3", 80, -5);
		std::cout << std::endl;
		
	//Form creation with empty name
		Form form_4("", 80, 5);
		std::cout << std::endl;

	//testing form signing
	a.signForm(form1);

	//signing contract by a bureaucrat without corresponding signing grade 
	Form form5("Form_5", 2, 2);
	a.signForm(form5);

	} catch (std::exception &e) {
		std::cout << std::endl << "<EXCEPTION>: Caught in main(): " << e.what() << std::endl;
	}

	return 0;
}
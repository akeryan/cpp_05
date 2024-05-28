/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:37:54 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/28 17:04:47 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try {
	// assigning too low grade
		Bureaucrat d("Alex", -5);
	// assigning loo high grade
		Bureaucrat c("Alex", 155);

	//Custom values assigned
		Bureaucrat b("Boris", 2);
		std::cout << b << std::endl;
		
	//test getters:
		std::cout<< "Bureaucrat " << b.getName() << " has grade " << b.getGrade() << std::endl;
		
	//Incrementing grade
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
	} catch (std::exception &e) {
		std::cout << "<EXCEPTION>: Caught in main(): " << e.what() << std::endl;
	}

	return 0;
}
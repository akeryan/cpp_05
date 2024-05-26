/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:37:54 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/26 16:16:45 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try {
		Bureaucrat a;
		std::cout << a << std::endl;
		Bureaucrat b("Boris", 2);
		std::cout << b << std::endl;
		b.incrementGrade();
		//b.incrementGrade();

		Bureaucrat c("Dominic", 500);

		//Bureaucrat d("", 100);
		//Bureaucrat c("Alex", 155);
	} catch (std::exception &e) {
		std::cout << "<EXCEPTION>: Caught in main(): " << e.what() << std::endl;
	}

	return 0;
}
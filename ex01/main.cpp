/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:37:54 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/28 17:17:48 by akeryan          ###   ########.fr       */
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
		
	} catch (std::exception &e) {
		std::cout << "<EXCEPTION>: Caught in main(): " << e.what() << std::endl;
	}

	return 0;
}
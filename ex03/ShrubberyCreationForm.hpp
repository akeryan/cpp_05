/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:01:40 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 14:07:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRY_CREATION_FORM_HPP
#define SHRUBBERRY_CREATION_FORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm();
		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	//getters:
		std::string getTarget(void) const;
	//setters:
		void setTarget(const std::string target);
	//other:
		void _execute(void) const;		
	private:
		std::string _target;
};

// Overloaded non-member operators
std::ostream &operator<<(std::ostream &osObj, const ShrubberyCreationForm &obj);
#endif
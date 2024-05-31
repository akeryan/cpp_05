/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:20:05 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 18:58:39 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		static const std::string forms[3];
		Intern();
		~Intern();
		Intern(const Intern &other);
		const Intern &operator=(const Intern &other);
		AForm *makeForm(const std::string formName, const std::string formTarget);
		
		class FormCreationFailureException: public std::exception
		{
			public:
				FormCreationFailureException():_msg("Wrong form name") { }
				FormCreationFailureException(const char *str):_msg(str) { }
				const char *what() const throw() { return _msg; }
			private:
				const char *_msg;	
		};
	private:
		AForm *(Intern::*funcs[3])(const std::string formTarget);
		AForm *shrubbery(const std::string formTarget);
		AForm *robotomy(const std::string formTarget);
		AForm *presidential(const std::string formTarget);

};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:22:53 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 13:50:30 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
class Form;

class Bureaucrat
{
	public:
		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException():_msg("Grade is too HIGH") { }
				GradeTooHighException(const char *str):_msg(str) { }
				const char *what() const throw() { return _msg; }
			private:
				const char *_msg;	
		};
		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException():_msg("Grade is too LOW") {};
				const char *what(void) const throw() { return _msg; }
			private:
				const char *_msg;	
		};
		class EmptyStringException: public std::exception
		{
			public:
				EmptyStringException():_msg("String is EMPTY") { }
				const char *what(void) const throw() { return _msg; }
			private:
				const char *_msg;	
		};
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &obj);
		const Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();
	// getters
		std::string getName(void) const;
		int getGrade(void) const;
	// other
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form &form);
	private:
		const std::string _name;
		int	_grade;
};

// Overloaded non-member operators
std::ostream &operator<<(std::ostream &osObj, const Bureaucrat &obj);

#endif
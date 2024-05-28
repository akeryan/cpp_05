/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:48:01 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/28 19:48:29 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <string>
# include "Bureaucrat.hpp"
class Bureaucrat;

class AForm 
{
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const Form &obj);
		~AForm();
		const Form &operator=(const Form &obj);

	//getters:
		std::string getName(void) const;
		bool getSignatureStatus(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
	
	//other:
		void beSigned(const Bureaucrat &obj);

	//nested classes:	
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
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
};

// Overloaded non-member operators
std::ostream &operator<<(std::ostream &osObj, const Form &obj);

#endif
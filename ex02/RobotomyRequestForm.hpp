/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:52:10 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 15:58:24 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <ctime>

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		~RobotomyRequestForm();
		const RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

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
std::ostream &operator<<(std::ostream &osObj, const RobotomyRequestForm &obj);

#endif
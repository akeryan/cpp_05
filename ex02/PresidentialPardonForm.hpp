/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:13:53 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/31 16:16:22 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRESIDENTIAL_PARDON_FORM_HPP 
#define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		~PresidentialPardonForm();
		const PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

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
std::ostream &operator<<(std::ostream &osObj, const PresidentialPardonForm &obj);

#endif
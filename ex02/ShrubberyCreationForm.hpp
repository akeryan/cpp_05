/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:01:40 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/30 15:19:34 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRY_CREATION_FORM_HPP
#define SHRUBBERRY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm();
		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		void beSigned(const Bureaucrat &bt);
	private:
};

#endif
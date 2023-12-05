/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:06:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 17:07:34 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << GREEN "Cat constructed\n" OFF;
	this->type = "cat";
}

Cat::Cat(const Cat& src)
{
	*this = src;
	std::cout << GREEN "Cat copy-constructed\n" OFF;
}

Cat::~Cat(void)
{
	std::cout << RED "Cat destructed\n" OFF;
}

void Cat::MakeSound(void) const
{
	std::cout << "Cat goes meow\n";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:50:39 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/15 12:50:46 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C()
{
	std::cout << GREEN "C created" OFF << std::endl;
}

C::~C() 
{
	std::cout << RED "C destroyed" OFF << std::endl;	
}
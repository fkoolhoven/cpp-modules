/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:57:48 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/26 15:39:40 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

# include <iostream>
# include <string>
# include <cstdlib>

template <typename T>
void swap(T& a, T& b)
{
	std::cout << "Swapping...\n";
	
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b)
{
	return (a < b ? a : b);
}

template <typename T>
T max(T a, T b)
{
	return (a > b ? a : b);
}

#endif
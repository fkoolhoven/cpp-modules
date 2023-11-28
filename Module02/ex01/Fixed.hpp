/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:52:03 by felicia           #+#    #+#             */
/*   Updated: 2023/11/28 21:52:09 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

#define RED			"\033[31m"
#define GREEN 		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define OFF			"\033[0m"

class Fixed
{
	private:
		int					fixed_point_number;
		static const int	fractional_bits = 8;
		
	public:
		Fixed();
		Fixed(const int int_number);
		Fixed(const float float_number);
		Fixed(const Fixed& original);
		Fixed& operator=(const Fixed& original);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
};

std::ostream& operator<<(std::ostream &o, Fixed const &instance);
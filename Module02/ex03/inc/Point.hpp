/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:22:50 by felicia           #+#    #+#             */
/*   Updated: 2023/11/29 15:13:01 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <cmath>

# include "Fixed.hpp"

# define RED	"\033[31m"
# define GREEN 	"\033[32m"
# define YELLOW "\033[33m"
# define OFF	"\033[0m"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
		
	public:	
		Point();
		Point(const float number1, const float number2);
		Point(const Point& original);
		Point& operator=(const Point& original);
		~Point();

		const Fixed&	getX() const;
		const Fixed& 	getY() const;
		void			setX(const Fixed& original);
		void			setY(const Fixed& original);
};

#endif
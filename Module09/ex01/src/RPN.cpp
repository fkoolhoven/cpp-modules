/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:03:14 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/19 13:16:00 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	std::cout << GREEN "RPN created\n" OFF;
}

RPN::RPN(const RPN& src)
{
	*this = src;
}

RPN& RPN::operator=(const RPN& src)
{
	this->stack = src.stack;
	return (*this);
}

RPN::~RPN(void) 
{ 
	std::cout << RED "RPN destroyed\n" OFF;
}

void RPN::CalculateRPN(std::string input)
{
	bool error = false;
	std::istringstream input_stream(input);
	std::string line;

	while (!error && std::getline(input_stream, line, ' '))
	{
		try
		{
			stack.push(std::stof(line));
		}
		catch (const std::exception& exception)
		{
			if (line.length() != 1 || stack.size() < 2)
				error = true;
			else
			{
				float second = stack.top();
				stack.pop();
				float first = stack.top();
				stack.pop();
				
				switch (line[0])
				{
					case '+':
						stack.push(first + second);
						break;
					case '-':
						stack.push(first - second);
						break;
					case '*':
						stack.push(first * second);
						break;
					case '/':
						if (second == 0)
							error = true;
						else
						{
							stack.push(first / second);
							break;
						}
					default:
						error = true;
				}
			}
		}
	}
	
	if (error || stack.size() != 1)
		std::cerr << "Error! Invalid input\n";
	else
		std::cout << "Result: " << stack.top() << std::endl;
}

std::stack<float>& RPN::getStack(void)
{
	return (this->stack);
}
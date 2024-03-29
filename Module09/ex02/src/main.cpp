/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:50:15 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/04 14:35:33 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int UseUserInput(int argc, char **argv)
{
	std::vector<int> vector;
	std::deque<int> deque;
	int elements;
	int number;

	auto start = std::chrono::high_resolution_clock::now();
	for (elements = 1; elements < argc; elements++)
	{
		try
		{
			number = std::stoi(argv[elements]);
			if (number < 1)
				throw std::invalid_argument("not a positive number");
			deque.push_back(number);
			vector.push_back(number);
		}
		catch (std::invalid_argument& exception)
		{
			std::cerr << "Invalid input: " << exception.what() << ": " << std::string(argv[elements]) << std::endl;
			return (EXIT_FAILURE);
		}
		catch (std::out_of_range& exception)
		{
			std::cerr << "Out of range: " << exception.what() << ": " << std::string(argv[elements]) << std::endl;
			return (EXIT_FAILURE);
		}
	}
	auto end = std::chrono::high_resolution_clock::now();

	PmergeMe sorter;
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "\nTime to process data: " << duration << " microseconds\n";
	std::cout << "Before sorting: " << vector << std::endl;

	std::cout << YELLOW BOLD "\nSorting vector...\n" OFF;
	sorter.SortVector(vector);

	std::cout << YELLOW BOLD "\nSorting deque...\n" OFF;
	sorter.SortDeque(deque);
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}

void ExecuteCustomTests(void)
{
	PmergeMe sorter;
	
	std::cout << YELLOW BOLD "\nTesting with 1 element\n" OFF;
	{
		
		std::vector<int> vector = {1};
		std::deque<int> deque = {1};
		
		std::cout << BLUE "Before sorting: " OFF << vector << std::endl;
		std::cout << BLUE "\nSorting vector...\n" OFF;
		sorter.SortVector(vector);

		std::cout << BLUE "\nSorting deque...\n" OFF;
		sorter.SortDeque(deque);
	}

	std::cout << YELLOW BOLD "\nTesting already sorted vector\n" OFF;
	{
		std::vector<int> vector = {1, 2, 3, 4, 5};
		std::deque<int> deque = {1, 2, 3, 4, 5};
		
		std::cout << BLUE "Before sorting: " OFF << vector << std::endl;
		std::cout << BLUE "\nSorting vector...\n" OFF;
		sorter.SortVector(vector);

		std::cout << BLUE "\nSorting deque...\n" OFF;
		sorter.SortDeque(deque);
	}

	std::cout << YELLOW BOLD "\nTesting worst case\n" OFF;
	{
		std::vector<int> vector = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		std::deque<int> deque = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		
		std::cout << BLUE "Before sorting: " OFF << vector << std::endl;
		std::cout << BLUE "\nSorting vector...\n" OFF;
		sorter.SortVector(vector);

		std::cout << BLUE "\nSorting deque...\n" OFF;
		sorter.SortDeque(deque);
	}

	std::cout << YELLOW BOLD "\nTesting with 100 elements\n" OFF;
	{
		std::vector<int> vector;
		std::deque<int> deque;
		
		for (int i = 0; i < 100; i++)
		{
			int number = rand() % 1000;
			vector.push_back(number);
			deque.push_back(number);
		}
		
		std::cout << BLUE "Before sorting: " OFF << vector << std::endl;
		std::cout << BLUE "\nSorting vector...\n" OFF;
		sorter.SortVector(vector);

		std::cout << BLUE "\nSorting deque...\n" OFF;
		sorter.SortDeque(deque);
	}

	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		ExecuteCustomTests();
		return (EXIT_SUCCESS);
	}
	else
	{
		return (UseUserInput(argc, argv));
	}
}
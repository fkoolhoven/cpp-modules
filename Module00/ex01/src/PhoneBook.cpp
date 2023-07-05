/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:44:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/07/05 16:57:13 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << BOLD GREEN"Constructed phonebook!\n" << OFF;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << BOLD RED"Destructed phonebook!\n" << OFF;
}

void	print_contact_info(std::string contact_info)
{
	int	strlen;

	strlen = contact_info.length();
	if (strlen > 10)
		std::cout << std::setw(9) << std::right << contact_info.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << std::right << contact_info << '|';
}

void	PhoneBook::display_specific_contact(int contact_id)
{
	std::cout << std::endl;
	std::cout << "INDEX: " << contacts[contact_id].get_Index() << std::endl;
	std::cout << "FIRST NAME: " << contacts[contact_id].get_FirstName() << std::endl;
	std::cout << "LAST NAME: " << contacts[contact_id].get_LastName() << std::endl;
	std::cout << "NICKNAME: " << contacts[contact_id].get_Nickname() << std::endl;
	std::cout << "PHONE NUMBER: " << contacts[contact_id].get_PhoneNumber() << std::endl;
	std::cout << "DARKEST SECRET: " << contacts[contact_id].get_DarkestSecret() << std::endl;
	std::cout << std::endl; 
}

void	PhoneBook::display_all_contacts(void)
{
	int i;

	std::cout << "\nID        |FIRST NAME| LAST NAME|  NICKNAME|\n";
	std::cout << std::string(44, '-') << std::endl;
	for (i = 0; i < 8 && contacts[i].get_Index() >= 0; i++)
	{
		std::cout << std::setw(10) << std::left << contacts[i].get_Index() << '|';
		print_contact_info(contacts[i].get_FirstName());
		print_contact_info(contacts[i].get_LastName()); 
		print_contact_info(contacts[i].get_Nickname());
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::search_contact(void)
{
	int contact_id;
	
	if (contacts[0].get_Index() == -1)
	{
		std::cout << YELLOW"Add a contact before searching.\n" << OFF;
		return ;
	}
	display_all_contacts();
	contact_id = -1;
	std::cout << YELLOW"Choose a valid contact ID from the ID column: " << OFF;
	while (!(std::cin >> contact_id) || contact_id < 0 || contact_id > 7 || contacts[contact_id].get_Index() == -1)
	{
        std::cin.clear();
       	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << YELLOW"Choose a valid contact ID from the ID column: " << OFF;
    }
	display_specific_contact(contact_id);
}

void	PhoneBook::add_contact_to_phonebook(int index)
{
	contacts[index].set_contact_info(index);
}

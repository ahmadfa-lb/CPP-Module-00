/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:08:11 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/15 17:19:01 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void	showOptions()
{
	std::cout 	<< "\033[33m$⫸\033[0m⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰" << std::endl
				<< "\033[33m$⫸\033[0mPlease enter one of the following OPTIONS:" << std::endl
				<< "\033[33m$⫸\033[0mTo add➕ a contact enter:\033[32mADD\t\033[0m" << std::endl
				<< "\033[33m$⫸\033[0mTo search🔎 for a contact in the PhoneBook enter:\033[32mSEARCH\t\033[0m" << std::endl
				<< "\033[33m$⫸\033[0mTo exit My Awesome PhoneBook📒 enter:\033[32mEXIT\t\033[0m" << std::endl
				<< "\033[33m$⫸\033[0m\033[0m⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰" << std::endl;
}

int main()
{
	PhoneBook pBook;
	std::string userInput;
	while (1)
	{
		userInput.clear();
		std::cout << "\033[33m$⫸\033[0m";
		std::getline(std::cin, userInput);
		//std::cout << std::endl;
		
		if (std::cin.eof() == true) //to avoid the infinite loop if ctrl d is pressed
		{
			std::cout << "⋙⋙⋙\tctrl ^D detected ⋙⋙⋙\texiting... .. .!!!" << std::endl;
			exit(0);
		}
		else if (userInput.compare("ADD") == 0)
			pBook.addContact();
		else if (userInput.compare("SEARCH") == 0)
		{
			pBook.searchContacts();
		userInput.clear();
	
		}
		else if (userInput == "EXIT")
			break ;	
		// else
		// {
		// 	std::cout << "\033[33m$⫸\033[0m✕❌✕ \033[31mWRONG INPUT\033[0m ✕❌✕" << std::endl;	
		// 	
		// }
		showOptions();
		userInput.clear();
		
	}
	std::cout << "\033[35mThankyou for using My Awesome PhoneBook® ✨!!" << std::endl;
	return (0);
}
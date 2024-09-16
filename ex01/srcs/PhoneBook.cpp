/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:32:37 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/16 04:09:43 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"


PhoneBook::PhoneBook(void) : currentIndex(0), contactCount(0) {}

PhoneBook::~PhoneBook(void) {}

bool isAllAlpha(const std::string str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isalpha(str[i]))
            return false;
    }
    return true;
}

bool isAllNumeric(const std::string str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    do
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Error: First name cannot be empty and should contains only charaters!" << std::endl;
        else
            newContact.setFirstName(input);
    } while (input.empty() || !isAllAlpha(input));

    do
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Error: Last name cannot be empty and should contains only charaters!" << std::endl;
        else
            newContact.setLastName(input);
    } while (input.empty() || !isAllAlpha(input));

    do
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Error: Nickname cannot be empty and should contains only charaters!" << std::endl;
        else
            newContact.setNickName(input);
    } while (input.empty() || !isAllAlpha(input));

    do
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Error: Phone number cannot be empty and should contains only digits!" << std::endl;
        else
            newContact.setPhoneNumber(input);
    } while (input.empty() || !isAllNumeric(input));

    do
    {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Error: Darkest secret cannot be empty!!" << std::endl;
        else
            newContact.setDarkestSecret(input);
    } while (input.empty());

    if (contactCount < 8)
    {
        contacts[contactCount] = newContact;
        contactCount++;
    }
    else
        contacts[currentIndex] = newContact;

    currentIndex = (currentIndex + 1) % 8;
    std::cout << std::endl;
    std::cout << "\033[32mContact added successfully!\033[0m" << std::endl;
    std::cout << std::endl;

}


std::string PhoneBook::truncateString(const std::string& str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::searchContacts() const
{
    if (contactCount == 0)
    {
        std::cout << "PhoneBook is empty. No contacts to display." << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(43, '-') << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getNickName()) << std::endl;
    }

    int index;
    std::cout << "Enter the index of the contact to view (1-" << contactCount << "): ";
    std::cin >> index;

    if (std::cin.fail() || index < 1 || index > contactCount)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid index!" << std::endl;
    }
    else
        contacts[index - 1].displayContact();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

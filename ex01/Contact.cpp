/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:07:44 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/16 05:28:16 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

bool Contact::isAllAlpha(const std::string& str) const
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isalpha(str[i]))
            return false;
    }
    return true;
}

bool Contact::isAllNumeric(const std::string& str) const
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

// Setter methods
void Contact::setFirstName(const std::string& firstName)
{
    if (isAllAlpha(firstName))
        fName = firstName;
    else
        std::cerr << "Error: First name contains invalid characters!" << std::endl;
}

void Contact::setLastName(const std::string& lastName)
{
    if (isAllAlpha(lastName))
        lName = lastName;
    else
        std::cerr << "Error: Last name contains invalid characters!" << std::endl;
}

void Contact::setNickName(const std::string& nickName)
{
    if (isAllAlpha(nickName))
        this->nickName = nickName;
    else
        std::cerr << "Error: Nickname contains invalid characters!" << std::endl;
}

void Contact::setPhoneNumber(const std::string& phone)
{
    if (isAllNumeric(phone))
        phoneNumber = phone;
    else
        std::cerr << "Error: Phone number contains invalid characters!" << std::endl;
}

void Contact::setDarkestSecret(const std::string& secret)
{
    darkestSecret = secret;
}

// Getter methods
std::string Contact::getFirstName(void) const
{
    return fName;
}

std::string Contact::getLastName(void) const
{
    return lName;
}

std::string Contact::getNickName(void) const
{
    return nickName;
}

std::string Contact::getPhoneNumber(void) const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
    return darkestSecret;
}

// Additional methods
bool Contact::isContactComplete(void) const
{
    return (!fName.empty() && !lName.empty() && !nickName.empty() && 
            !phoneNumber.empty() && !darkestSecret.empty());
}

void Contact::displayContact(void) const
{
    std::cout << std::endl;
    std::cout << "First Name: " << fName << std::endl;
    std::cout << "Last Name: " << lName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
    std::cout << std::endl;
}

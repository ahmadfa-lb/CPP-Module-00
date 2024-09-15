/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:32:28 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/15 16:27:44 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <cctype>

class PhoneBook
{
private:
    Contact contacts[8];
    int currentIndex;
    int contactCount;

public:
    PhoneBook(void);
    ~PhoneBook(void);

    void addContact(void);
    void searchContacts() const;
	std::string truncateString(const std::string& str) const;
};

#endif
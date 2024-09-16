/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:34:08 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/15 16:31:21 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTAT_H

#include <iostream>
#include <string>

class Contact
{
private:
	std::string fName;
	std::string lName;
	std::string nickName;
	std::string	phoneNumber;
	std::string darkestSecret;

	// Private helper functions
    bool isAllAlpha(const std::string& str) const;
    bool isAllNumeric(const std::string& str) const;
	
public:
	Contact(void);
	~Contact(void);

	// Setter methods
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setNickName(const std::string& nickName);
    void setPhoneNumber(const std::string& phone);
    void setDarkestSecret(const std::string& secret);

    // Getter methods
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickName(void) const;
    std::string getPhoneNumber(void) const;
    std::string getDarkestSecret(void) const;

	// Additional methods
    bool isContactComplete(void) const;
    void displayContact(void) const;
};

#endif


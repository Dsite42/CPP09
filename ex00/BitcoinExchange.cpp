/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:42:20 by cgodecke          #+#    #+#             */
/*   Updated: 2024/01/19 12:57:50 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


// Constructors

// Constructor which is reading 'data.csv' and filling the map. If an error accours during opening the file thow exeption 'Could not open file' and if the key value dont has the format Year-Month-Day throw exeption 'Invalid date format'. Shall compliant with c++98.
BitcoinExchange::BitcoinExchange()
{
	_readDatabase();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	if (this != &other)
		*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
		_quotes = other._quotes;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

// Getters
std::map<std::string, double> const &BitcoinExchange::getQuotes() const
{
	return (_quotes);
}

void BitcoinExchange::_readDatabase()
{
       std::ifstream file("data.csv");
        if (!file.is_open())
            throw CouldNotOpenFile();

        std::string line;

        // Check if first line is date,exchange_rate
        std::getline(file, line);
        if (line != "date,exchange_rate")
            throw InvalidColumnFormat();

        while (std::getline(file, line)) {
            std::string date, price;
            std::istringstream ss(line);
            std::getline(ss, date, ',');
            std::getline(ss, price, ',');

            // Validate date format. 	// der check muss nur beim input file gemacht werden nicht bei der database
            if (date.size() != 10 || date[4] != '-' || date[7] != '-')
                throw InvalidDateFormat();

            // Parse price using istringstream
            double priceValue;
            std::istringstream priceStream(price);
			// der check muss nur beim input file gemacht werden nicht bei der database
            if (!(priceStream >> priceValue) || priceValue < 0 || priceValue > 10000000)
			{
				std::cout << "priceValue: " << priceValue << std::endl;
				throw InvalidPriceFormat();
			}

            // Store the valid data
            _quotes[date] = priceValue;
        }

        file.close();
}
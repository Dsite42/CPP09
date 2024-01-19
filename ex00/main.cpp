/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:24:49 by cgodecke          #+#    #+#             */
/*   Updated: 2024/01/19 11:34:14 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main()
{
	try
	{
		BitcoinExchange exchange;
		// print all quotes
		std::map<std::string, double> const &quotes = exchange.getQuotes();
		for (std::map<std::string, double>::const_iterator it = quotes.begin(); it != quotes.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	return (0);
}

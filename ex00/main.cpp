/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:24:49 by cgodecke          #+#    #+#             */
/*   Updated: 2024/01/19 13:17:00 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin [file]" << std::endl;
		return (1);
	}
	else
	



	try
	{
		BitcoinExchange exchange;
		// print all quotes
		std::map<std::string, double> const &quotes = exchange.getQuotes();
		for (std::map<std::string, double>::const_iterator it = quotes.begin(); it != quotes.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		// execute the file
		exchange.execute(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	


	return (0);
}

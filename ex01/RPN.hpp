/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:08:27 by cgodecke          #+#    #+#             */
/*   Updated: 2024/01/20 17:05:55 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <exception>

class RPN
{
	private:
		std::stack<int> _stack;
		void _executeStack(int (RPN::*f)(int, int));
		int _plus(int a, int b);
		int _minus(int a, int b);
		int _multiply(int a, int b);
		int _divide(int a, int b);

	public:
		//Constructors
		RPN();
		RPN(const std::string  &inputStr);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		//Getters
		int getResult() const;


		//Exceptions
		class invalidArgument : public std::runtime_error
		{
			public:
				explicit invalidArgument(const std::string& msg);
		};

		class emptyStack : public std::runtime_error
		{
			public:
				explicit emptyStack(const std::string& msg);
		};

		class divisionByZero : public std::runtime_error
		{
			public:
				explicit divisionByZero(const std::string& msg);
		};	
};

#endif

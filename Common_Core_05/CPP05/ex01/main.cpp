/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbieu <abarbieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:05:12 by abarbieu          #+#    #+#             */
/*   Updated: 2024/01/03 10:10:02 by abarbieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(){
	try{
		std::cout << "John" << std::endl;
		Bureaucrat	John("john", 50);
		Form	form1("form1", 60, 50);
		std::cout << John;
		std::cout << form1;
		John.signForm(form1);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
//------------------------------------------//
	try{
		std::cout << "Jane" << std::endl;
		Bureaucrat	Jane("jane", 50);
		Form	form2("form2", 151, 150);
		std::cout << Jane;
		std::cout << form2;
		Jane.signForm(form2);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
//------------------------------------------//
	try{
		std::cout << "Johnny" << std::endl;
		Bureaucrat	Johnny("johnny", 50);
		Form	form3("form3", 1, 0);
		std::cout << Johnny;
		std::cout << form3;
		Johnny.signForm(form3);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
//------------------------------------------//
	try{
		std::cout << "George" << std::endl;
		Bureaucrat	George("george", 50);
		Form	form4("form4", 40, 20);
		std::cout << George;
		std::cout << form4;
		George.signForm(form4);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

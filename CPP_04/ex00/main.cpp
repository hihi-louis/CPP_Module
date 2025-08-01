/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:32:00 by tripham           #+#    #+#             */
/*   Updated: 2025/07/21 18:56:55 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

template <typename T>
static void clean(T* ptr)
{
	delete ptr;
}

int main()
{
	Animal omenal = Animal();
	
	Animal *omenal1 = new Cat();
	Dog bulldog;
	Dog cogi(bulldog);
	WrongAnimal *ahaha = new WrongCat();
	throw std::runtime_error("test");
	//try catch for new otherwise it's gonna be segfault
	std::cout << cogi.getType() << "" << std::endl;
	std::cout << ahaha->getType() << "" << std::endl;
	
	omenal1->makeSound();
	bulldog.makeSound();
	cogi.makeSound();

	ahaha->makeSound();
	clean(omenal1);
	clean(ahaha);
}


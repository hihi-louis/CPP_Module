/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:32:00 by tripham           #+#    #+#             */
/*   Updated: 2025/07/08 17:02:22 by tripham          ###   ########.fr       */
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
	if (ptr)
		delete ptr;
}

int main()
{
	const int size = 10;
	Animal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;

	for (int i = 0; i < size; i++)
		animals[i]->makeSound();

	std::cout << "\n=== Deep Copy Test ===\n" << std::endl;

	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "I need to bite someone");
	originalDog.getBrain()->setIdea(1, "I am a supper dog");

	Dog copiedDog(originalDog);

	std::cout << "Original Dog Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "CopiedDog Idea :" << copiedDog.getBrain()->getIdea(0) << std::endl;

	copiedDog.getBrain()->setIdea(0, "I want to sleep");

	std::cout << "After modifying copy:\n";
    std::cout << "Original Dog Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0  : " << copiedDog.getBrain()->getIdea(0) << std::endl;

	for (int i = 0; i < size; i++)
		clean(animals[i]);
	return 0;
}
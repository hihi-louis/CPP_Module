/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:32:00 by tripham           #+#    #+#             */
/*   Updated: 2025/09/01 16:30:09 by tripham          ###   ########.fr       */
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
    Animal* animal = nullptr;
    Animal* dog = nullptr;
    Animal* cat = nullptr;
    WrongAnimal* wrong = nullptr;

    try {
        std::cout << "---- Correct polymorphism ----" << std::endl;
        animal = new Animal();
        dog = new Dog();
        cat = new Cat();

        std::cout << dog->getType() << std::endl;
        std::cout << cat->getType() << std::endl;
        dog->makeSound(); 
        cat->makeSound();
        animal->makeSound();

        std::cout << "\n---- Wrong polymorphism ----" << std::endl;
        wrong = new WrongCat();
        std::cout << wrong->getType() << std::endl;
        wrong->makeSound();

		//Test Exception
        throw std::runtime_error("Manual test exception in main()");

        //If dont throw it is gonna normally deleteded
        // clean(animal);
        // clean(dog);
        // clean(cat);
        // clean(wrong);
    }
    catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;

        // Clean up when It throws exceptions
        // clean(animal);
        // clean(dog);
        // clean(cat);
        // clean(wrong);
    }
	clean(animal);
    clean(dog);
    clean(cat);
    clean(wrong);

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:18:01 by makacem           #+#    #+#             */
/*   Updated: 2023/06/11 15:38:04 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
    std::srand(std::time(nullptr));

    int randomNumber = std::rand() % 3 + 1;
    if (randomNumber == 1)
        return (new A);
    else if (randomNumber == 2)
        return (new B);
    else
        return (new C);
    
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A\n";
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B\n";
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C\n";
}

void    identify(Base &p)
{
    try
    {
        A &temp = dynamic_cast<A &>(p);
        (void)temp;
        std::cout << "A\n";
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        B &temp = dynamic_cast<B &>(p);
        (void)temp;
        std::cout << "B\n";
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        C &temp = dynamic_cast<C &>(p);
        (void)temp;
        std::cout << "A\n";
    }
    catch(const std::exception& e)
    {
    }
    
}

Base::~Base()
{
    std::cout << "Virtual destructor called\n";
}

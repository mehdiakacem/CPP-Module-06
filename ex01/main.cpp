/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:57:03 by makacem           #+#    #+#             */
/*   Updated: 2023/06/12 18:30:43 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *mehdi = new Data;
    uintptr_t temp;
    Data *second;

    mehdi->name = "mehdi";
    mehdi->nbr = 20;

    temp = Serializer::serialize(mehdi);

    second = Serializer::deserialize(temp);

    std::cout << second->name << std::endl;
    std::cout << second->nbr << std::endl;

    delete mehdi;
}
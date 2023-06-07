/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:26:56 by makacem           #+#    #+#             */
/*   Updated: 2023/06/07 18:59:24 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    ScalarConverter::convert(std::string param)
{
    try
    {
        int num = std::stoi(param);
        std::cout << "int: " << num << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid parameter.\n";
        return ;
    }
    try
    {
        float num = std::stof(param);
        std::cout << "float: " << num << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid parameter.\n";
    }
}

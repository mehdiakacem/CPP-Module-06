/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:26:56 by makacem           #+#    #+#             */
/*   Updated: 2023/06/11 08:51:34 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    ScalarConverter::convert(std::string param)
{    
    std::size_t found;

    //char
    if (param.length() == 3 && param.front() == 39 && param.back() == 39)
    {
        char c = param[1];

        if (!isprint(c) || c == ' ')
            std::cout << "char: Non displayble\n";
        else
            std::cout << "char: " << static_cast<char>(c) << std::endl;
        std::cout << "int : " << static_cast<int>(c) << std::endl;
        std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }
    //float

    if (param == "-inff" || param == "+inff" || param == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        if (param == "-inff")
        {
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
        else if(param == "+inff")
        {
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
        }
        else if(param == "nanf")
        {
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
        }
        return;
    }
    if (param == "-inf" || param == "+inf" || param == "nan")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        if (param == "-inf")
        {
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
        else if(param == "+inf")
        {
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
        }
        else if(param == "nan")
        {
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
        }
        return;
    }
    found = param.find('f');
    if (param.back() == 'f' && found != std::string::npos)
    {
        try
        {
            param.erase(found, found);
            unsigned long i = 0;
            if (param.front() == '-')
                i = 1;
            found = param.find('.');
            while (i < found)
            {
                if (!isdigit(param[i]))
                    throw std::invalid_argument("Invalid argument.");
                i++;
            }
            i = found + 1;
            while (i < param.length())
            {
                if (!isdigit(param[i]))
                    throw std::invalid_argument("Invalid argument.");
                i++;
            }
            float num = std::atof(param.c_str());
            if (!isprint(num))
                std::cout << "char: Non displayble\n";
            else 
                std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(num) << std::endl;
            size_t found = param.find('.');
            if (found != std::string::npos && param.back() == '0')
            {
                std::cout << "float: "<< static_cast<float>(num) << ".0f" << std::endl;
                std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
            }
            else
            {
                std::cout << "float: "<< static_cast<float>(num) << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(num) << std::endl;
            }
            return;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Invalid parameter.\n";
            return ;
        }
    }
    //double
    found = param.find('.');
    if (found != std::string::npos)
    {
        try
        {
            unsigned long i = 0;
            if (param.front() == '-')
                i = 1;
            while (i < found)
            {
                if (!isdigit(param[i]))
                    throw std::invalid_argument("Invalid argument.");
                i++;
            }
            i = found + 1;
            while (i < param.length())
            {
                if (!isdigit(param[i]))
                    throw std::invalid_argument("Invalid argument.");
                i++;
            }
            double num = std::stod(param);
            if (!isprint(num) || num == ' ')
                std::cout << "char: Non displayble\n";
            else
                std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(num) << std::endl;
            if (param.back() == '0')
            {
                std::cout << "float: "<< static_cast<float>(num) << ".0f" << std::endl;
                std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
            }
            else
            {
                std::cout << "float: "<< static_cast<float>(num) << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(num) << std::endl;
            }
            return;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Invalid parameter.\n";
            return ;
        }
    }
    //int
    try
    {
        unsigned long i = 0;
        if (param.front() == '-')
            i = 1;
        while (i < param.length())
        {
            if (!isdigit(param[i]))
                throw std::invalid_argument("Invalid argument.");
            i++;
        }
        int num;
        if (param.length() == 1 && !isdigit(param.front()))
            num = param.front();
        else
            num = std::stoi(param);
        if (!isprint(num) || num == ' ')
            std::cout << "char: Non displayble\n";
        else 
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        std::cout << "int: " << static_cast<float>(num) << std::endl;
        std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid parameter.\n";
        return ;
    }
}

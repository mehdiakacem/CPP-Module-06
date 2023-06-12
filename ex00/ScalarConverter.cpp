/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:26:56 by makacem           #+#    #+#             */
/*   Updated: 2023/06/12 18:28:46 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    ScalarConverter::convert(std::string param)
{    
    std::size_t found;

    if (param == "-inff" || param == "+inff" || param == "nanf")
    {
        std::cout << "char: Impossible\n";
        std::cout << "int: Impossible\n";
        if (param == "-inff")
        {
            float num = std::numeric_limits<float>::infinity() * -1;
            std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(num) << std::endl;
        }
        else if(param == "+inff")
        {
            float num = std::numeric_limits<float>::infinity();
            std::cout << "float: +" << static_cast<float>(num) << "f" << std::endl;
            std::cout << "double: +" << static_cast<double>(num) << std::endl;
        }
        else if(param == "nanf")
        {
            float num = std::numeric_limits<float>::quiet_NaN();
            std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(num) << std::endl;
        }
        return;
    }
    if (param == "-inf" || param == "+inf" || param == "nan")
    {
        std::cout << "char: Impossible\n";
        std::cout << "int: Impossible\n";
        if (param == "-inf")
        {
            double num = std::numeric_limits<double>::infinity() * -1;
            std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(num) << std::endl;
        }
        else if(param == "+inf")
        {
            double num = std::numeric_limits<double>::infinity();
            std::cout << "float: +" << static_cast<float>(num) << "f" << std::endl;
            std::cout << "double: +" << static_cast<double>(num) << std::endl;
        }
        else if(param == "nan")
        {
            double num = std::numeric_limits<double>::quiet_NaN();
            std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(num) << std::endl;
        }
        return;
    }
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
            float num = std::stof(param);
            if (num > 127 || num < 0)
                std::cout << "char: Impossible\n";
            else if (!isprint(num))
                std::cout << "char: Non displayble\n";
            else 
                std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
            if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
                std::cout << "int: Impossible\n";
            else
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
            std::cout << "char: Impossible.\n";
            std::cout << "int: Impossible.\n";
            std::cout << "float: Impossible.\n";
            std::cout << "double: Impossible.\n";
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
            if (num > 127 || num < 0)
                std::cout << "char: Impossible\n";
            else if (!isprint(num) || num == ' ')
                std::cout << "char: Non displayble\n";
            else
                std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
            if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
                std::cout << "int: Impossible\n";
            else
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
            std::cout << "char: Impossible.\n";
            std::cout << "int: Impossible.\n";
            std::cout << "float: Impossible.\n";
            std::cout << "double: Impossible.\n";
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
        if (num > 127 || num < 0)
            std::cout << "char: Impossible\n";
        else if (!isprint(num) || num == ' ')
            std::cout << "char: Non displayble\n";
        else 
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(num) << std::endl;
        std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << "char: Impossible.\n";
        std::cout << "int: Impossible.\n";
        std::cout << "float: Impossible.\n";
        std::cout << "double: Impossible.\n";
        return ;
    }
    


}

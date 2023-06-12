/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:11:01 by makacem           #+#    #+#             */
/*   Updated: 2023/06/12 18:27:49 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include<limits>

int main(int argc, char **argv)
{
    (void)argc;
        
    if(argv[1])
        ScalarConverter::convert(argv[1]);
    
    return 0;
}
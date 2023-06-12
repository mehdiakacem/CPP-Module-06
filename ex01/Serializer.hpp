/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:32:47 by makacem           #+#    #+#             */
/*   Updated: 2023/06/12 18:29:49 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP

#include <iostream>

struct Data
{
    /* data */
    int nbr;
    std::string name;
};


class Serializer
{
    private:
        Serializer();
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};




#endif
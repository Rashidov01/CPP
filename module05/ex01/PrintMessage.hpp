/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintMessage.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:15:20 by arashido          #+#    #+#             */
/*   Updated: 2024/03/03 19:24:38 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_MESSAGE_HPP
#define PRINT_MESSAGE_HPP

#include <iostream>
#include <string>

namespace Color {
    const std::string Reset = "\033[90m";
    const std::string Red = "\033[31m";
    const std::string Green = "\033[32m";
    const std::string Yellow = "\033[33m";
    const std::string Blue = "\033[34m";
    const std::string Orange = "\033[93m";
}

template <typename T>
inline void printMessage(const T& message, const std::string& colorCode = Color::Reset) {
    std::cout << colorCode << message << Color::Reset << std::endl;
}

#endif
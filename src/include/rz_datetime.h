/**
 * @file rz_datetime.h
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief CXX20 datetime lib
 * @version 2.0.0
 * @date 2023-03-25
 *
 * @copyright Copyright (c) 2024 ZHENG Robert
 *
 */

#pragma once

#include <iostream>
#include <chrono>

/**
 * @brief DateTime class
 *
 */
class DateTime
{
public:
  DateTime();

  std::string getUtcDateTime();
  std::string getLocalTime();
  std::string currentDateTime(std::string format);
};
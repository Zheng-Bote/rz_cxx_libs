/**
 * @file rz_datetime.h
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief CXX20 datetime lib
 * @version 2.0.0
 * @date 2023-03-25
 *
 * @copyright Copyright (c) 2023 ZHENG Robert
 *
 */

#pragma once

#include <iostream>
#include <chrono>
#include <clocale>

/**
 * @brief DateTime class
 *
 */
class DateTime
{
public:
  DateTime();

  std::string getUtcDateTimeSys();
  std::string getUtcDateTimeHuman();

  std::string getLocalTimeSys();
  std::string getLocalTimeHuman();

  std::string getCurrentZoneOffset();

  void showAllTimezones();
  void findTimezone(const std::string &endName = "Paris");
};
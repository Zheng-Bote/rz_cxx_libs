/**
 * @file rz_datetime.h
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief CXX20 datetime lib
 * @version 2.1.0
 * @date 2023-03-25
 *
 * @copyright Copyright (c) 2023 ZHENG Robert
 *
 */

#pragma once

#include <iostream>
#include <chrono>
#include <clocale>
#include <string>

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
  std::string getFormatedUtcDateTimeHuman(const std::string &format = "YYYY-MM-DD_HH-MM");

  std::string getLocalTimeSys();
  std::string getLocalTimeHuman();
  std::string DateTime::getFormatedLocalDateTimeHuman(const std::string &format = "YYYY-MM-DD_HH-MM");

  std::string getCurrentZoneOffset();

  void showAllTimezones();
  std::string findTimezoneTime(const std::string &endName = "Paris");
};
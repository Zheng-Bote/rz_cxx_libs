/**
 * @file rz_datetime.cpp
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief CXX20 datetime lib
 * @version 2.0.0
 * @date 2023-03-25
 *
 * @copyright Copyright (c) 2024 ZHENG Robert
 *
 */

#include "rz_datetime.h"

/**
 * @brief Construct a new Date Time:: Date Time object
 *
 */
DateTime::DateTime()
{
}

// TODO: define content and ret code
/**
 * @brief DateTime::getUtcDateTime
 *
 * @return std::string
 */
std::string DateTime::getUtcDateTime()
{

  using std::chrono::floor;

  std::cout << "UTC  time" << '\n'; // (1)
  auto utcTime = std::chrono::system_clock::now();
  std::cout << "  " << utcTime << '\n';
  std::cout << "  " << floor<std::chrono::seconds>(utcTime) << '\n';

  return std::string();
}

// TODO: define content and ret code
/**
 * @brief DateTime::getLocalTime
 *
 * @return std::string
 */
std::string DateTime::getLocalTime()
{
  using std::chrono::floor;
  auto utcTime = std::chrono::system_clock::now();
  std::cout << "Local time" << '\n'; // (2)
  auto localTime = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);

  std::cout << "  " << localTime << '\n';
  std::cout << "  " << floor<std::chrono::seconds>(localTime.get_local_time())
            << '\n';

  auto offset = localTime.get_info().offset; // (3)
  std::cout << "  UTC offset: " << offset << '\n';
  return std::string();
}

// TODO: clean code and upd C-style
/**
 * @brief returns the current date time
 *
 * @param format
 * human    (e.g.: 2023-03-25 15:41:32)
 * spdx     (e.g.: 2023-03-25T15:41:32CET)
 * string   (e.g.: 2023-03-25_15-41-32)
 *
 * @return const std::string
 */
std::string DateTime::currentDateTime(std::string format)
{
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
  // for more information about date/time format

  if (format.compare("human") == 0)
  {
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
  }
  else if (format.compare("spdx") == 0)
  {
    strftime(buf, sizeof(buf), "%Y-%m-%dT%X%Z", &tstruct);
  }
  else
  {
    strftime(buf, sizeof(buf), "%Y-%m-%d_%H-%M-%S", &tstruct);
  }
  return buf;
}
/**
 * @file rz_datetime.cpp
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief CXX20 datetime lib
 * @version 2.0.0
 * @date 2023-03-25
 *
 * @copyright Copyright (c) 2023 ZHENG Robert
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

/**
 * @brief DateTime::getUtcDateTime
 *
 * @return std::string (eg: 2024-10-09T12:29+0000)
 */
std::string DateTime::getUtcDateTimeSys()
{
  auto epoch = std::chrono::utc_clock::now();
  return std::format("{0:%F}T{0:%R%z}", epoch);
}

/**
 * @brief DateTime::getUtcDateTimeHuman
 *
 * @return std::string (eg: 2024-10-09 12:29:21)
 */
std::string DateTime::getUtcDateTimeHuman()
{
  using std::chrono::floor;

  auto epoch = std::chrono::utc_clock::now();
  auto humanTime = floor<std::chrono::seconds>(epoch);

  return std::format("{0:%F} {0:%T}", humanTime);
}

/**
 * @brief DateTime::getLocalTime
 *
 * @return std::string (eg: 2024-10-09T12:29+0200)
 */
std::string DateTime::getLocalTimeSys()
{
  using std::chrono::floor;

  auto utcTime = std::chrono::system_clock::now();
  auto localTime = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);
  auto local_Time = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);

  return std::format("{0:%F}T{0:%R%z}", local_Time);
}

/**
 * @brief DateTime::getLocalTimeHuman
 *
 * @return std::string (eg: 2024-10-09 12:29:21)
 */
std::string DateTime::getLocalTimeHuman()
{
  using std::chrono::floor;

  auto utcTime = std::chrono::system_clock::now();
  auto localTime = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);
  auto humanTime = floor<std::chrono::seconds>(localTime.get_local_time());

  return std::format("{0:%F} {0:%T}", humanTime);
}

/**
 * @brief DateTime::getCurrentZoneOffset
 *
 * @return std::string (eg: +0200)
 */
std::string DateTime::getCurrentZoneOffset()
{
  // auto offset = std::chrono::current_zone()->get_info(std::chrono::system_clock::now()).offset;
  // return std::format("{%Ez}", offset);

  using std::chrono::floor;

  auto utcTime = std::chrono::system_clock::now();
  auto localTime = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);
  auto local_Time = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);

  return std::format("{0:%z}", local_Time);
}

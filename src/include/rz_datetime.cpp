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

/**
 * @brief DateTime::showAllTimezones
 *
 */
void DateTime::showAllTimezones()
{
  const std::chrono::tzdb &tzdb{std::chrono::get_tzdb()};
  const std::vector<std::chrono::time_zone> &tzs{tzdb.zones};
  for (const std::chrono::time_zone &tz : tzs)
  {
    std::cout << tz.name() << '\n';
  }
}

// TODO: cleanup ret
/**
 * @brief DateTime::findTimezone
 *
 * @param endName (eg: Paris)
 */
void DateTime::findTimezone(const std::string &endName)
{
  const std::chrono::tzdb &tzdb{std::chrono::get_tzdb()};
  const std::vector<std::chrono::time_zone> &tzs{tzdb.zones};
  const auto &res{std::find_if(tzs.begin(), tzs.end(), [&endName](const std::chrono::time_zone &tz)
                               {
    std::string name{tz.name()};
    return name.ends_with(endName); })};

  if (res != tzs.end())
  {
    try
    {
      const std::string_view myLocation{res->name()};
      const std::chrono::time_point now{std::chrono::system_clock::now()};
      const std::chrono::zoned_time zt_1{myLocation, now};
      std::cout << myLocation << ": " << zt_1 << '\n';
    }
    catch (const std::runtime_error &e)
    {
      std::cout << e.what() << '\n';
    }
  }
}

/**
 * @file rz_filesystem.h
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief CXX20 filesystem library
 * @version 2.0.0
 * @date 2023-03-24
 *
 * @copyright Copyright (c) ZHENG Robert 2023
 *
 */

#pragma once

#include <filesystem>
#include <format>
#include <iostream>

/**
 * @brief The Filesystem class
 */
class Filesystem
{
public:
  Filesystem();
  ~Filesystem();

  // directories
  bool createDirectory(const std::filesystem::path &p) noexcept;
  bool createDirectories(const std::filesystem::path &p) noexcept;
  bool copyDirectories(const std::filesystem::path &src, const std::filesystem::path &dest) noexcept;
  bool removeDirectory(const std::filesystem::path &p) noexcept;
  bool removeDirectories(const std::filesystem::path &p) noexcept;
  bool isDirectory(const std::filesystem::path &p);
  bool showDirectoryTree(const std::string &p);

  void listDirectory(const std::filesystem::path &p);
  void listDirectories(const std::filesystem::path &p, unsigned tabs = 0);

  std::uintmax_t calculateDirectorySize(const std::filesystem::path &dir);

  // files
  bool copyFile(const std::filesystem::path &src, const std::filesystem::path &dest) noexcept;
  bool copyFiles(const std::filesystem::path &src, const std::filesystem::path &dest) noexcept;
  bool copyFilesRecursive(const std::filesystem::path &src,
                          const std::filesystem::path &dest) noexcept;
  bool isFile(const std::filesystem::path &p);
  std::string getFilePermission(const std::filesystem::path &file);

  // mixed
  std::string getAbsolutePath(const std::filesystem::path &p);
  std::string getRelativePath(const std::filesystem::path &basePath, const std::filesystem::path &absolutePath);

  std::uintmax_t getDiskCapacity(std::string const &fs);
  std::uintmax_t getDiskFree(std::string const &fs);
  std::uintmax_t getDiskAvailable(std::string const &fs);

  std::uintmax_t
  diskUsagePercent(const std::filesystem::space_info &si,
                   bool is_privileged = false) noexcept;
  void printDiskSpaceInfo(std::string const &dir, int width = 14);

private:
  std::error_code ec{};
  struct filePerms
  {
    std::string owner_read{"-"};
    std::string owner_write{'-'};
    std::string owner_execute{'-'};
    std::string group_read{"-"};
    std::string group_write{'-'};
    std::string group_execute{'-'};
    std::string others_read{"-"};
    std::string others_write{'-'};
    std::string others_execute{'-'};
  };
};

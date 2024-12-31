/**
 * @file rz_qt_image.h
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief Qt6 image lib
 * @version 0.3.0
 * @date 2024-10-06
 *
 * @copyright Copyright (c) 2024 ZHENG Robert
 *
 */

#pragma once

#include <QCoreApplication>
#include <QImage>

#include <iostream>

/**
 * @brief Img class
 *
 */
class Img
{
public:
  Img();
  void scaledToWidth(QString &pathToPhotoIn, QString &pathToPhotoOut, qint32 &width, , QString convertTo = "WEBP");
  bool rotateImage(conts QString &pathToSrcFile, const int &turn);
  bool convertImage(const QString &pathToSrcFile, const QString &convertTo, const int targetSize);

private:
  const QString VERSION = "0.3.0";
};
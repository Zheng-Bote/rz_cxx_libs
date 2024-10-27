/**
 * @file rz_qt_image.h
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief Qt6 image lib
 * @version 0.2.0
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

private:
  const QString VERSION = "0.1.0";
};
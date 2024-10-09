/**
 * @file rz_qt_image.cpp
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief Qt6 datetime lib
 * @version 0.1.0
 * @date 2024-10-06
 *
 * @copyright Copyright (c) 2024 ZHENG Robert
 *
 */

#include "rz_qt_image.h"

/**
 * @brief Construct a new Img:: Img object
 *
 */
Img::Img()
{
}

/**
 * @brief Img::scaledToWidth
 *
 * @param pathToPhotoIn
 * @param pathToPhotoOut
 * @param width
 * @param convertTo (eg: BMP JPG JPEG PNG WEBP)
 */
void Img::scaledToWidth(QString &pathToPhotoIn, QString &pathToPhotoOut, qint32 &width, QString convertTo)
{
  QImage imageInput(pathToPhotoIn);
  QImage imageOutput = imageInput.scaledToWidth(480, Qt::FastTransformation);

  imageOutput.save(pathToPhotoOut, convertTo);

  std::cout << "old size: " << imageInput.sizeInBytes() << std::endl;
  std::cout << "old width: " << imageInput.width() << std::endl;
  std::cout << "new size: " << imageOutput.sizeInBytes() << std::endl;
  std::cout << "new width: " << imageOutput.width() << std::endl;
}

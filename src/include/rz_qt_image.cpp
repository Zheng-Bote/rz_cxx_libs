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

// TODOS
// path / file separation
bool Img::rotateImage(conts QString &pathToSrcFile, const int &turn)
{

  QString imgIn = imgStruct.abolutePath + "/" + imgStruct.fileBasename + "." + imgStruct.completeSuffix;
  qDebug() << "rotateImage: " << imgIn;

  backupOrigFile();

  QImage pix(imgIn);
  QImage pix_rotated = pix.transformed(QTransform().rotate(turn), Qt::SmoothTransformation);
  if (!pix_rotated.save(imgIn, nullptr, 100))
  {
    std::cerr << "rotateImage failed: " << imgIn.toStdString();
    return false;
  }
  else
  {
    std::cerr << "rotateImage successfully: " << imgIn.toStdString();
  }

  return true;
}

// TODOS
// path & src file
// reduced copy
// target format
// target quality
bool Img::convertImage(const QString &pathToSrcFile, const QString &convertTo, const int targetSize)
{
  QString imgIn = imgStruct.abolutePath + "/" + imgStruct.fileBasename + "." + imgStruct.completeSuffix;
  QString imgOutName = imgStruct.fileBasename + "__" + QString::number(targetSize) + "." + imgStruct.newSuffix;
  QString imgOut = imgStruct.abolutePath + "/" + imgStruct.newFolder;
  imgOut = imgOut + "/" + imgOutName;
  QImage imageInput{imgIn};

  if (!checkImgWidth(imageInput, targetSize))
  {
    qDebug() << "img is < " << targetSize;
    // well, the confused exit gate
    return true;
  }

  if (checkImgTargetExists(imgOut))
  {
    qDebug() << "target exists: " << imgOut.toStdString();
    // well, the confused exit gate
    return true;
  }
  else
  {
    qDebug() << "target doesn't exists: " << imgOut.toStdString();
    if (!createWebpPath())
    {
      std::cerr << "convertImage failed to create webp folder: " << imgOut.toStdString();
      return false;
    }
  }

  QImage reducedCopy{":/images/reduced_copy.png"};
  QImage imageOutput = imageInput.scaledToWidth(targetSize, Qt::SmoothTransformation);
  QPainter painter(&imageOutput);
  painter.drawImage(0, 0, reducedCopy);
  if (!imageOutput.save(imgOut, "WEBP", 75))
  {
    std::cerr << "convertImage failed to save webp image: " << imgOut.toStdString();
    return false;
  }
  return true;
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

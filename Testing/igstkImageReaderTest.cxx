/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    $RCSfile: igstkImageReaderTest.cxx,v $
  Language:  C++
  Date:      $Date: 2008-02-11 01:41:51 $
  Version:   $Revision: 1.9 $

  Copyright (c) ISC  Insight Software Consortium.  All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include "igstkImageReader.h"
#include "igstkImageSpatialObject.h"

#include "igstkLogger.h"
#include "itkStdStreamLogOutput.h"

int igstkImageReaderTest( int , char* [] )
{

  igstk::RealTimeClock::Initialize();

  typedef short    PixelType;
  const unsigned int Dimension = 3;

  typedef igstk::ImageSpatialObject< PixelType, Dimension > 
                                                 ImageSpatialObjectType;
  
  class myTestReader : 
    public igstk::ImageReader< ImageSpatialObjectType >
    {
  public:
    typedef myTestReader                                 Self;
    typedef igstk::ImageReader< ImageSpatialObjectType > Superclass;
    igstkNewMacro( Self );
  private:
    typedef Superclass::ImageType ImageType;
    virtual const ImageType * GetITKImage() const { return NULL; }
    };

  typedef myTestReader   ReaderType;

  ReaderType::Pointer  reader = ReaderType::New();

  reader->Print( std::cout );

  return EXIT_SUCCESS;
}

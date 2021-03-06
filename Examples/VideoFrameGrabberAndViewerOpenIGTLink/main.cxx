/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    $RCSfile: main.cxx,v $
  Language:  C++
  Date:      $Date: 2009-06-18 18:40:54 $
  Version:   $Revision: 1.1 $

  Copyright (c) ISC  Insight Software Consortium.  All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#if defined(_MSC_VER)
// Warning about: identifier was truncated to '255' characters
// in the debug information (MVC6.0 Debug)
#pragma warning( disable : 4284 )
#endif

#include "VideoFrameGrabberAndViewerOpenIGTLink.h"

int main(int, char** )
{

  igstk::RealTimeClock::Initialize();

  igstk::VideoFrameGrabberAndViewerOpenIGTLink * application =
                            new igstk::VideoFrameGrabberAndViewerOpenIGTLink();

  while( !application->HasQuitted() )
  {
    Fl::wait(0.001);
    igstk::PulseGenerator::CheckTimeouts();
  }

  application->mainWindow->hide();

  delete application;

  return EXIT_SUCCESS;
}

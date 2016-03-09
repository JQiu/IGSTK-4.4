/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    $RCSfile: igstkTrackerDataLoggerMainFLTK.cxx,v $
  Language:  C++
  Date:      $Date: 2011-02-04 22:42:16 $
  Version:   $Revision: 1.1 $

  Copyright (c) ISC  Insight Software Consortium.  All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "igstkTrackerDataLoggerGUI.h"

#include "igstkEvents.h"

int main(int , char *[] )
{
  TrackerDataLoggerGUI app;

  //required by IGSTK for the time stamping used by the tracker
  igstk::RealTimeClock::Initialize();

  app.Show();
  
  while( !app.HasQuitted() )
  {
    Fl::wait(0.001);
    igstk::PulseGenerator::CheckTimeouts();
  }


  return EXIT_SUCCESS;
}

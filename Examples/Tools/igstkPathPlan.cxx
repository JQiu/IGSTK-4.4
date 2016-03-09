/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    $RCSfile: igstkPathPlan.cxx,v $
  Language:  C++
  Date:      $Date: 2009-02-03 15:59:03 $
  Version:   $Revision: 1.1 $

  Copyright (c) ISC  Insight Software Consortium.  All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "igstkPathPlan.h"

namespace igstk
{

/** Constructor: Initializes all internal variables. */
PathPlan::PathPlan()
{
  m_EntryPoint.Fill( 0.0 );
  m_TargetPoint.Fill( 10.0 );
  PointType p;
  p.Fill( 0.0 );

  //m_TrackerCofigurations.clear();
  //TrackerConfiguration * config = new TrackerConfiguration;
  //m_TrackerCofigurations.push_back( config );
}

/** Destructor */
PathPlan::~PathPlan()
{

}
} // end of namespace

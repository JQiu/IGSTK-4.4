/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    $RCSfile: igstkLogger.cxx,v $
  Language:  C++
  Date:      $Date: 2008-02-11 01:41:50 $
  Version:   $Revision: 1.6 $

  Copyright (c) ISC  Insight Software Consortium.  All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "igstkLogger.h"

namespace igstk
{

Logger::Logger()
{
  /**  Our default priority level is WARNING.
   *   This overrides the behavior of the itkLogger.
   */
  this->m_PriorityLevel = Logger::WARNING;
}

Logger::~Logger()
{

}

bool 
Logger::
ShouldBuildMessage(PriorityLevelType level)
{
  if (this->GetPriorityLevel() >= level) 
    {
    return true;
    }
  else
    {
    return false;
    }
}


} // namespace igstk

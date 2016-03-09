/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    $RCSfile: igstkViewProxyBase.cxx,v $
  Language:  C++
  Date:      $Date: 2008-02-11 01:41:51 $
  Version:   $Revision: 1.1 $

  Copyright (c) ISC  Insight Software Consortium.  All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "igstkViewProxyBase.h"
#include "igstkView.h"
#include "vtkRenderer.h"
#include "vtkRenderWindowInteractor.h"

namespace igstk {

vtkRenderer * ViewProxyBase::GetRenderer( View * view )
{
  return view->GetRenderer();
} 

vtkRenderWindowInteractor * 
ViewProxyBase::GetRenderWindowInteractor( View * view )
{
  return view->GetRenderWindowInteractor();
} 

void
ViewProxyBase::InitializeInteractor( View * view )
{
  view->RequestInitializeRenderWindowInteractor();
}

void 
ViewProxyBase::SetRenderWindowSize( View * view, int width, int height )
{
  view->RequestSetRenderWindowSize( width, height );
}

void 
ViewProxyBase
::SetPickedPointCoordinates( View * view, 
                             double xPickedPoint,
                             double yPickedPoint)
{
  view->SetPickedPointCoordinates( xPickedPoint, yPickedPoint );
}

} // end namespace igstk

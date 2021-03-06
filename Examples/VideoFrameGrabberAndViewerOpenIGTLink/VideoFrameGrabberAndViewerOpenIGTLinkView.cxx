/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    $RCSfile: VideoFrameGrabberAndViewerOpenIGTLinkView.cxx,v $
  Language:  C++
  Date:      $Date: 2009-06-18 18:40:54 $
  Version:   $Revision: 1.1 $

  Copyright (c) ISC  Insight Software Consortium.  All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

// generated by Fast Light User Interface Designer (fluid) version 1.0107

#include "VideoFrameGrabberAndViewerOpenIGTLinkView.h"

namespace igstk
{

VideoFrameGrabberAndViewerOpenIGTLinkView::
VideoFrameGrabberAndViewerOpenIGTLinkView(int X, 
                                          int Y, 
                                          int W, 
                                          int H, 
                                          const char *L)
  : Fl_Group(X, Y, W, H, L)
{
  Fl_Group * parentGroup = this->parent();

  m_X = 150; // width of the control panel
  m_Y = 0;

  m_Width = parentGroup->w() - m_X;
  m_Height = parentGroup->h();

  // Create widgets
  typedef igstk::FLTKWidget   WidgetType;

  m_VideoWidget    = new WidgetType(X, Y, m_Width, m_Height, "Display 0");

  // Create views
  m_VideoView    = ViewType3D::New();

  m_VideoWidget->RequestSetView( m_VideoView );

  end();
}

VideoFrameGrabberAndViewerOpenIGTLinkView::
                                    ~VideoFrameGrabberAndViewerOpenIGTLinkView()
{
  delete m_VideoWidget;
}
} // end namespace igstk

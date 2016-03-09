/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    $RCSfile: igstkQuadrantViews.h,v $
  Language:  C++
  Date:      $Date: 2009-01-30 20:49:52 $
  Version:   $Revision: 1.1 $

  Copyright (c) ISC  Insight Software Consortium.  All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

// generated by Fast Light User Interface Designer (fluid) version 1.0107

#ifndef __igstkQuadrantViews_h
#define __igstkQuadrantViews_h
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Value_Slider.H>

#include "igstkFLTKWidget.h"
#include "igstkView2D.h"
#include "igstkView3D.h"
#include "igstkEvents.h"
#include "igstkCTImageSpatialObject.h"

namespace igstk {

/** \class QuadrantViews
* 
* \brief Composite FLTK class defines the standard four viewer windows.
*
* This class provides a convenient way to define the commonly used quadrant 
* views. It has three 2D views and one 3D view. From left to right and top to 
* bottom they are: Axial, Sagittal, Coronal, and 3D. For convenience, arrays
* of pointers are also provided for easy accessing of the Views and Widget 
* objects. The index for those object is: Axial=0, Sagittal=1, Coronal=2, 
* 3D=3.
* 
* There are also three slider bars for each 2D views, which can be used for
* image reslicing. When moving the slider bar, a ReslicingEvent carrying
* slice index (current value of the three slider bar) will be triggered. 
* User can observe this event and pass the index to image representation
* object to do reslicing.
* 
* For picking event, observer should be added directly to the internal View
* objects.
*
*/

class QuadrantViews : public Fl_Group {
public:

  QuadrantViews(int X, int Y, int W, int H, const char *L = 0);

  virtual ~QuadrantViews(void);

  typedef igstk::View          ViewType;
  typedef igstk::View2D        ViewType2D;
  typedef igstk::View3D        ViewType3D;

  // Declare View objects
  ViewType2D::Pointer          m_DisplayAxial;
  ViewType2D::Pointer          m_DisplayCoronal;
  ViewType2D::Pointer          m_DisplaySagittal;
  ViewType3D::Pointer          m_Display3D;

  // Declare FLTKWidget objects
  igstk::FLTKWidget * m_DisplayAxialWidget;
  igstk::FLTKWidget * m_DisplaySagittalWidget;
  igstk::FLTKWidget * m_DisplayCoronalWidget;
  igstk::FLTKWidget * m_Display3DWidget;

  // Define slider bars
  Fl_Value_Slider * m_AxialSlider;
  Fl_Value_Slider * m_SagittalSlider;
  Fl_Value_Slider * m_CoronalSlider;

  // Array of pointer to the View, Widget, and Slider bar
  std::vector< igstk::FLTKWidget * >   m_Displays;
  std::vector< ViewType::Pointer   >   m_Views;
  std::vector< Fl_Value_Slider   * >   m_Sliders;

  /** Event for reslicing from slider bar */
  typedef CTImageSpatialObject::IndexType  IndexType;

  igstkLoadedEventMacro( ReslicingEvent, IGSTKEvent, IndexType );

  unsigned long AddObserver( 
    const ::itk::EventObject & event, ::itk::Command * observer );

  void RemoveObserver( unsigned long tag );
  void RemoveAllObservers();

protected:

  virtual void RequestResliceImage(void);

private:

  // Call backs for slider bars
  void cb_AxialSlider_i(Fl_Value_Slider*, void*);
  static void cb_AxialSlider(Fl_Value_Slider*, void*);
  void cb_SagittalSlider_i(Fl_Value_Slider*, void*);
  static void cb_SagittalSlider(Fl_Value_Slider*, void*);
  void cb_CoronalSlider_i(Fl_Value_Slider*, void*);
  static void cb_CoronalSlider(Fl_Value_Slider*, void*);

  ::itk::Object::Pointer    m_Reporter;

};

} // end namespace igstk

#endif
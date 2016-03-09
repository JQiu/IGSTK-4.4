/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    $RCSfile: TrackingVolumeViewer.h,v $
  Language:  C++
  Date:      $Date: 2009-04-27 17:36:47 $
  Version:   $Revision: 1.2 $

  Copyright (c) ISC  Insight Software Consortium.  All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __TrackingVolumeViewer_h
#define __TrackingVolumeViewer_h

#include "TrackingVolumeViewerGUI.h"

#include "igstkConfigure.h"

#include "igstkStateMachine.h"
#include "igstkMacros.h"
#include "igstkObject.h"
#include "igstkEvents.h"

#include "igstkTracker.h"
#include "igstkTrackerTool.h"

#include "igstkEllipsoidObject.h"
#include "igstkEllipsoidObjectRepresentation.h"

#include "igstkMeshReader.h"
#include "igstkMeshObjectRepresentation.h"

#include "igstkAxesObject.h"
#include "igstkAxesObjectRepresentation.h"

#include "itkStdStreamLogOutput.h"

#include "igstkTrackerController.h"
#include "igstkTrackerConfiguration.h"

#include "igstkReslicerPlaneSpatialObject.h"
#include "igstkMeshResliceObjectRepresentation.h"

#include "igstkMicronTrackerConfiguration.h"
#include "igstkAuroraTrackerConfiguration.h"

#include "igstkTransformFileReader.h"
#include "igstkRigidTransformXMLFileReader.h"
#include "igstkTrackerConfigurationFileReader.h"
#include "igstkTrackerConfigurationXMLFileReaderBase.h"

/** \class TrackingVolumeViewer
* 
* \brief Implementation class for TrackingVolumeViewerGUI.
*
* This class implements the main application.
*
*/
class TrackingVolumeViewer : public TrackingVolumeViewerGUI
{
public:

  /** Typedefs */
  igstkStandardClassBasicTraitsMacro( TrackingVolumeViewer, TrackingVolumeViewerGUI );
  
  igstkLoggerMacro();

  /** Declarations needed for the State Machine */
  igstkStateMachineMacro();

  /** typedef for mesh readers */
  typedef igstk::MeshReader                           MeshReaderType;

  /** typedef for mesh spatial object */
  typedef MeshReaderType::MeshObjectType              MeshObjectType;

  /** typedef for mesh spatial object representation */
  typedef igstk::MeshObjectRepresentation             MeshRepresentationType;

  /** typedef for ellipsoid spatial object */
  typedef igstk::EllipsoidObject                      EllipsoidType;

  /** typedef for ellipsoid spatial object representation*/
  typedef igstk::EllipsoidObjectRepresentation        EllipsoidRepresentationType;

  /** typedef for a vector of ellipsoid spatial objects and representations*/
  typedef std::vector < EllipsoidType::Pointer >      
                                                      EllipsoidSpatialObjectVectorType;

  typedef std::vector < EllipsoidRepresentationType::Pointer >    
                                                      EllipsoidRepresentationVectorType;
  /** reslicer plane spatial object */
  typedef igstk::ReslicerPlaneSpatialObject           ReslicerPlaneType;

  /** mesh reslice representation */
  typedef igstk::MeshResliceObjectRepresentation      MeshResliceRepresentationType;

  /** typedef for axes spatial objects */
  typedef igstk::AxesObject                           AxesObjectType;
  typedef igstk::AxesObjectRepresentation             AxesRepresentationType;

  /** typedef for the vector of tracker tools */
  typedef std::vector < igstk::TrackerTool::Pointer >    ToolVectorType;


  /** Public request methods from the GUI */
  virtual void RequestLoadTrackerMesh();
  virtual void RequestLoadWorkingVolumeMesh();
  virtual void RequestPrepareToQuit();

  /**
   * Open the relevant tracker settings dialog (Polaris/Aurora/Micron/Ascension)
   * and get the users input.
   */
  virtual void RequestConfigureTracker();
  virtual void RequestInitializeTracker();  
  virtual void RequestStartTracking();
  virtual void RequestStopTracking();
  virtual void RequestDisconnectTracker();

    /**
   * Observer for the event generated by 
   * TrackerConfigurationFileReader->RequestGetData() method.
   */
  igstkObserverObjectMacro( TrackerConfiguration, 
                   igstk::TrackerConfigurationFileReader::TrackerConfigurationDataEvent,
                   igstk::TrackerConfiguration)

  igstkObserverMacro( TransformData, 
                    igstk::TransformFileReader::TransformDataEvent, 
                    igstk::PrecomputedTransformData::Pointer )

  igstkObserverMacro( TransformationDescription, 
                      igstk::StringEvent, 
                      std::string )

  igstkObserverMacro( TransformationDate, 
                      igstk::PrecomputedTransformData::TransformDateTypeEvent, 
                      std::string )

  typedef igstk::TrackerConfigurationFileReader::ReadTrackerConfigurationFailSuccessObserver
                    ReadTrackerConfigurationFailSuccessObserverType;

  igstkObserverMacro( TransformError, 
                      igstk::PrecomputedTransformData::TransformErrorTypeEvent, 
                      igstk::PrecomputedTransformData::ErrorType )


  /** Define observers for event communication */

  igstkObserverObjectMacro( MeshObject, igstk::MeshReader::MeshModifiedEvent,
                                        igstk::MeshObject);

  igstkEventMacro( InvalidRequestErrorEvent, igstk::IGSTKErrorEvent );

  TrackingVolumeViewer();
  virtual ~TrackingVolumeViewer();

private:

  TrackingVolumeViewer(const Self&); // purposely not implemented
  void operator=(const Self&); // purposely not implemented
  
   /** States for the State Machine */
  igstkDeclareStateMacro( Initial );
  igstkDeclareStateMacro( ConfiguringTracker );
  igstkDeclareStateMacro( TrackerConfigurationReady );
  igstkDeclareStateMacro( InitializingTracker );
  igstkDeclareStateMacro( TrackerInitializationReady );
  igstkDeclareStateMacro( LoadingMesh );
  igstkDeclareStateMacro( StartingTracker );
  igstkDeclareStateMacro( StoppingTracker );
  igstkDeclareStateMacro( DisconnectingTracker );
  igstkDeclareStateMacro( Tracking );
  
   /** Inputs to the state machine and it's designed transitions */
  igstkDeclareInputMacro( Success );
  igstkDeclareInputMacro( Failure );
  igstkDeclareInputMacro( LoadTrackerMesh );
  igstkDeclareInputMacro( LoadWorkingVolumeMesh );
  igstkDeclareInputMacro( ConfigureTracker );
  igstkDeclareInputMacro( InitializeTracker );
  igstkDeclareInputMacro( StartTracking );
  igstkDeclareInputMacro( StopTracking );
  igstkDeclareInputMacro( DisconnectTracker );

  /** Define a initial world coordinate system */
  AxesObjectType::Pointer                               m_WorldReference;
  AxesRepresentationType::Pointer                       m_WorldReferenceRepresentation;

  /** SpatialObject and representation for the tracker�s working volume */
  MeshObjectType::Pointer                               m_MeshSpatialObject;
  MeshRepresentationType::Pointer                       m_MeshRepresentation;

  /** SpatialObject and representation for the tracker�s tip */
  EllipsoidSpatialObjectVectorType                      m_TipSpatialObjectVector;
  EllipsoidRepresentationVectorType                     m_TipRepresentationVector;

  /** tracker configuration object */
  const igstk::TrackerConfiguration *                   m_TrackerConfiguration;

  /** plane reslicer spatial objects */
  ReslicerPlaneType::Pointer                            m_AxialPlaneSpatialObject;
  ReslicerPlaneType::Pointer                            m_SagittalPlaneSpatialObject;
  ReslicerPlaneType::Pointer                            m_CoronalPlaneSpatialObject;
 
  MeshResliceRepresentationType::Pointer                m_AxialMeshResliceRepresentation;
  MeshResliceRepresentationType::Pointer                m_SagittalMeshResliceRepresentation;
  MeshResliceRepresentationType::Pointer                m_CoronalMeshResliceRepresentation;

  /** Class that observes the events generated by the tracker controller. */
  class TrackerControllerObserver : public itk::Command
  {
  public:
    typedef TrackerControllerObserver            Self;
    typedef ::itk::Command                       Superclass;
    typedef ::itk::SmartPointer<Self>            Pointer;
    typedef ::itk::SmartPointer<const Self>      ConstPointer;

    igstkNewMacro(Self)
    igstkTypeMacro(TrackerControllerObserver, itk::Command)

    void SetParent(TrackingVolumeViewer *p); 

      /** Invoke this method when an initialization event occurs. */
    void Execute(itk::Object *caller, const itk::EventObject & event); 
    void Execute(const itk::Object *caller, const itk::EventObject & event);
  
    /**
     * Clear the current error.
     */
    void ClearError() 
    {
      this->m_ErrorOccured = false; 
      this->m_ErrorMessage.clear();
    }
    /**
     * If an error occurs in one of the observed IGSTK components this method will return true.
     */
    bool Error() 
    {
      return this->m_ErrorOccured;
    }

    void GetErrorMessage(std::string &errorMessage) 
    {
      errorMessage = this->m_ErrorMessage;
    }


  protected:
    TrackerControllerObserver() : m_Parent(NULL), m_ErrorOccured(false) {}
    virtual ~TrackerControllerObserver(){}


  private:
    TrackingVolumeViewer *m_Parent;
    bool m_ErrorOccured;
    std::string m_ErrorMessage;

    //purposely not implemented
    TrackerControllerObserver(const Self&);
    void operator=(const Self&); 
  };

  /** Class that observes the events generated by the transform reader. */
  class ReadObserver : public itk::Command
  {
  public:
    typedef ReadObserver                    Self;
    typedef ::itk::Command                   Superclass;
    typedef ::itk::SmartPointer<Self>        Pointer;
    typedef ::itk::SmartPointer<const Self>  ConstPointer;

    igstkNewMacro( Self )
    igstkTypeMacro( ReadObserver, itk::Command )

    virtual void Execute( itk::Object *caller, const itk::EventObject & event )
    {
      const igstk::TransformFileReader::ReadFailureEvent *rfe;
      if( ( rfe = dynamic_cast<const igstk::TransformFileReader::ReadFailureEvent *>( &event ) ) ) 
        std::cerr<<rfe->Get()<<"\n";
      else if( dynamic_cast<const igstk::TransformFileReader::ReadSuccessEvent *>( &event ) )
        ( static_cast<igstk::TransformFileReader *>( caller ) )->RequestGetData();
    }

    virtual void Execute( const itk::Object *caller, 
                          const itk::EventObject & event )
    {
      const itk::Object * constCaller = caller;
      this->Execute( constCaller, event );
    }
  protected:

    ReadObserver(){}
    virtual ~ReadObserver(){}
  private:
    //purposely not implemented
    ReadObserver(const Self&);
    void operator=(const Self&); 
  };

  igstk::TrackerController::Pointer                     m_TrackerController;
  TrackerControllerObserver::Pointer                    m_TrackerControllerObserver;

  ToolVectorType                                        m_ToolVector;
  
  /** Action methods to be invoked only by the state machine */
  void NoProcessing();
  void ReportInvalidRequestProcessing();
  void ReportSuccessSpatialObjectLoadedProcessing();
  void ReportFailuredSpatialObjectLoadedProcessing();
  void ReportSuccessMeshLoadedProcessing();
  void ReportFailuredMeshLoadedProcessing();
  void ReportSuccessTrackerConfigurationProcessing();
  void ReportFailureTrackerConfigurationProcessing();
  void ReportSuccessTrackerInitializationProcessing();
  void ReportFailureTrackerInitializationProcessing();
  void ReportSuccessTrackerDisconnectionProcessing();
  void ReportFailureTrackerDisconnectionProcessing();  
  void ReportSuccessStopTrackingProcessing();
  void ReportFailureStopTrackingProcessing();
  void ReportSuccessStartTrackingProcessing();
  void ReportFailureStartTrackingProcessing();
  void LoadTrackerMeshProcessing();
  void LoadWorkingVolumeMeshProcessing();
  void ConfigureTrackerProcessing();
  void InitializeTrackerProcessing();
  void StartTrackingProcessing();
  void StopTrackingProcessing();
  void DisconnectTrackerProcessing();

  void ReportError( const std::string &message );
  void ReportError( const char *message );

  /** Observer type for loaded event, 
   *  the callback can be set to a member function. */
  typedef itk::ReceptorMemberCommand < Self > LoadedObserverType;
  typedef itk::SimpleMemberCommand < Self > CancelObserverType;
  
  CancelObserverType::Pointer               m_TrackerConfigurationCancelObserver;
      
  /** Log file */
  std::ofstream                                   m_LogFile;  

};

#endif
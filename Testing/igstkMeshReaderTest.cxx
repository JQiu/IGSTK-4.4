/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    $RCSfile: igstkMeshReaderTest.cxx,v $
  Language:  C++
  Date:      $Date: 2008-05-06 17:37:38 $
  Version:   $Revision: 1.8 $

  Copyright (c) ISC  Insight Software Consortium.  All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include "igstkMeshReader.h"

#include "igstkLogger.h"
#include "itkStdStreamLogOutput.h"

igstkObserverObjectMacro( MeshObject, 
                          igstk::MeshReader::MeshModifiedEvent,
                          igstk::MeshObject);

int igstkMeshReaderTest( int argc, char * argv [] )
{

  igstk::RealTimeClock::Initialize();


  if( argc < 3 )
    {
    std::cerr << "Error: Missing command line arguments" << std::endl;
    std::cerr << "Usage : " << std::endl;
    std::cerr << argv[0] << " inputGoodFileName ";
    std::cerr << " inputBadFileName " << std::endl;
    return 1;
    }
  
  typedef igstk::MeshReader    ReaderType;

  ReaderType::Pointer  reader = ReaderType::New();

  typedef igstk::Object::LoggerType   LoggerType;
  typedef itk::StdStreamLogOutput     LogOutputType;
  
  // logger object created for logging mouse activities
  LoggerType::Pointer   logger = LoggerType::New();
  LogOutputType::Pointer logOutput = LogOutputType::New();
  logOutput->SetStream( std::cout );
  logger->AddLogOutput( logOutput );
  logger->SetPriorityLevel( itk::Logger::DEBUG );

  reader->SetLogger( logger );

  std::string name = reader->GetNameOfClass();

  std::cout << "Name of class = " << name << std::endl;

  reader->Print( std::cout );

  // Test error condition: on purpose request to read an object
  // without having provided the filename 
  reader->RequestReadObject();

  // Test empty name
  std::string emptyname;
  reader->RequestSetFileName( emptyname );
  
  // Test file doesn't exist
  std::string filenameThatDoesntExist = "/This/FileName/Does/Not/Exist";
  reader->RequestSetFileName( filenameThatDoesntExist );

  // Test file that is a directory
  std::string filenameIsADirectory = ".";
  reader->RequestSetFileName( filenameIsADirectory );
  
  // Test file that exists
  std::string filenameThatExists = argv[1];
  reader->RequestSetFileName( filenameThatExists );

  // Request to read the object from the file
  reader->RequestReadObject();

  // Attach an observer
  MeshObjectObserver::Pointer observer = MeshObjectObserver::New();

  reader->AddObserver(igstk::MeshReader::MeshModifiedEvent(),observer);

  reader->RequestGetOutput();

  if(!observer->GotMeshObject())
  {
    std::cout << "No MeshObject!" << std::endl;
    std::cout << "[FAILED]" << std::endl;
    return EXIT_FAILURE;
  }

  observer->GetMeshObject()->Print( std::cout );
  
  // Now reading a corrupted file
  std::string filenameWithCorruptedContent = argv[2];
  reader->RequestSetFileName( filenameWithCorruptedContent );
  reader->RequestReadObject();
  
  return EXIT_SUCCESS;
}

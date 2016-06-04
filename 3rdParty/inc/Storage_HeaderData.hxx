// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Storage_HeaderData_HeaderFile
#define _Storage_HeaderData_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_Storage_HeaderData.hxx>

#include <Standard_Integer.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Storage_Error.hxx>
#include <MMgt_TShared.hxx>
class Storage_Schema;
class TCollection_AsciiString;
class TCollection_ExtendedString;
class TColStd_SequenceOfAsciiString;
class TColStd_SequenceOfExtendedString;



class Storage_HeaderData : public MMgt_TShared
{

public:

  
  Standard_EXPORT Storage_HeaderData();
  
  //! return the creation date
  Standard_EXPORT   TCollection_AsciiString CreationDate()  const;
  
  //! return the Storage package version
  Standard_EXPORT   TCollection_AsciiString StorageVersion()  const;
  
  //! get the version of the schema
  Standard_EXPORT   TCollection_AsciiString SchemaVersion()  const;
  
  //! get the schema's name
  Standard_EXPORT   TCollection_AsciiString SchemaName()  const;
  
  //! set the version of the application
  Standard_EXPORT   void SetApplicationVersion (const TCollection_AsciiString& aVersion) ;
  
  //! get the version of the application
  Standard_EXPORT   TCollection_AsciiString ApplicationVersion()  const;
  
  //! set the name of the application
  Standard_EXPORT   void SetApplicationName (const TCollection_ExtendedString& aName) ;
  
  //! get the name of the application
  Standard_EXPORT   TCollection_ExtendedString ApplicationName()  const;
  
  //! set the data type
  Standard_EXPORT   void SetDataType (const TCollection_ExtendedString& aType) ;
  
  //! returns data type
  Standard_EXPORT   TCollection_ExtendedString DataType()  const;
  
  //! add <theUserInfo> to the user informations
  Standard_EXPORT   void AddToUserInfo (const TCollection_AsciiString& theUserInfo) ;
  
  //! return the user informations
  Standard_EXPORT  const  TColStd_SequenceOfAsciiString& UserInfo()  const;
  
  //! add <theUserInfo> to the user informations
  Standard_EXPORT   void AddToComments (const TCollection_ExtendedString& aComment) ;
  
  //! return the user informations
  Standard_EXPORT  const  TColStd_SequenceOfExtendedString& Comments()  const;
  
  //! the the number of persistent objects
  //! Return:
  //! the number of persistent objects readed
  Standard_EXPORT   Standard_Integer NumberOfObjects()  const;
  
  Standard_EXPORT   Storage_Error ErrorStatus()  const;
  
  Standard_EXPORT   TCollection_AsciiString ErrorStatusExtension()  const;
  
  Standard_EXPORT   void ClearErrorStatus() ;


friend class Storage_Schema;


  DEFINE_STANDARD_RTTI(Storage_HeaderData)

protected:




private: 

  
  Standard_EXPORT   void SetNumberOfObjects (const Standard_Integer anObjectNumber) ;
  
  Standard_EXPORT   void SetStorageVersion (const TCollection_AsciiString& aVersion) ;
  
  Standard_EXPORT   void SetCreationDate (const TCollection_AsciiString& aDate) ;
  
  Standard_EXPORT   void SetSchemaVersion (const TCollection_AsciiString& aVersion) ;
  
  Standard_EXPORT   void SetSchemaName (const TCollection_AsciiString& aName) ;
  
  Standard_EXPORT   void SetErrorStatus (const Storage_Error anError) ;
  
  Standard_EXPORT   void SetErrorStatusExtension (const TCollection_AsciiString& anErrorExt) ;

  Standard_Integer myNBObj;
  TCollection_AsciiString myStorageVersion;
  TCollection_AsciiString mySchemaVersion;
  TCollection_AsciiString mySchemaName;
  TCollection_AsciiString myApplicationVersion;
  TCollection_ExtendedString myApplicationName;
  TCollection_ExtendedString myDataType;
  TCollection_AsciiString myDate;
  TColStd_SequenceOfAsciiString myUserInfo;
  TColStd_SequenceOfExtendedString myComments;
  Storage_Error myErrorStatus;
  TCollection_AsciiString myErrorStatusExt;


};







#endif // _Storage_HeaderData_HeaderFile
// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TDF_DeltaOnResume_HeaderFile
#define _TDF_DeltaOnResume_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_TDF_DeltaOnResume.hxx>

#include <TDF_AttributeDelta.hxx>
#include <Handle_TDF_Attribute.hxx>
class TDF_Attribute;


//! This class provides default services for an
//! AttributeDelta on an Resume action.
//!
//! Applying this AttributeDelta means FORGETTING its
//! attribute.
class TDF_DeltaOnResume : public TDF_AttributeDelta
{

public:

  
  //! Creates a TDF_DeltaOnResume.
  Standard_EXPORT TDF_DeltaOnResume(const Handle(TDF_Attribute)& anAtt);
  
  //! Applies the delta to the attribute.
  Standard_EXPORT   void Apply() ;




  DEFINE_STANDARD_RTTI(TDF_DeltaOnResume)

protected:




private: 




};







#endif // _TDF_DeltaOnResume_HeaderFile
// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepElement_VolumeElementPurpose_HeaderFile
#define _StepElement_VolumeElementPurpose_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <StepData_SelectType.hxx>
#include <Standard_Integer.hxx>
#include <Handle_Standard_Transient.hxx>
#include <Handle_StepData_SelectMember.hxx>
#include <StepElement_EnumeratedVolumeElementPurpose.hxx>
#include <Handle_TCollection_HAsciiString.hxx>
class Standard_Transient;
class StepData_SelectMember;
class TCollection_HAsciiString;


//! Representation of STEP SELECT type VolumeElementPurpose
class StepElement_VolumeElementPurpose  : public StepData_SelectType
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Empty constructor
  Standard_EXPORT StepElement_VolumeElementPurpose();
  
  //! Recognizes a kind of VolumeElementPurpose select type
  //! return 0
  Standard_EXPORT   Standard_Integer CaseNum (const Handle(Standard_Transient)& ent)  const;
  
  //! Recognizes a items of select member VolumeElementPurposeMember
  //! 1 -> EnumeratedVolumeElementPurpose
  //! 2 -> ApplicationDefinedElementPurpose
  //! 0 else
  Standard_EXPORT virtual   Standard_Integer CaseMem (const Handle(StepData_SelectMember)& ent)  const;
  
  //! Returns a new select member the type VolumeElementPurposeMember
  Standard_EXPORT virtual   Handle(StepData_SelectMember) NewMember()  const;
  
  //! Set Value for EnumeratedVolumeElementPurpose
  Standard_EXPORT   void SetEnumeratedVolumeElementPurpose (const StepElement_EnumeratedVolumeElementPurpose aVal) ;
  
  //! Returns Value as EnumeratedVolumeElementPurpose (or Null if another type)
  Standard_EXPORT   StepElement_EnumeratedVolumeElementPurpose EnumeratedVolumeElementPurpose()  const;
  
  //! Set Value for ApplicationDefinedElementPurpose
  Standard_EXPORT   void SetApplicationDefinedElementPurpose (const Handle(TCollection_HAsciiString)& aVal) ;
  
  //! Returns Value as ApplicationDefinedElementPurpose (or Null if another type)
  Standard_EXPORT   Handle(TCollection_HAsciiString) ApplicationDefinedElementPurpose()  const;




protected:





private:





};







#endif // _StepElement_VolumeElementPurpose_HeaderFile

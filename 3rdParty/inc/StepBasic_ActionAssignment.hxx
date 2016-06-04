// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_ActionAssignment_HeaderFile
#define _StepBasic_ActionAssignment_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepBasic_ActionAssignment.hxx>

#include <Handle_StepBasic_Action.hxx>
#include <MMgt_TShared.hxx>
class StepBasic_Action;


//! Representation of STEP entity ActionAssignment
class StepBasic_ActionAssignment : public MMgt_TShared
{

public:

  
  //! Empty constructor
  Standard_EXPORT StepBasic_ActionAssignment();
  
  //! Initialize all fields (own and inherited)
  Standard_EXPORT   void Init (const Handle(StepBasic_Action)& aAssignedAction) ;
  
  //! Returns field AssignedAction
  Standard_EXPORT   Handle(StepBasic_Action) AssignedAction()  const;
  
  //! Set field AssignedAction
  Standard_EXPORT   void SetAssignedAction (const Handle(StepBasic_Action)& AssignedAction) ;




  DEFINE_STANDARD_RTTI(StepBasic_ActionAssignment)

protected:




private: 


  Handle(StepBasic_Action) theAssignedAction;


};







#endif // _StepBasic_ActionAssignment_HeaderFile

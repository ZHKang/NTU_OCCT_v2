// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _RWStepAP203_RWStartRequest_HeaderFile
#define _RWStepAP203_RWStartRequest_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Handle_StepData_StepReaderData.hxx>
#include <Standard_Integer.hxx>
#include <Handle_Interface_Check.hxx>
#include <Handle_StepAP203_StartRequest.hxx>
class StepData_StepReaderData;
class Interface_Check;
class StepAP203_StartRequest;
class StepData_StepWriter;
class Interface_EntityIterator;


//! Read & Write tool for StartRequest
class RWStepAP203_RWStartRequest 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Empty constructor
  Standard_EXPORT RWStepAP203_RWStartRequest();
  
  //! Reads StartRequest
  Standard_EXPORT   void ReadStep (const Handle(StepData_StepReaderData)& data, const Standard_Integer num, Handle(Interface_Check)& ach, const Handle(StepAP203_StartRequest)& ent)  const;
  
  //! Writes StartRequest
  Standard_EXPORT   void WriteStep (StepData_StepWriter& SW, const Handle(StepAP203_StartRequest)& ent)  const;
  
  //! Fills data for graph (shared items)
  Standard_EXPORT   void Share (const Handle(StepAP203_StartRequest)& ent, Interface_EntityIterator& iter)  const;




protected:





private:





};







#endif // _RWStepAP203_RWStartRequest_HeaderFile
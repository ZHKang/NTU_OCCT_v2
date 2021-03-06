// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_ProductContext_HeaderFile
#define _StepBasic_ProductContext_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepBasic_ProductContext.hxx>

#include <Handle_TCollection_HAsciiString.hxx>
#include <StepBasic_ApplicationContextElement.hxx>
#include <Handle_StepBasic_ApplicationContext.hxx>
class TCollection_HAsciiString;
class StepBasic_ApplicationContext;



class StepBasic_ProductContext : public StepBasic_ApplicationContextElement
{

public:

  
  //! Returns a ProductContext
  Standard_EXPORT StepBasic_ProductContext();
  
  Standard_EXPORT virtual   void Init (const Handle(TCollection_HAsciiString)& aName, const Handle(StepBasic_ApplicationContext)& aFrameOfReference) ;
  
  Standard_EXPORT virtual   void Init (const Handle(TCollection_HAsciiString)& aName, const Handle(StepBasic_ApplicationContext)& aFrameOfReference, const Handle(TCollection_HAsciiString)& aDisciplineType) ;
  
  Standard_EXPORT   void SetDisciplineType (const Handle(TCollection_HAsciiString)& aDisciplineType) ;
  
  Standard_EXPORT   Handle(TCollection_HAsciiString) DisciplineType()  const;




  DEFINE_STANDARD_RTTI(StepBasic_ProductContext)

protected:




private: 


  Handle(TCollection_HAsciiString) disciplineType;


};







#endif // _StepBasic_ProductContext_HeaderFile

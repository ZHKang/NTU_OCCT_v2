// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_SiUnitAndLengthUnit_HeaderFile
#define _StepBasic_SiUnitAndLengthUnit_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepBasic_SiUnitAndLengthUnit.hxx>

#include <Handle_StepBasic_LengthUnit.hxx>
#include <StepBasic_SiUnit.hxx>
#include <Handle_StepBasic_DimensionalExponents.hxx>
#include <Standard_Boolean.hxx>
#include <StepBasic_SiPrefix.hxx>
#include <StepBasic_SiUnitName.hxx>
class StepBasic_LengthUnit;
class StepBasic_DimensionalExponents;



class StepBasic_SiUnitAndLengthUnit : public StepBasic_SiUnit
{

public:

  
  //! Returns a SiUnitAndLengthUnit
  Standard_EXPORT StepBasic_SiUnitAndLengthUnit();
  
  Standard_EXPORT virtual   void Init (const Handle(StepBasic_DimensionalExponents)& aDimensions) ;
  
  Standard_EXPORT virtual   void Init (const Standard_Boolean hasAprefix, const StepBasic_SiPrefix aPrefix, const StepBasic_SiUnitName aName) ;
  
  Standard_EXPORT   void SetLengthUnit (const Handle(StepBasic_LengthUnit)& aLengthUnit) ;
  
  Standard_EXPORT   Handle(StepBasic_LengthUnit) LengthUnit()  const;




  DEFINE_STANDARD_RTTI(StepBasic_SiUnitAndLengthUnit)

protected:




private: 


  Handle(StepBasic_LengthUnit) lengthUnit;


};







#endif // _StepBasic_SiUnitAndLengthUnit_HeaderFile
// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepRepr_HArray1OfPropertyDefinitionRepresentation_HeaderFile
#define _StepRepr_HArray1OfPropertyDefinitionRepresentation_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepRepr_HArray1OfPropertyDefinitionRepresentation.hxx>

#include <StepRepr_Array1OfPropertyDefinitionRepresentation.hxx>
#include <MMgt_TShared.hxx>
#include <Handle_StepRepr_PropertyDefinitionRepresentation.hxx>
#include <Standard_Integer.hxx>
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class StepRepr_PropertyDefinitionRepresentation;
class StepRepr_Array1OfPropertyDefinitionRepresentation;



class StepRepr_HArray1OfPropertyDefinitionRepresentation : public MMgt_TShared
{

public:

  
    StepRepr_HArray1OfPropertyDefinitionRepresentation(const Standard_Integer Low, const Standard_Integer Up);
  
    StepRepr_HArray1OfPropertyDefinitionRepresentation(const Standard_Integer Low, const Standard_Integer Up, const Handle(StepRepr_PropertyDefinitionRepresentation)& V);
  
      void Init (const Handle(StepRepr_PropertyDefinitionRepresentation)& V) ;
  
      Standard_Integer Length()  const;
  
      Standard_Integer Lower()  const;
  
      Standard_Integer Upper()  const;
  
      void SetValue (const Standard_Integer Index, const Handle(StepRepr_PropertyDefinitionRepresentation)& Value) ;
  
     const  Handle(StepRepr_PropertyDefinitionRepresentation)& Value (const Standard_Integer Index)  const;
  
      Handle(StepRepr_PropertyDefinitionRepresentation)& ChangeValue (const Standard_Integer Index) ;
  
     const  StepRepr_Array1OfPropertyDefinitionRepresentation& Array1()  const;
  
      StepRepr_Array1OfPropertyDefinitionRepresentation& ChangeArray1() ;




  DEFINE_STANDARD_RTTI(StepRepr_HArray1OfPropertyDefinitionRepresentation)

protected:




private: 


  StepRepr_Array1OfPropertyDefinitionRepresentation myArray;


};

#define ItemHArray1 Handle(StepRepr_PropertyDefinitionRepresentation)
#define ItemHArray1_hxx <StepRepr_PropertyDefinitionRepresentation.hxx>
#define TheArray1 StepRepr_Array1OfPropertyDefinitionRepresentation
#define TheArray1_hxx <StepRepr_Array1OfPropertyDefinitionRepresentation.hxx>
#define TCollection_HArray1 StepRepr_HArray1OfPropertyDefinitionRepresentation
#define TCollection_HArray1_hxx <StepRepr_HArray1OfPropertyDefinitionRepresentation.hxx>
#define Handle_TCollection_HArray1 Handle_StepRepr_HArray1OfPropertyDefinitionRepresentation
#define TCollection_HArray1_Type_() StepRepr_HArray1OfPropertyDefinitionRepresentation_Type_()

#include <TCollection_HArray1.lxx>

#undef ItemHArray1
#undef ItemHArray1_hxx
#undef TheArray1
#undef TheArray1_hxx
#undef TCollection_HArray1
#undef TCollection_HArray1_hxx
#undef Handle_TCollection_HArray1
#undef TCollection_HArray1_Type_




#endif // _StepRepr_HArray1OfPropertyDefinitionRepresentation_HeaderFile

// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Quantity_Convert_HeaderFile
#define _Quantity_Convert_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Quantity_PhysicalQuantity.hxx>
#include <Quantity_Coefficient.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
class TCollection_AsciiString;


//! Services to manage units conversion between Front-ends and Engines.
//! This conversion is managed by a table of correspondance between the quantities
//! and their "conversion coefficient".
//! This table is implemented like an external array (TCollection_Array1) regarding
//! to the quantities enumeration.
class Quantity_Convert 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Creates an object;
  Standard_EXPORT Quantity_Convert();
  
  //! Updates the conversion table (correspondances between
  //! Quantities and conversion coefficients).
    static   void SetQuantity (const Quantity_PhysicalQuantity aQuantity, const Quantity_Coefficient aCoef) ;
  
  //! Converts, from the conversion table, the value <aVal>
  //! from the user system to the SI system.
    static   Standard_Real ConvertUserToSI (const Quantity_PhysicalQuantity aQuantity, const Standard_Real aVal) ;
  
  //! Converts, from the conversion table, the value <aVal>
  //! from the SI system to the user system.
    static   Standard_Real ConvertSIToUser (const Quantity_PhysicalQuantity aQuantity, const Standard_Real aVal) ;
  

  //! if (aType is a physical quantity)
  //! returns True and the name of the associated PhysicalQuantity .
  //! else
  //! returns False.
  Standard_EXPORT static   Standard_Boolean IsPhysicalQuantity (const TCollection_AsciiString& aTypeName, TCollection_AsciiString& anEnum) ;




protected:





private:





};


#include <Quantity_Convert.lxx>





#endif // _Quantity_Convert_HeaderFile

// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESGeom_Boundary_HeaderFile
#define _IGESGeom_Boundary_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_IGESGeom_Boundary.hxx>

#include <Standard_Integer.hxx>
#include <Handle_IGESData_IGESEntity.hxx>
#include <Handle_IGESData_HArray1OfIGESEntity.hxx>
#include <Handle_TColStd_HArray1OfInteger.hxx>
#include <Handle_IGESBasic_HArray1OfHArray1OfIGESEntity.hxx>
#include <IGESData_IGESEntity.hxx>
class IGESData_IGESEntity;
class IGESData_HArray1OfIGESEntity;
class TColStd_HArray1OfInteger;
class IGESBasic_HArray1OfHArray1OfIGESEntity;
class Standard_DimensionMismatch;
class Standard_OutOfRange;


//! defines IGESBoundary, Type <141> Form <0>
//! in package IGESGeom
//! A boundary entity identifies a surface boundary consisting
//! of a set of curves lying on the surface
class IGESGeom_Boundary : public IGESData_IGESEntity
{

public:

  
  Standard_EXPORT IGESGeom_Boundary();
  
  //! This method is used to set the fields of the class
  //! Boundary
  //! - aType              : Type of bounded surface representation
  //! - aPreference        : Preferred representation of
  //! Trimming Curve
  //! - aSurface           : Untrimmed surface to be bounded
  //! - allModelCurves     : Model Space Curves
  //! - allSenses          : Orientation flags of all Model Space
  //! Curves
  //! - allParameterCurves : Parameter Space Curves
  //! raises exception if allSenses, allModelCurves and
  //! allParameterCurves do not have same dimensions
  Standard_EXPORT   void Init (const Standard_Integer aType, const Standard_Integer aPreference, const Handle(IGESData_IGESEntity)& aSurface, const Handle(IGESData_HArray1OfIGESEntity)& allModelCurves, const Handle(TColStd_HArray1OfInteger)& allSenses, const Handle(IGESBasic_HArray1OfHArray1OfIGESEntity)& allParameterCurves) ;
  
  //! returns type of bounded surface representation
  //! 0 = Boundary entities may only reference model space trimming
  //! curves. Associated surface representation may be parametric
  //! 1 = Boundary entities must reference model space curves and
  //! associated parameter space curve collections. Associated
  //! surface must be a parametric representation
  Standard_EXPORT   Standard_Integer BoundaryType()  const;
  
  //! returns preferred representation of trimming curves
  //! 0 = Unspecified
  //! 1 = Model space
  //! 2 = Parameter space
  //! 3 = Representations are of equal preference
  Standard_EXPORT   Standard_Integer PreferenceType()  const;
  
  //! returns the surface to be bounded
  Standard_EXPORT   Handle(IGESData_IGESEntity) Surface()  const;
  
  //! returns the number of model space curves
  Standard_EXPORT   Standard_Integer NbModelSpaceCurves()  const;
  
  //! returns Model Space Curve
  //! raises exception if Index <= 0 or Index > NbModelSpaceCurves()
  Standard_EXPORT   Handle(IGESData_IGESEntity) ModelSpaceCurve (const Standard_Integer Index)  const;
  
  //! returns the sense of a particular model space curve
  //! 1 = model curve direction does not need reversal
  //! 2 = model curve direction needs to be reversed
  //! raises exception if Index <= 0 or Index > NbModelSpaceCurves()
  Standard_EXPORT   Standard_Integer Sense (const Standard_Integer Index)  const;
  
  //! returns the number of parameter curves associated with one
  //! model space curve referred to by Index
  //! raises exception if Index <= 0 or Index > NbModelSpaceCurves()
  Standard_EXPORT   Standard_Integer NbParameterCurves (const Standard_Integer Index)  const;
  
  //! returns an array of parameter space curves associated with
  //! a model space curve referred to by the Index
  //! raises exception if Index <= 0 or Index > NbModelSpaceCurves()
  Standard_EXPORT   Handle(IGESData_HArray1OfIGESEntity) ParameterCurves (const Standard_Integer Index)  const;
  
  //! returns an individual parameter curve
  //! raises exception if Index or Num is out of range
  Standard_EXPORT   Handle(IGESData_IGESEntity) ParameterCurve (const Standard_Integer Index, const Standard_Integer Num)  const;




  DEFINE_STANDARD_RTTI(IGESGeom_Boundary)

protected:




private: 


  Standard_Integer theType;
  Standard_Integer thePreference;
  Handle(IGESData_IGESEntity) theSurface;
  Handle(IGESData_HArray1OfIGESEntity) theModelCurves;
  Handle(TColStd_HArray1OfInteger) theSenses;
  Handle(IGESBasic_HArray1OfHArray1OfIGESEntity) theParameterCurves;


};







#endif // _IGESGeom_Boundary_HeaderFile
// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AIS_EllipseRadiusDimension_HeaderFile
#define _AIS_EllipseRadiusDimension_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_AIS_EllipseRadiusDimension.hxx>

#include <gp_Elips.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_Geom_OffsetCurve.hxx>
#include <AIS_Relation.hxx>
#include <AIS_KindOfDimension.hxx>
#include <AIS_KindOfSurface.hxx>
#include <Handle_Geom_Surface.hxx>
class Geom_OffsetCurve;
class TopoDS_Shape;
class TCollection_ExtendedString;
class Geom_Surface;



//! Computes  geometry  (  basis  curve  and  plane  of  dimension)
//! for  input  shape  aShape  from  TopoDS
//! Root  class  for MinRadiusDimension  and  MaxRadiusDimension
class AIS_EllipseRadiusDimension : public AIS_Relation
{

public:

  
  Standard_EXPORT virtual   AIS_KindOfDimension KindOfDimension()  const;
  
  Standard_EXPORT virtual   Standard_Boolean IsMovable()  const;
  
  Standard_EXPORT   void ComputeGeometry() ;




  DEFINE_STANDARD_RTTI(AIS_EllipseRadiusDimension)

protected:

  
  Standard_EXPORT AIS_EllipseRadiusDimension(const TopoDS_Shape& aShape, const TCollection_ExtendedString& aText);

  gp_Elips myEllipse;
  Standard_Real myFirstPar;
  Standard_Real myLastPar;
  Standard_Boolean myIsAnArc;
  Handle(Geom_OffsetCurve) myOffsetCurve;
  Standard_Real myOffset;
  Standard_Boolean myIsOffset;


private: 

  
  Standard_EXPORT   void ComputeFaceGeometry() ;
  
  Standard_EXPORT   void ComputeCylFaceGeometry (const AIS_KindOfSurface aSurfType, const Handle(Geom_Surface)& aSurf, const Standard_Real Offset) ;
  
  Standard_EXPORT   void ComputePlanarFaceGeometry() ;
  
  Standard_EXPORT   void ComputeEdgeGeometry() ;



};







#endif // _AIS_EllipseRadiusDimension_HeaderFile
// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepToGeom_MakeCartesianPoint2d_HeaderFile
#define _StepToGeom_MakeCartesianPoint2d_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Boolean.hxx>
#include <Handle_StepGeom_CartesianPoint.hxx>
#include <Handle_Geom2d_CartesianPoint.hxx>
class StepGeom_CartesianPoint;
class Geom2d_CartesianPoint;


//! This class implements the mapping between classes
//! CartesianPoint from StepGeom which describes a point from
//! Prostep and CartesianPoint from Geom2d.
class StepToGeom_MakeCartesianPoint2d 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT static   Standard_Boolean Convert (const Handle(StepGeom_CartesianPoint)& SP, Handle(Geom2d_CartesianPoint)& CP) ;




protected:





private:





};







#endif // _StepToGeom_MakeCartesianPoint2d_HeaderFile

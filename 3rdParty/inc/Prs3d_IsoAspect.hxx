// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Prs3d_IsoAspect_HeaderFile
#define _Prs3d_IsoAspect_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_Prs3d_IsoAspect.hxx>

#include <Standard_Integer.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Standard_Real.hxx>
class Quantity_Color;


//! A framework to define the display attributes of isoparameters.
//! This framework can be used to modify the default
//! setting for isoparameters in AIS_Drawer.
class Prs3d_IsoAspect : public Prs3d_LineAspect
{

public:

  
  //! Constructs a framework to define display attributes of isoparameters.
  //! These include:
  //! -   the color attribute aColor
  //! -   the type of line aType
  //! -   the width value aWidth
  //! -   aNumber, the number of isoparameters to be   displayed.
  Standard_EXPORT Prs3d_IsoAspect(const Quantity_NameOfColor aColor, const Aspect_TypeOfLine aType, const Standard_Real aWidth, const Standard_Integer aNumber);
  
  Standard_EXPORT Prs3d_IsoAspect(const Quantity_Color& aColor, const Aspect_TypeOfLine aType, const Standard_Real aWidth, const Standard_Integer aNumber);
  
  //! defines the number of U or V isoparametric curves
  //! to be drawn for a single face.
  //! Default value: 10
  Standard_EXPORT   void SetNumber (const Standard_Integer aNumber) ;
  
  //! returns the number of U or V isoparametric curves drawn for a single face.
  Standard_EXPORT   Standard_Integer Number()  const;




  DEFINE_STANDARD_RTTI(Prs3d_IsoAspect)

protected:




private: 


  Standard_Integer myNumber;


};







#endif // _Prs3d_IsoAspect_HeaderFile

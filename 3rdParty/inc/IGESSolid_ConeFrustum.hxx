// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESSolid_ConeFrustum_HeaderFile
#define _IGESSolid_ConeFrustum_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_IGESSolid_ConeFrustum.hxx>

#include <Standard_Real.hxx>
#include <gp_XYZ.hxx>
#include <IGESData_IGESEntity.hxx>
class gp_XYZ;
class gp_Pnt;
class gp_Dir;


//! defines ConeFrustum, Type <156> Form Number <0>
//! in package IGESSolid
//! The Cone Frustum is defined by the center of the
//! larger circular face of the frustum, its radius, a unit
//! vector in the axis direction, a height in this direction
//! and a second circular face with radius which is lesser
//! than the first face.
class IGESSolid_ConeFrustum : public IGESData_IGESEntity
{

public:

  
  Standard_EXPORT IGESSolid_ConeFrustum();
  
  //! This method is used to set the fields of the class
  //! ConeFrustum
  //! - Ht     : the Height of cone
  //! - R1     : Radius of the larger face
  //! - R2     : Radius of the smaller face (default 0)
  //! - Center : Center of the larger face (default (0,0,0))
  //! - anAxis : Unit vector in axis direction (default (0,0,1))
  Standard_EXPORT   void Init (const Standard_Real Ht, const Standard_Real R1, const Standard_Real R2, const gp_XYZ& Center, const gp_XYZ& anAxis) ;
  
  //! returns the height of the cone frustum
  Standard_EXPORT   Standard_Real Height()  const;
  
  //! returns the radius of the larger face of the cone frustum
  Standard_EXPORT   Standard_Real LargerRadius()  const;
  
  //! returns the radius of the second face of the cone frustum
  Standard_EXPORT   Standard_Real SmallerRadius()  const;
  
  //! returns the center of the larger face of the cone frustum
  Standard_EXPORT   gp_Pnt FaceCenter()  const;
  
  //! returns the center of the larger face of the cone frustum
  //! after applying TransformationMatrix
  Standard_EXPORT   gp_Pnt TransformedFaceCenter()  const;
  
  //! returns the direction of the axis of the cone frustum
  Standard_EXPORT   gp_Dir Axis()  const;
  
  //! returns the direction of the axis of the cone frustum
  //! after applying TransformationMatrix
  Standard_EXPORT   gp_Dir TransformedAxis()  const;




  DEFINE_STANDARD_RTTI(IGESSolid_ConeFrustum)

protected:




private: 


  Standard_Real theHeight;
  Standard_Real theR1;
  Standard_Real theR2;
  gp_XYZ theFaceCenter;
  gp_XYZ theAxis;


};







#endif // _IGESSolid_ConeFrustum_HeaderFile
// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StlMesh_MeshTriangle_HeaderFile
#define _StlMesh_MeshTriangle_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StlMesh_MeshTriangle.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Real.hxx>
#include <MMgt_TShared.hxx>
class Standard_NegativeValue;


//! A  mesh triangle is defined with
//! three geometric vertices and an orientation
class StlMesh_MeshTriangle : public MMgt_TShared
{

public:

  
  //! empty constructor
  Standard_EXPORT StlMesh_MeshTriangle();
  
  //! create a triangle defined with the indexes of its three vertices
  //! and its orientation
  //! Raised if V1, V2 or V3 is lower than zero
  Standard_EXPORT StlMesh_MeshTriangle(const Standard_Integer V1, const Standard_Integer V2, const Standard_Integer V3, const Standard_Real Xn, const Standard_Real Yn, const Standard_Real Zn);
  
  //! get indexes of the three vertices (V1,V2,V3) and the orientation
  Standard_EXPORT   void GetVertexAndOrientation (Standard_Integer& V1, Standard_Integer& V2, Standard_Integer& V3, Standard_Real& Xn, Standard_Real& Yn, Standard_Real& Zn)  const;
  
  //! set indexes of the three vertices (V1,V2,V3) and the orientation
  //! Raised if V1, V2 or V3 is lower than zero
  Standard_EXPORT   void SetVertexAndOrientation (const Standard_Integer V1, const Standard_Integer V2, const Standard_Integer V3, const Standard_Real Xn, const Standard_Real Yn, const Standard_Real Zn) ;
  
  //! get indexes of the three vertices (V1,V2,V3)
  Standard_EXPORT   void GetVertex (Standard_Integer& V1, Standard_Integer& V2, Standard_Integer& V3)  const;
  
  //! set indexes of the three vertices (V1,V2,V3)
  //! Raised if V1, V2 or V3 is lower than zero
  Standard_EXPORT   void SetVertex (const Standard_Integer V1, const Standard_Integer V2, const Standard_Integer V3) ;




  DEFINE_STANDARD_RTTI(StlMesh_MeshTriangle)

protected:




private: 


  Standard_Integer MyV1;
  Standard_Integer MyV2;
  Standard_Integer MyV3;
  Standard_Real MyXn;
  Standard_Real MyYn;
  Standard_Real MyZn;


};







#endif // _StlMesh_MeshTriangle_HeaderFile

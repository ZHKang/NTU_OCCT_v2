// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _MgtBRep_TranslateTool1_HeaderFile
#define _MgtBRep_TranslateTool1_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_MgtBRep_TranslateTool1.hxx>

#include <MgtBRep_TriangleMode.hxx>
#include <MgtTopoDS_TranslateTool1.hxx>
#include <Handle_PGeom_Curve.hxx>
#include <Handle_Geom_Curve.hxx>
#include <Handle_PGeom2d_Curve.hxx>
#include <Handle_Geom2d_Curve.hxx>
#include <Handle_PGeom_Surface.hxx>
#include <Handle_Geom_Surface.hxx>
class Standard_TypeMismatch;
class PGeom_Curve;
class Geom_Curve;
class PTColStd_TransientPersistentMap;
class PTColStd_PersistentTransientMap;
class PGeom2d_Curve;
class Geom2d_Curve;
class PGeom_Surface;
class Geom_Surface;
class TopoDS_Shape;
class PTopoDS_Shape1;


//! The TranslateTool1 class is provided to support the
//! translation of BRep topological data structures.
//! Used to call the MgtTopoDS methods.
class MgtBRep_TranslateTool1 : public MgtTopoDS_TranslateTool1
{

public:

  
  //! Creates a new TranslateTool1
  Standard_EXPORT MgtBRep_TranslateTool1(const MgtBRep_TriangleMode aTriMode);
  
  Standard_EXPORT   void Add (TopoDS_Shape& S1, const TopoDS_Shape& S2)  const;
  
  Standard_EXPORT   void MakeVertex (TopoDS_Shape& S)  const;
  
  Standard_EXPORT   void MakeVertex (PTopoDS_Shape1& S)  const;
  
  Standard_EXPORT   void MakeEdge (TopoDS_Shape& S)  const;
  
  Standard_EXPORT   void MakeEdge (PTopoDS_Shape1& S)  const;
  
  Standard_EXPORT   void MakeWire (TopoDS_Shape& S)  const;
  
  Standard_EXPORT   void MakeWire (PTopoDS_Shape1& S)  const;
  
  Standard_EXPORT   void MakeFace (TopoDS_Shape& S)  const;
  
  Standard_EXPORT   void MakeFace (PTopoDS_Shape1& S)  const;
  
  Standard_EXPORT   void MakeShell (TopoDS_Shape& S)  const;
  
  Standard_EXPORT   void MakeShell (PTopoDS_Shape1& S)  const;
  
  Standard_EXPORT   void MakeSolid (TopoDS_Shape& S)  const;
  
  Standard_EXPORT   void MakeSolid (PTopoDS_Shape1& S)  const;
  
  Standard_EXPORT   void MakeCompSolid (TopoDS_Shape& S)  const;
  
  Standard_EXPORT   void MakeCompSolid (PTopoDS_Shape1& S)  const;
  
  Standard_EXPORT   void MakeCompound (TopoDS_Shape& S)  const;
  
  Standard_EXPORT   void MakeCompound (PTopoDS_Shape1& S)  const;
  
  Standard_EXPORT virtual   void UpdateVertex (const TopoDS_Shape& S1, PTopoDS_Shape1& S2, PTColStd_TransientPersistentMap& M)  const;
  
  Standard_EXPORT virtual   void UpdateVertex (const PTopoDS_Shape1& S1, TopoDS_Shape& S2, PTColStd_PersistentTransientMap& M)  const;
  
  Standard_EXPORT virtual   void UpdateEdge (const TopoDS_Shape& S1, PTopoDS_Shape1& S2, PTColStd_TransientPersistentMap& M)  const;
  
  Standard_EXPORT virtual   void UpdateEdge (const PTopoDS_Shape1& S1, TopoDS_Shape& S2, PTColStd_PersistentTransientMap& M)  const;
  
  Standard_EXPORT virtual   void UpdateFace (const TopoDS_Shape& S1, PTopoDS_Shape1& S2, PTColStd_TransientPersistentMap& M)  const;
  
  Standard_EXPORT virtual   void UpdateFace (const PTopoDS_Shape1& S1, TopoDS_Shape& S2, PTColStd_PersistentTransientMap& M)  const;




  DEFINE_STANDARD_RTTI(MgtBRep_TranslateTool1)

protected:

  
  //! Translates a Transient Curve onto a Persistent Curve
  Standard_EXPORT   Handle(PGeom_Curve) Translate (const Handle(Geom_Curve)& TC, PTColStd_TransientPersistentMap& M)  const;
  
  //! Translates a Persistent Curve onto a Transient Curve
  Standard_EXPORT   Handle(Geom_Curve) Translate (const Handle(PGeom_Curve)& PC, PTColStd_PersistentTransientMap& M)  const;
  
  //! Translates a Transient Curve2d onto a Persistent Curve
  Standard_EXPORT   Handle(PGeom2d_Curve) Translate (const Handle(Geom2d_Curve)& TC, PTColStd_TransientPersistentMap& M)  const;
  
  //! Translates a Persistent Curve2d onto a Transient Curve
  Standard_EXPORT   Handle(Geom2d_Curve) Translate (const Handle(PGeom2d_Curve)& PC, PTColStd_PersistentTransientMap& M)  const;
  
  //! Translates a Transient Surface onto a Persistent Curve
  Standard_EXPORT   Handle(PGeom_Surface) Translate (const Handle(Geom_Surface)& TS, PTColStd_TransientPersistentMap& M)  const;
  
  //! Translates a Persistent Surface onto a Transient Curve
  Standard_EXPORT   Handle(Geom_Surface) Translate (const Handle(PGeom_Surface)& PS, PTColStd_PersistentTransientMap& M)  const;



private: 


  MgtBRep_TriangleMode myTriangleMode;


};







#endif // _MgtBRep_TranslateTool1_HeaderFile
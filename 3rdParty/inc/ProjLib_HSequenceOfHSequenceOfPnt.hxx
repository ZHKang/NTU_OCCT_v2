// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ProjLib_HSequenceOfHSequenceOfPnt_HeaderFile
#define _ProjLib_HSequenceOfHSequenceOfPnt_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_ProjLib_HSequenceOfHSequenceOfPnt.hxx>

#include <ProjLib_SequenceOfHSequenceOfPnt.hxx>
#include <MMgt_TShared.hxx>
#include <Handle_TColgp_HSequenceOfPnt.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_NoSuchObject;
class Standard_OutOfRange;
class TColgp_HSequenceOfPnt;
class ProjLib_SequenceOfHSequenceOfPnt;



class ProjLib_HSequenceOfHSequenceOfPnt : public MMgt_TShared
{

public:

  
    ProjLib_HSequenceOfHSequenceOfPnt();
  
      Standard_Boolean IsEmpty()  const;
  
      Standard_Integer Length()  const;
  
  Standard_EXPORT   void Clear() ;
  
  Standard_EXPORT   void Append (const Handle(TColgp_HSequenceOfPnt)& anItem) ;
  
  Standard_EXPORT   void Append (const Handle(ProjLib_HSequenceOfHSequenceOfPnt)& aSequence) ;
  
  Standard_EXPORT   void Prepend (const Handle(TColgp_HSequenceOfPnt)& anItem) ;
  
  Standard_EXPORT   void Prepend (const Handle(ProjLib_HSequenceOfHSequenceOfPnt)& aSequence) ;
  
  Standard_EXPORT   void Reverse() ;
  
  Standard_EXPORT   void InsertBefore (const Standard_Integer anIndex, const Handle(TColgp_HSequenceOfPnt)& anItem) ;
  
  Standard_EXPORT   void InsertBefore (const Standard_Integer anIndex, const Handle(ProjLib_HSequenceOfHSequenceOfPnt)& aSequence) ;
  
  Standard_EXPORT   void InsertAfter (const Standard_Integer anIndex, const Handle(TColgp_HSequenceOfPnt)& anItem) ;
  
  Standard_EXPORT   void InsertAfter (const Standard_Integer anIndex, const Handle(ProjLib_HSequenceOfHSequenceOfPnt)& aSequence) ;
  
  Standard_EXPORT   void Exchange (const Standard_Integer anIndex, const Standard_Integer anOtherIndex) ;
  
  Standard_EXPORT   Handle(ProjLib_HSequenceOfHSequenceOfPnt) Split (const Standard_Integer anIndex) ;
  
  Standard_EXPORT   void SetValue (const Standard_Integer anIndex, const Handle(TColgp_HSequenceOfPnt)& anItem) ;
  
  Standard_EXPORT  const  Handle(TColgp_HSequenceOfPnt)& Value (const Standard_Integer anIndex)  const;
  
  Standard_EXPORT   Handle(TColgp_HSequenceOfPnt)& ChangeValue (const Standard_Integer anIndex) ;
  
  Standard_EXPORT   void Remove (const Standard_Integer anIndex) ;
  
  Standard_EXPORT   void Remove (const Standard_Integer fromIndex, const Standard_Integer toIndex) ;
  
     const  ProjLib_SequenceOfHSequenceOfPnt& Sequence()  const;
  
      ProjLib_SequenceOfHSequenceOfPnt& ChangeSequence() ;
  
  Standard_EXPORT   Handle(ProjLib_HSequenceOfHSequenceOfPnt) ShallowCopy()  const;




  DEFINE_STANDARD_RTTI(ProjLib_HSequenceOfHSequenceOfPnt)

protected:




private: 


  ProjLib_SequenceOfHSequenceOfPnt mySequence;


};

#define Item Handle(TColgp_HSequenceOfPnt)
#define Item_hxx <TColgp_HSequenceOfPnt.hxx>
#define TheSequence ProjLib_SequenceOfHSequenceOfPnt
#define TheSequence_hxx <ProjLib_SequenceOfHSequenceOfPnt.hxx>
#define TCollection_HSequence ProjLib_HSequenceOfHSequenceOfPnt
#define TCollection_HSequence_hxx <ProjLib_HSequenceOfHSequenceOfPnt.hxx>
#define Handle_TCollection_HSequence Handle_ProjLib_HSequenceOfHSequenceOfPnt
#define TCollection_HSequence_Type_() ProjLib_HSequenceOfHSequenceOfPnt_Type_()

#include <TCollection_HSequence.lxx>

#undef Item
#undef Item_hxx
#undef TheSequence
#undef TheSequence_hxx
#undef TCollection_HSequence
#undef TCollection_HSequence_hxx
#undef Handle_TCollection_HSequence
#undef TCollection_HSequence_Type_


inline Handle(ProjLib_HSequenceOfHSequenceOfPnt) ShallowCopy(const Handle(ProjLib_HSequenceOfHSequenceOfPnt)& me) {
 return me->ShallowCopy();
}



#endif // _ProjLib_HSequenceOfHSequenceOfPnt_HeaderFile

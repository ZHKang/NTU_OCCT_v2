// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PColgp_HSequenceOfPnt_HeaderFile
#define _PColgp_HSequenceOfPnt_HeaderFile

#include <Standard_Macro.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard.hxx>
#include <Handle_PColgp_HSequenceOfPnt.hxx>

#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
#include <gp_Pnt.hxx>
#include <Handle_PColgp_HSequenceOfPnt.hxx>
#include <Handle_PColgp_SeqNodeOfHSequenceOfPnt.hxx>
#include <Standard_Persistent.hxx>
class PColgp_SeqNodeOfHSequenceOfPnt;
class Standard_NoSuchObject;
class Standard_OutOfRange;
class PColgp_SeqExplorerOfHSequenceOfPnt;
class gp_Pnt;


class PColgp_HSequenceOfPnt : public Standard_Persistent
{

public:

  
  Standard_EXPORT PColgp_HSequenceOfPnt();
  
  Standard_EXPORT   Standard_Boolean IsEmpty()  const;
  
  Standard_EXPORT   Standard_Integer Length()  const;
  
  Standard_EXPORT   gp_Pnt First()  const;
  
  Standard_EXPORT   gp_Pnt Last()  const;
  
  Standard_EXPORT   void Clear() ;
  
  Standard_EXPORT   void Append (const gp_Pnt& T) ;
  
  Standard_EXPORT   void Append (const Handle(PColgp_HSequenceOfPnt)& S) ;
  
  Standard_EXPORT   void Prepend (const gp_Pnt& T) ;
  
  Standard_EXPORT   void Prepend (const Handle(PColgp_HSequenceOfPnt)& S) ;
  
  Standard_EXPORT   void Reverse() ;
  
  Standard_EXPORT   void InsertBefore (const Standard_Integer Index, const gp_Pnt& T) ;
  
  Standard_EXPORT   void InsertBefore (const Standard_Integer Index, const Handle(PColgp_HSequenceOfPnt)& S) ;
  
  Standard_EXPORT   void InsertAfter (const Standard_Integer Index, const gp_Pnt& T) ;
  
  Standard_EXPORT   void InsertAfter (const Standard_Integer Index, const Handle(PColgp_HSequenceOfPnt)& S) ;
  
  Standard_EXPORT   void Exchange (const Standard_Integer I, const Standard_Integer J) ;
  
  Standard_EXPORT   Handle(PColgp_HSequenceOfPnt) SubSequence (const Standard_Integer FromIndex, const Standard_Integer ToIndex)  const;
  
  Standard_EXPORT   Handle(PColgp_HSequenceOfPnt) Split (const Standard_Integer Index) ;
  
  Standard_EXPORT   void SetValue (const Standard_Integer Index, const gp_Pnt& T) ;
  
  Standard_EXPORT   gp_Pnt Value (const Standard_Integer Index)  const;
  
  Standard_EXPORT   Standard_Boolean Contains (const gp_Pnt& T)  const;
  
  Standard_EXPORT   Standard_Integer Location (const Standard_Integer N, const gp_Pnt& T, const Standard_Integer FromIndex, const Standard_Integer ToIndex)  const;
  
  Standard_EXPORT   Standard_Integer Location (const Standard_Integer N, const gp_Pnt& T)  const;
  
  Standard_EXPORT   void Remove (const Standard_Integer Index) ;
  
  Standard_EXPORT   void Remove (const Standard_Integer FromIndex, const Standard_Integer ToIndex) ;
  
  Standard_EXPORT   void Destroy() ;
~PColgp_HSequenceOfPnt()
{
  Destroy();
}
PColgp_HSequenceOfPnt(const Storage_stCONSTclCOM& a) : Standard_Persistent(a)
{
  
}
    Handle(PColgp_SeqNodeOfHSequenceOfPnt) _CSFDB_GetPColgp_HSequenceOfPntFirstItem() const { return FirstItem; }
    void _CSFDB_SetPColgp_HSequenceOfPntFirstItem(const Handle(PColgp_SeqNodeOfHSequenceOfPnt)& p) { FirstItem = p; }
    Handle(PColgp_SeqNodeOfHSequenceOfPnt) _CSFDB_GetPColgp_HSequenceOfPntLastItem() const { return LastItem; }
    void _CSFDB_SetPColgp_HSequenceOfPntLastItem(const Handle(PColgp_SeqNodeOfHSequenceOfPnt)& p) { LastItem = p; }
    Standard_Integer _CSFDB_GetPColgp_HSequenceOfPntSize() const { return Size; }
    void _CSFDB_SetPColgp_HSequenceOfPntSize(const Standard_Integer p) { Size = p; }

friend class PColgp_SeqExplorerOfHSequenceOfPnt;


  DEFINE_STANDARD_RTTI(PColgp_HSequenceOfPnt)

protected:




private: 

  
  Standard_EXPORT   Handle(PColgp_SeqNodeOfHSequenceOfPnt) GetFirst()  const;
  
  Standard_EXPORT   Handle(PColgp_SeqNodeOfHSequenceOfPnt) GetLast()  const;

  Handle(PColgp_SeqNodeOfHSequenceOfPnt) FirstItem;
  Handle(PColgp_SeqNodeOfHSequenceOfPnt) LastItem;
  Standard_Integer Size;


};







#endif // _PColgp_HSequenceOfPnt_HeaderFile

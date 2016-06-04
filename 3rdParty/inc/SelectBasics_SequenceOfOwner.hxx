// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _SelectBasics_SequenceOfOwner_HeaderFile
#define _SelectBasics_SequenceOfOwner_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TCollection_BaseSequence.hxx>
#include <Handle_SelectBasics_EntityOwner.hxx>
#include <Handle_SelectBasics_SequenceNodeOfSequenceOfOwner.hxx>
#include <Standard_Integer.hxx>
class Standard_NoSuchObject;
class Standard_OutOfRange;
class SelectBasics_EntityOwner;
class SelectBasics_SequenceNodeOfSequenceOfOwner;



class SelectBasics_SequenceOfOwner  : public TCollection_BaseSequence
{
public:

  DEFINE_STANDARD_ALLOC

  
    SelectBasics_SequenceOfOwner();
  
  Standard_EXPORT SelectBasics_SequenceOfOwner(const SelectBasics_SequenceOfOwner& Other);
  
  Standard_EXPORT   void Clear() ;
~SelectBasics_SequenceOfOwner()
{
  Clear();
}
  
  Standard_EXPORT  const  SelectBasics_SequenceOfOwner& Assign (const SelectBasics_SequenceOfOwner& Other) ;
 const  SelectBasics_SequenceOfOwner& operator = (const SelectBasics_SequenceOfOwner& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT   void Append (const Handle(SelectBasics_EntityOwner)& T) ;
  
      void Append (SelectBasics_SequenceOfOwner& S) ;
  
  Standard_EXPORT   void Prepend (const Handle(SelectBasics_EntityOwner)& T) ;
  
      void Prepend (SelectBasics_SequenceOfOwner& S) ;
  
      void InsertBefore (const Standard_Integer Index, const Handle(SelectBasics_EntityOwner)& T) ;
  
      void InsertBefore (const Standard_Integer Index, SelectBasics_SequenceOfOwner& S) ;
  
  Standard_EXPORT   void InsertAfter (const Standard_Integer Index, const Handle(SelectBasics_EntityOwner)& T) ;
  
      void InsertAfter (const Standard_Integer Index, SelectBasics_SequenceOfOwner& S) ;
  
  Standard_EXPORT  const  Handle(SelectBasics_EntityOwner)& First()  const;
  
  Standard_EXPORT  const  Handle(SelectBasics_EntityOwner)& Last()  const;
  
      void Split (const Standard_Integer Index, SelectBasics_SequenceOfOwner& Sub) ;
  
  Standard_EXPORT  const  Handle(SelectBasics_EntityOwner)& Value (const Standard_Integer Index)  const;
 const  Handle(SelectBasics_EntityOwner)& operator() (const Standard_Integer Index)  const
{
  return Value(Index);
}
  
  Standard_EXPORT   void SetValue (const Standard_Integer Index, const Handle(SelectBasics_EntityOwner)& I) ;
  
  Standard_EXPORT   Handle(SelectBasics_EntityOwner)& ChangeValue (const Standard_Integer Index) ;
  Handle(SelectBasics_EntityOwner)& operator() (const Standard_Integer Index) 
{
  return ChangeValue(Index);
}
  
  Standard_EXPORT   void Remove (const Standard_Integer Index) ;
  
  Standard_EXPORT   void Remove (const Standard_Integer FromIndex, const Standard_Integer ToIndex) ;




protected:





private:





};

#define SeqItem Handle(SelectBasics_EntityOwner)
#define SeqItem_hxx <SelectBasics_EntityOwner.hxx>
#define TCollection_SequenceNode SelectBasics_SequenceNodeOfSequenceOfOwner
#define TCollection_SequenceNode_hxx <SelectBasics_SequenceNodeOfSequenceOfOwner.hxx>
#define Handle_TCollection_SequenceNode Handle_SelectBasics_SequenceNodeOfSequenceOfOwner
#define TCollection_SequenceNode_Type_() SelectBasics_SequenceNodeOfSequenceOfOwner_Type_()
#define TCollection_Sequence SelectBasics_SequenceOfOwner
#define TCollection_Sequence_hxx <SelectBasics_SequenceOfOwner.hxx>

#include <TCollection_Sequence.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _SelectBasics_SequenceOfOwner_HeaderFile
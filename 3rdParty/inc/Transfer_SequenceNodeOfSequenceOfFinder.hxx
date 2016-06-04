// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Transfer_SequenceNodeOfSequenceOfFinder_HeaderFile
#define _Transfer_SequenceNodeOfSequenceOfFinder_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_Transfer_SequenceNodeOfSequenceOfFinder.hxx>

#include <Handle_Transfer_Finder.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_SeqNodePtr.hxx>
class Transfer_Finder;
class Transfer_SequenceOfFinder;



class Transfer_SequenceNodeOfSequenceOfFinder : public TCollection_SeqNode
{

public:

  
    Transfer_SequenceNodeOfSequenceOfFinder(const Handle(Transfer_Finder)& I, const TCollection_SeqNodePtr& n, const TCollection_SeqNodePtr& p);
  
      Handle(Transfer_Finder)& Value()  const;




  DEFINE_STANDARD_RTTI(Transfer_SequenceNodeOfSequenceOfFinder)

protected:




private: 


  Handle(Transfer_Finder) myValue;


};

#define SeqItem Handle(Transfer_Finder)
#define SeqItem_hxx <Transfer_Finder.hxx>
#define TCollection_SequenceNode Transfer_SequenceNodeOfSequenceOfFinder
#define TCollection_SequenceNode_hxx <Transfer_SequenceNodeOfSequenceOfFinder.hxx>
#define Handle_TCollection_SequenceNode Handle_Transfer_SequenceNodeOfSequenceOfFinder
#define TCollection_SequenceNode_Type_() Transfer_SequenceNodeOfSequenceOfFinder_Type_()
#define TCollection_Sequence Transfer_SequenceOfFinder
#define TCollection_Sequence_hxx <Transfer_SequenceOfFinder.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _Transfer_SequenceNodeOfSequenceOfFinder_HeaderFile

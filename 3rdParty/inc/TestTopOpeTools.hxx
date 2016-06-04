// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TestTopOpeTools_HeaderFile
#define _TestTopOpeTools_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Draw_Interpretor.hxx>
class TestTopOpeTools_Mesure;
class TestTopOpeTools_Array1OfMesure;
class TestTopOpeTools_HArray1OfMesure;



//! Provide Trace control on packages involved in
//! topological operations kernel, from Draw command interpretor.
//!
//! They may be used by users of topological operation kernel, such as :
//!
//! * topological operation performer,
//! * hidden line removal performer,
//! * fillet, chamfer performer
//!
//! Trace  control   consists  in  management  of
//! control functions,  activating/desactivating  execution  of
//! instructions considered as purely PASSIVE code,
//! performing dumps, prints, and drawing of internal objects
//! dealed by some topological operation packages.
//!
//! All of the Trace controls in top.ope. kernel
//! are enclosed by the C conditional compilation statements :
//! #ifdef OCCT_DEBUG  ...  #endif
//!
//! The "Traced" packages of topological operation kernel are :
//! - TopBuild
//! - TopOpeBRepTool
//! - TopOpeBRepDS
//!
//! How to use the Trace :
//! ----------------------
//!
//! In a Test.cxx program using  the Draw command interpretor, dealing
//! a set of commands theCommands (Draw_CommandManager theCommands)  :
//!
//! TestTopOpeTools::TraceCommands();
//!
//! Compile your Test.cxx, run and then, under the command manager prompt :
//!
//! Trace : prints the list of the Trace flags available on top.ope. kernel
//! Trace <flag> : activates Trace code of <flag>
//! Trace <flag> <1 | 0> : activates/desactivates Trace code of <flag>
//! Trace <1 | 0> : activates/desactivates all Trace code of top.ope. kernel
//!
//! How to add Traces :
//! -------------------
//!
//! It it possible to add your own "Traced" portions of code in your code.
//! In your test program, simply add :
//!
//! #include <TestTopOpeTools_AddTrace.hxx>
//!
//! and see the file TestTopOpeTools_Trace.hxx for explanations.
class TestTopOpeTools 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Defines all topological operation test commands
  Standard_EXPORT static   void AllCommands (Draw_Interpretor& I) ;
  
  //! Defines the dump commands on
  //! topological operation packages.
  Standard_EXPORT static   void TraceCommands (Draw_Interpretor& I) ;
  
  //! Defines auxiliary commands
  Standard_EXPORT static   void OtherCommands (Draw_Interpretor& I) ;




protected:





private:




friend class TestTopOpeTools_Mesure;
friend class TestTopOpeTools_Array1OfMesure;
friend class TestTopOpeTools_HArray1OfMesure;

};







#endif // _TestTopOpeTools_HeaderFile
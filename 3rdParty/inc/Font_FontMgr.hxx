// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Font_FontMgr_HeaderFile
#define _Font_FontMgr_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_Font_FontMgr.hxx>

#include <Font_NListOfSystemFont.hxx>
#include <MMgt_TShared.hxx>
#include <Handle_Font_SystemFont.hxx>
#include <Handle_TCollection_HAsciiString.hxx>
#include <Font_FontAspect.hxx>
#include <Standard_Integer.hxx>
#include <Standard_CString.hxx>
#include <Standard_Boolean.hxx>
class TColStd_SequenceOfHAsciiString;
class Font_SystemFont;
class TCollection_HAsciiString;


//! Collects and provides information about available fonts in system.
class Font_FontMgr : public MMgt_TShared
{

public:

  
  Standard_EXPORT static   Handle(Font_FontMgr) GetInstance() ;
  
  Standard_EXPORT  const  Font_NListOfSystemFont& GetAvailableFonts()  const;
  
  //! Returns sequence of available fonts names
  Standard_EXPORT   void GetAvailableFontsNames (TColStd_SequenceOfHAsciiString& theFontsNames)  const;
  
  //! Returns font that match given parameters.
  //! If theFontName is empty string returned font can have any FontName.
  //! If theFontAspect is Font_FA_Undefined returned font can have any FontAspect.
  //! If theFontSize is "-1" returned font can have any FontSize.
  Standard_EXPORT   Handle(Font_SystemFont) GetFont (const Handle(TCollection_HAsciiString)& theFontName, const Font_FontAspect theFontAspect, const Standard_Integer theFontSize)  const;
  
  //! Tries to find font by given parameters.
  //! If the specified font is not found tries to use font names mapping.
  //! If the requested family name not found -> search for any font family
  //! with given aspect and height. If the font is still not found, returns
  //! any font available in the system. Returns NULL in case when the fonts
  //! are not found in the system.
  Standard_EXPORT   Handle(Font_SystemFont) FindFont (const Handle(TCollection_HAsciiString)& theFontName, const Font_FontAspect theFontAspect, const Standard_Integer theFontSize)  const;
  
  //! Read font file and retrieve information from it.
  Standard_EXPORT   Handle(Font_SystemFont) CheckFont (const Standard_CString theFontPath)  const;
  
  //! Register new font.
  //! If there is existing entity with the same name and properties but different path
  //! then font will will be overridden or ignored depending on theToOverride flag.
  Standard_EXPORT   Standard_Boolean RegisterFont (const Handle(Font_SystemFont)& theFont, const Standard_Boolean theToOverride) ;




  DEFINE_STANDARD_RTTI(Font_FontMgr)

protected:




private: 

  
  //! Creates empty font object
  Standard_EXPORT Font_FontMgr();
  
  //! Collects available fonts paths.
  Standard_EXPORT   void InitFontDataBase() ;

  Font_NListOfSystemFont myListOfFonts;


};







#endif // _Font_FontMgr_HeaderFile

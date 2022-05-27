///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MenuBar
///////////////////////////////////////////////////////////////////////////////
class MenuBar : public wxMenuBar
{
	private:

	protected:
		wxMenu* m_menu;

		// Virtual event handlers, override them in your derived class
		virtual void m_open_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_save_click( wxCommandEvent& event ) { event.Skip(); }


	public:

		MenuBar( long style = 0 );
		~MenuBar();

};


///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "menu_bar.hpp"

///////////////////////////////////////////////////////////////////////////

MenuBar::MenuBar( long style ) : wxMenuBar( style )
{
	m_menu = new wxMenu();
	wxMenuItem* m_open;
	m_open = new wxMenuItem( m_menu, wxID_ANY, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu->Append( m_open );

	m_menu->AppendSeparator();

	wxMenuItem* m_save;
	m_save = new wxMenuItem( m_menu, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu->Append( m_save );

	Append( m_menu, wxT("File") );


	// Connect Events
	m_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MenuBar::m_open_click ), this, m_open->GetId());
	m_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MenuBar::m_save_click ), this, m_save->GetId());
}

MenuBar::~MenuBar()
{
	// Disconnect Events

}

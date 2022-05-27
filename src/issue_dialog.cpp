///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "issue_dialog.hpp"

///////////////////////////////////////////////////////////////////////////

IssueDialog::IssueDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -300,75 ), wxDefaultSize );

	wxBoxSizer* issue_dialog_sizer;
	issue_dialog_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* borrower_email_sizer;
	borrower_email_sizer = new wxBoxSizer( wxHORIZONTAL );

	borrower_email_text = new wxStaticText( this, wxID_ANY, wxT("Email"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	borrower_email_text->Wrap( -1 );
	borrower_email_sizer->Add( borrower_email_text, 0, wxALIGN_CENTER|wxALL, 5 );

	borrower_email_input = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	borrower_email_sizer->Add( borrower_email_input, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	issue_button = new wxButton( this, wxID_ANY, wxT("Issue"), wxDefaultPosition, wxDefaultSize, 0 );
	borrower_email_sizer->Add( issue_button, 0, wxALIGN_CENTER|wxALL, 5 );


	issue_dialog_sizer->Add( borrower_email_sizer, 1, wxEXPAND, 5 );


	this->SetSizer( issue_dialog_sizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	borrower_email_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( IssueDialog::check_borrow_email ), NULL, this );
	issue_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IssueDialog::issue_button_click ), NULL, this );
}

IssueDialog::~IssueDialog()
{
	// Disconnect Events
	borrower_email_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( IssueDialog::check_borrow_email ), NULL, this );
	issue_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IssueDialog::issue_button_click ), NULL, this );

}

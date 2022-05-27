///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "main_panel.hpp"

///////////////////////////////////////////////////////////////////////////

MainPanel::MainPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	this->SetMinSize( wxSize( 700,550 ) );

	wxBoxSizer* main_panel_sizer;
	main_panel_sizer = new wxBoxSizer( wxVERTICAL );

	main_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	books_page = new wxPanel( main_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* books_page_top_sizer;
	books_page_top_sizer = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* book_details_static_box;
	book_details_static_box = new wxStaticBoxSizer( new wxStaticBox( books_page, wxID_ANY, wxT("Details") ), wxVERTICAL );

	wxBoxSizer* book_details_top_sizer;
	book_details_top_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* book_details_left_sizer;
	book_details_left_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* isbn_number_sizer;
	isbn_number_sizer = new wxBoxSizer( wxHORIZONTAL );

	isbn_number_text = new wxStaticText( book_details_static_box->GetStaticBox(), wxID_ANY, wxT("ISBN Number"), wxDefaultPosition, wxSize( 72,-1 ), 0 );
	isbn_number_text->Wrap( -1 );
	isbn_number_text->SetMinSize( wxSize( 72,-1 ) );

	isbn_number_sizer->Add( isbn_number_text, 0, wxALIGN_CENTER|wxALL, 5 );

	isbn_number_input = new wxTextCtrl( book_details_static_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	isbn_number_sizer->Add( isbn_number_input, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	book_details_left_sizer->Add( isbn_number_sizer, 0, wxEXPAND, 5 );

	wxBoxSizer* book_name_sizer;
	book_name_sizer = new wxBoxSizer( wxHORIZONTAL );

	book_name_text = new wxStaticText( book_details_static_box->GetStaticBox(), wxID_ANY, wxT("Name"), wxDefaultPosition, wxSize( 72,-1 ), 0 );
	book_name_text->Wrap( -1 );
	book_name_text->SetMinSize( wxSize( 72,-1 ) );

	book_name_sizer->Add( book_name_text, 0, wxALIGN_CENTER|wxALL, 5 );

	book_name_input = new wxTextCtrl( book_details_static_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	book_name_sizer->Add( book_name_input, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	book_details_left_sizer->Add( book_name_sizer, 0, wxEXPAND, 5 );

	wxBoxSizer* genre_sizer;
	genre_sizer = new wxBoxSizer( wxHORIZONTAL );

	genre_text = new wxStaticText( book_details_static_box->GetStaticBox(), wxID_ANY, wxT("Genre"), wxDefaultPosition, wxSize( 72,-1 ), 0 );
	genre_text->Wrap( -1 );
	genre_text->SetMinSize( wxSize( 72,-1 ) );

	genre_sizer->Add( genre_text, 0, wxALIGN_CENTER|wxALL, 5 );

	genre_input = new wxTextCtrl( book_details_static_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	genre_sizer->Add( genre_input, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	book_details_left_sizer->Add( genre_sizer, 0, wxEXPAND, 5 );

	wxBoxSizer* publisher_sizer;
	publisher_sizer = new wxBoxSizer( wxHORIZONTAL );

	publisher_text = new wxStaticText( book_details_static_box->GetStaticBox(), wxID_ANY, wxT("Publisher"), wxDefaultPosition, wxSize( 72,-1 ), 0 );
	publisher_text->Wrap( -1 );
	publisher_text->SetMinSize( wxSize( 72,-1 ) );

	publisher_sizer->Add( publisher_text, 0, wxALIGN_CENTER|wxALL, 5 );

	publisher_input = new wxTextCtrl( book_details_static_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	publisher_sizer->Add( publisher_input, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	book_details_left_sizer->Add( publisher_sizer, 0, wxEXPAND, 5 );


	book_details_top_sizer->Add( book_details_left_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* book_details_right_sizer;
	book_details_right_sizer = new wxBoxSizer( wxHORIZONTAL );

	authors_emails_text = new wxStaticText( book_details_static_box->GetStaticBox(), wxID_ANY, wxT("Authors'\nEmails"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	authors_emails_text->Wrap( -1 );
	book_details_right_sizer->Add( authors_emails_text, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxBoxSizer* authors_emails_list_sizer;
	authors_emails_list_sizer = new wxBoxSizer( wxVERTICAL );

	book_author_email_input = new wxTextCtrl( book_details_static_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	authors_emails_list_sizer->Add( book_author_email_input, 0, wxALL|wxEXPAND, 5 );

	authors_emails_list = new wxListBox( book_details_static_box->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 );
	authors_emails_list_sizer->Add( authors_emails_list, 1, wxALL|wxEXPAND, 5 );


	book_details_right_sizer->Add( authors_emails_list_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* authors_emails_buttons_sizer;
	authors_emails_buttons_sizer = new wxBoxSizer( wxVERTICAL );

	book_author_email_add = new wxButton( book_details_static_box->GetStaticBox(), wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	book_author_email_add->Enable( false );

	authors_emails_buttons_sizer->Add( book_author_email_add, 0, wxALIGN_CENTER|wxALL, 5 );

	book_author_email_remove = new wxButton( book_details_static_box->GetStaticBox(), wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	book_author_email_remove->Enable( false );

	authors_emails_buttons_sizer->Add( book_author_email_remove, 0, wxALIGN_CENTER|wxALL, 5 );

	authors_emails_clear = new wxButton( book_details_static_box->GetStaticBox(), wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	authors_emails_clear->Enable( false );

	authors_emails_buttons_sizer->Add( authors_emails_clear, 0, wxALIGN_CENTER|wxALL, 5 );


	book_details_right_sizer->Add( authors_emails_buttons_sizer, 0, wxEXPAND, 5 );


	book_details_top_sizer->Add( book_details_right_sizer, 1, wxEXPAND, 5 );


	book_details_static_box->Add( book_details_top_sizer, 1, wxEXPAND, 5 );


	books_page_top_sizer->Add( book_details_static_box, 2, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* books_list_sizer;
	books_list_sizer = new wxStaticBoxSizer( new wxStaticBox( books_page, wxID_ANY, wxT("List") ), wxVERTICAL );

	books_list = new wxListCtrl( books_list_sizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	books_list_sizer->Add( books_list, 1, wxALL|wxEXPAND, 5 );


	books_page_top_sizer->Add( books_list_sizer, 4, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* book_actions_top_sizer;
	book_actions_top_sizer = new wxStaticBoxSizer( new wxStaticBox( books_page, wxID_ANY, wxT("Actions") ), wxHORIZONTAL );

	wxBoxSizer* actions_left_sizer;
	actions_left_sizer = new wxBoxSizer( wxHORIZONTAL );

	add_book_button = new wxButton( book_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	add_book_button->Enable( false );

	actions_left_sizer->Add( add_book_button, 0, wxALIGN_CENTER|wxALL, 5 );

	update_book_button = new wxButton( book_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	update_book_button->Enable( false );

	actions_left_sizer->Add( update_book_button, 0, wxALIGN_CENTER|wxBOTTOM|wxRIGHT|wxTOP, 5 );

	remove_book_button = new wxButton( book_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	remove_book_button->Enable( false );

	actions_left_sizer->Add( remove_book_button, 0, wxALIGN_CENTER|wxBOTTOM|wxRIGHT|wxTOP, 5 );

	issue_book_button = new wxButton( book_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Issue"), wxDefaultPosition, wxDefaultSize, 0 );
	issue_book_button->Enable( false );

	actions_left_sizer->Add( issue_book_button, 0, wxALIGN_CENTER|wxBOTTOM|wxRIGHT|wxTOP, 5 );


	book_actions_top_sizer->Add( actions_left_sizer, 10, wxEXPAND, 5 );

	wxBoxSizer* actions_right_sizer;
	actions_right_sizer = new wxBoxSizer( wxHORIZONTAL );

	available_quantity_text = new wxStaticText( book_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Available Quantity"), wxDefaultPosition, wxDefaultSize, 0 );
	available_quantity_text->Wrap( -1 );
	actions_right_sizer->Add( available_quantity_text, 0, wxALIGN_CENTER|wxALL, 5 );

	available_quantity_decrease_button = new wxButton( book_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Dec"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	available_quantity_decrease_button->Enable( false );
	available_quantity_decrease_button->SetMinSize( wxSize( 50,-1 ) );

	actions_right_sizer->Add( available_quantity_decrease_button, 0, wxALIGN_CENTER|wxALL, 5 );

	available_quantity_increase_button = new wxButton( book_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Inc"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	available_quantity_increase_button->Enable( false );
	available_quantity_increase_button->SetMinSize( wxSize( 50,-1 ) );

	actions_right_sizer->Add( available_quantity_increase_button, 0, wxALIGN_CENTER|wxBOTTOM|wxRIGHT|wxTOP, 5 );


	book_actions_top_sizer->Add( actions_right_sizer, 1, wxEXPAND, 5 );


	books_page_top_sizer->Add( book_actions_top_sizer, 0, wxALL|wxEXPAND, 5 );


	books_page->SetSizer( books_page_top_sizer );
	books_page->Layout();
	books_page_top_sizer->Fit( books_page );
	main_notebook->AddPage( books_page, wxT("Books"), false );
	authors_page = new wxPanel( main_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* authors_page_top_sizer;
	authors_page_top_sizer = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* authors_details_static_box;
	authors_details_static_box = new wxStaticBoxSizer( new wxStaticBox( authors_page, wxID_ANY, wxT("Details") ), wxVERTICAL );

	wxBoxSizer* authors_details_top_sizer;
	authors_details_top_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* authors_details_left_sizer;
	authors_details_left_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* author_name_sizer;
	author_name_sizer = new wxBoxSizer( wxHORIZONTAL );

	author_name_text = new wxStaticText( authors_details_static_box->GetStaticBox(), wxID_ANY, wxT("Name"), wxDefaultPosition, wxSize( 32,-1 ), 0 );
	author_name_text->Wrap( -1 );
	author_name_text->SetMinSize( wxSize( 32,-1 ) );

	author_name_sizer->Add( author_name_text, 0, wxALIGN_CENTER|wxALL, 5 );

	author_name_input = new wxTextCtrl( authors_details_static_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	author_name_sizer->Add( author_name_input, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	authors_details_left_sizer->Add( author_name_sizer, 0, wxEXPAND, 5 );

	wxBoxSizer* author_email_sizer;
	author_email_sizer = new wxBoxSizer( wxHORIZONTAL );

	author_email_text = new wxStaticText( authors_details_static_box->GetStaticBox(), wxID_ANY, wxT("Email"), wxDefaultPosition, wxSize( 32,-1 ), 0 );
	author_email_text->Wrap( -1 );
	author_email_text->SetMinSize( wxSize( 32,-1 ) );

	author_email_sizer->Add( author_email_text, 0, wxALIGN_CENTER|wxALL, 5 );

	author_email_input = new wxTextCtrl( authors_details_static_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	author_email_sizer->Add( author_email_input, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	authors_details_left_sizer->Add( author_email_sizer, 0, wxEXPAND, 5 );


	authors_details_top_sizer->Add( authors_details_left_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* author_details_right_sizer;
	author_details_right_sizer = new wxBoxSizer( wxHORIZONTAL );

	author_isbn_numbers_text = new wxStaticText( authors_details_static_box->GetStaticBox(), wxID_ANY, wxT("ISBN\nNumbers"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	author_isbn_numbers_text->Wrap( -1 );
	author_details_right_sizer->Add( author_isbn_numbers_text, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	author_isbn_numbers_list = new wxListBox( authors_details_static_box->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 );
	author_isbn_numbers_list->Enable( false );

	author_details_right_sizer->Add( author_isbn_numbers_list, 1, wxALL|wxEXPAND, 5 );


	authors_details_top_sizer->Add( author_details_right_sizer, 1, wxEXPAND, 5 );


	authors_details_static_box->Add( authors_details_top_sizer, 1, wxEXPAND, 5 );


	authors_page_top_sizer->Add( authors_details_static_box, 2, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* authors_list_sizer;
	authors_list_sizer = new wxStaticBoxSizer( new wxStaticBox( authors_page, wxID_ANY, wxT("List") ), wxVERTICAL );

	authors_list = new wxListCtrl( authors_list_sizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	authors_list_sizer->Add( authors_list, 1, wxALL|wxEXPAND, 5 );


	authors_page_top_sizer->Add( authors_list_sizer, 4, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* author_actions_top_sizer;
	author_actions_top_sizer = new wxStaticBoxSizer( new wxStaticBox( authors_page, wxID_ANY, wxT("Actions") ), wxHORIZONTAL );

	wxBoxSizer* author_actions_left_sizer;
	author_actions_left_sizer = new wxBoxSizer( wxHORIZONTAL );

	add_author_button = new wxButton( author_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	add_author_button->Enable( false );

	author_actions_left_sizer->Add( add_author_button, 0, wxALIGN_CENTER|wxALL, 5 );

	update_author_button = new wxButton( author_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	update_author_button->Enable( false );

	author_actions_left_sizer->Add( update_author_button, 0, wxALIGN_CENTER|wxBOTTOM|wxRIGHT|wxTOP, 5 );

	remove_author_button = new wxButton( author_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	remove_author_button->Enable( false );

	author_actions_left_sizer->Add( remove_author_button, 0, wxALIGN_CENTER|wxBOTTOM|wxRIGHT|wxTOP, 5 );


	author_actions_top_sizer->Add( author_actions_left_sizer, 10, wxEXPAND, 5 );


	authors_page_top_sizer->Add( author_actions_top_sizer, 0, wxALL|wxEXPAND, 5 );


	authors_page->SetSizer( authors_page_top_sizer );
	authors_page->Layout();
	authors_page_top_sizer->Fit( authors_page );
	main_notebook->AddPage( authors_page, wxT("Authors"), true );
	borrowers_page = new wxPanel( main_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* borrowers_page_top_sizer;
	borrowers_page_top_sizer = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* borrowers_details_static_box;
	borrowers_details_static_box = new wxStaticBoxSizer( new wxStaticBox( borrowers_page, wxID_ANY, wxT("Details") ), wxVERTICAL );

	wxBoxSizer* borrowers_details_top_sizer;
	borrowers_details_top_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* borrowers_details_left_sizer;
	borrowers_details_left_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* borrower_name_sizer;
	borrower_name_sizer = new wxBoxSizer( wxHORIZONTAL );

	borrower_name_text = new wxStaticText( borrowers_details_static_box->GetStaticBox(), wxID_ANY, wxT("Name"), wxDefaultPosition, wxSize( 32,-1 ), 0 );
	borrower_name_text->Wrap( -1 );
	borrower_name_text->SetMinSize( wxSize( 32,-1 ) );

	borrower_name_sizer->Add( borrower_name_text, 0, wxALIGN_CENTER|wxALL, 5 );

	borrower_name_input = new wxTextCtrl( borrowers_details_static_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	borrower_name_sizer->Add( borrower_name_input, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	borrowers_details_left_sizer->Add( borrower_name_sizer, 0, wxEXPAND, 5 );

	wxBoxSizer* borrower_email_sizer;
	borrower_email_sizer = new wxBoxSizer( wxHORIZONTAL );

	borrower_email_text = new wxStaticText( borrowers_details_static_box->GetStaticBox(), wxID_ANY, wxT("Email"), wxDefaultPosition, wxSize( 32,-1 ), 0 );
	borrower_email_text->Wrap( -1 );
	borrower_email_text->SetMinSize( wxSize( 32,-1 ) );

	borrower_email_sizer->Add( borrower_email_text, 0, wxALIGN_CENTER|wxALL, 5 );

	borrower_email_input = new wxTextCtrl( borrowers_details_static_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	borrower_email_sizer->Add( borrower_email_input, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	borrowers_details_left_sizer->Add( borrower_email_sizer, 0, wxEXPAND, 5 );


	borrowers_details_top_sizer->Add( borrowers_details_left_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* borrower_details_right_sizer;
	borrower_details_right_sizer = new wxBoxSizer( wxHORIZONTAL );

	borrower_isbn_numbers_text = new wxStaticText( borrowers_details_static_box->GetStaticBox(), wxID_ANY, wxT("ISBN\nNumbers"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	borrower_isbn_numbers_text->Wrap( -1 );
	borrower_details_right_sizer->Add( borrower_isbn_numbers_text, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	borrower_isbn_numbers_list = new wxListBox( borrowers_details_static_box->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 );
	borrower_details_right_sizer->Add( borrower_isbn_numbers_list, 1, wxALL|wxEXPAND, 5 );


	borrowers_details_top_sizer->Add( borrower_details_right_sizer, 1, wxEXPAND, 5 );


	borrowers_details_static_box->Add( borrowers_details_top_sizer, 1, wxEXPAND, 5 );


	borrowers_page_top_sizer->Add( borrowers_details_static_box, 2, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* borrowers_list_sizer;
	borrowers_list_sizer = new wxStaticBoxSizer( new wxStaticBox( borrowers_page, wxID_ANY, wxT("List") ), wxVERTICAL );

	borrowers_list = new wxListCtrl( borrowers_list_sizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	borrowers_list_sizer->Add( borrowers_list, 1, wxALL|wxEXPAND, 5 );


	borrowers_page_top_sizer->Add( borrowers_list_sizer, 4, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* borrower_actions_top_sizer;
	borrower_actions_top_sizer = new wxStaticBoxSizer( new wxStaticBox( borrowers_page, wxID_ANY, wxT("Actions") ), wxHORIZONTAL );

	wxBoxSizer* borrower_actions_left_sizer;
	borrower_actions_left_sizer = new wxBoxSizer( wxHORIZONTAL );

	add_borrower_button = new wxButton( borrower_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	add_borrower_button->Enable( false );

	borrower_actions_left_sizer->Add( add_borrower_button, 0, wxALIGN_CENTER|wxALL, 5 );

	update_borrower_button = new wxButton( borrower_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	update_borrower_button->Enable( false );

	borrower_actions_left_sizer->Add( update_borrower_button, 0, wxALIGN_CENTER|wxBOTTOM|wxRIGHT|wxTOP, 5 );

	remove_borrower_button = new wxButton( borrower_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	remove_borrower_button->Enable( false );

	borrower_actions_left_sizer->Add( remove_borrower_button, 0, wxALIGN_CENTER|wxBOTTOM|wxRIGHT|wxTOP, 5 );

	return_book_button = new wxButton( borrower_actions_top_sizer->GetStaticBox(), wxID_ANY, wxT("Return"), wxDefaultPosition, wxDefaultSize, 0 );
	return_book_button->Enable( false );

	borrower_actions_left_sizer->Add( return_book_button, 0, wxBOTTOM|wxRIGHT|wxTOP, 5 );


	borrower_actions_top_sizer->Add( borrower_actions_left_sizer, 10, wxEXPAND, 5 );


	borrowers_page_top_sizer->Add( borrower_actions_top_sizer, 0, wxALL|wxEXPAND, 5 );


	borrowers_page->SetSizer( borrowers_page_top_sizer );
	borrowers_page->Layout();
	borrowers_page_top_sizer->Fit( borrowers_page );
	main_notebook->AddPage( borrowers_page, wxT("Borrowers"), false );

	main_panel_sizer->Add( main_notebook, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( main_panel_sizer );
	this->Layout();

	// Connect Events
	isbn_number_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_book_details ), NULL, this );
	book_name_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_book_details ), NULL, this );
	genre_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_book_details ), NULL, this );
	publisher_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_book_details ), NULL, this );
	book_author_email_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::authors_email_input_on_text ), NULL, this );
	authors_emails_list->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainPanel::authors_emails_list_on ), NULL, this );
	book_author_email_add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::book_author_email_add_click ), NULL, this );
	book_author_email_remove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::book_author_email_remove_click ), NULL, this );
	authors_emails_clear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::authors_emails_clear_click ), NULL, this );
	books_list->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( MainPanel::books_list_item_deselected ), NULL, this );
	books_list->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( MainPanel::books_list_item_selected ), NULL, this );
	add_book_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::add_book_button_click ), NULL, this );
	update_book_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::update_book_button_click ), NULL, this );
	remove_book_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::remove_book_button_click ), NULL, this );
	issue_book_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::issue_book_button_click ), NULL, this );
	available_quantity_decrease_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::available_quantity_decrease_button_click ), NULL, this );
	available_quantity_increase_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::available_quantity_increase_button_click ), NULL, this );
	author_name_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_author_details ), NULL, this );
	author_email_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_author_details ), NULL, this );
	authors_list->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( MainPanel::authors_list_item_deselected ), NULL, this );
	authors_list->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( MainPanel::authors_list_item_selected ), NULL, this );
	add_author_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::add_author_button_click ), NULL, this );
	update_author_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::update_author_button_click ), NULL, this );
	remove_author_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::remove_author_button_click ), NULL, this );
	borrower_name_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_borrower_details ), NULL, this );
	borrower_email_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_borrower_details ), NULL, this );
	borrower_isbn_numbers_list->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainPanel::borrower_isbn_numbers_list_on ), NULL, this );
	borrowers_list->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( MainPanel::borrowers_list_item_deselected ), NULL, this );
	borrowers_list->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( MainPanel::borrowers_list_item_selected ), NULL, this );
	add_borrower_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::add_borrower_button_click ), NULL, this );
	update_borrower_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::update_borrower_button_click ), NULL, this );
	remove_borrower_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::remove_borrower_button_click ), NULL, this );
	return_book_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::return_book_button_click ), NULL, this );
}

MainPanel::~MainPanel()
{
	// Disconnect Events
	isbn_number_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_book_details ), NULL, this );
	book_name_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_book_details ), NULL, this );
	genre_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_book_details ), NULL, this );
	publisher_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_book_details ), NULL, this );
	book_author_email_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::authors_email_input_on_text ), NULL, this );
	authors_emails_list->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainPanel::authors_emails_list_on ), NULL, this );
	book_author_email_add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::book_author_email_add_click ), NULL, this );
	book_author_email_remove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::book_author_email_remove_click ), NULL, this );
	authors_emails_clear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::authors_emails_clear_click ), NULL, this );
	books_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( MainPanel::books_list_item_deselected ), NULL, this );
	books_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( MainPanel::books_list_item_selected ), NULL, this );
	add_book_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::add_book_button_click ), NULL, this );
	update_book_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::update_book_button_click ), NULL, this );
	remove_book_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::remove_book_button_click ), NULL, this );
	issue_book_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::issue_book_button_click ), NULL, this );
	available_quantity_decrease_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::available_quantity_decrease_button_click ), NULL, this );
	available_quantity_increase_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::available_quantity_increase_button_click ), NULL, this );
	author_name_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_author_details ), NULL, this );
	author_email_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_author_details ), NULL, this );
	authors_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( MainPanel::authors_list_item_deselected ), NULL, this );
	authors_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( MainPanel::authors_list_item_selected ), NULL, this );
	add_author_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::add_author_button_click ), NULL, this );
	update_author_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::update_author_button_click ), NULL, this );
	remove_author_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::remove_author_button_click ), NULL, this );
	borrower_name_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_borrower_details ), NULL, this );
	borrower_email_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainPanel::check_borrower_details ), NULL, this );
	borrower_isbn_numbers_list->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainPanel::borrower_isbn_numbers_list_on ), NULL, this );
	borrowers_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( MainPanel::borrowers_list_item_deselected ), NULL, this );
	borrowers_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( MainPanel::borrowers_list_item_selected ), NULL, this );
	add_borrower_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::add_borrower_button_click ), NULL, this );
	update_borrower_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::update_borrower_button_click ), NULL, this );
	remove_borrower_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::remove_borrower_button_click ), NULL, this );
	return_book_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainPanel::return_book_button_click ), NULL, this );

}

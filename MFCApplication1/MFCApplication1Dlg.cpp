
// MFCApplication1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg dialog
CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, _messageEdit(_T(""))
	, _ip(_T(""))
	, _port(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//link up message data
	DDX_Text(pDX, Message_Edit, _messageEdit);
	DDX_Text(pDX, IP_Edit, _ip);
	DDX_Text(pDX, Port_Edit, _port);
	DDX_Control(pDX, Message_List, _messageListControl);
}

//mfc message mapping (event to eventhandler hookups)
BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)

	//messages implemented by default template
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	//messages from ui controls
	ON_BN_CLICKED(Send_Button, &CMFCApplication1Dlg::OnSendClicked)
	ON_BN_CLICKED(Connect_Button, &CMFCApplication1Dlg::OnConnectClicked)

	//messages from clientsocketcontroller class
	ON_MESSAGE(WM_CLIENTSOCKETCNTROLLER_ONCONNECT, OnClientSocketControllerDisconnect)
	ON_MESSAGE(WM_CLIENTSOCKETCNTROLLER_ONCONNECT, OnClientSocketControllerReceive)

END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	_clientController.Hwnd = m_hWnd;

	UpdateMessageList(_T("Welcome Client, no connection currently established."));

	//set bold title fonts
	CFont m_font;
	m_font.CreateFont(10, 0, 0, 0, FW_BOLD, 0, 1, 0, 0, 0, 0, 0, 0, _T("Arial"));
	GetDlgItem(Message_Window_Title)->SetFont(&m_font);
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Respond to a message send button clicked event from the ui
void CMFCApplication1Dlg::OnSendClicked()
{
	
	//verify the connection prior to making a send attempt
	if (!_clientController.IsConnected) {
		UpdateMessageList(_T("Connection must be made prior to sending..."));
		return;
	}

	//send attempt
	
	//convert CString from UI into a format acceptable by CAsyncSocket.Send(), in this case a const char*
	CT2A stringConverter(_messageEdit);
	char* convertedTextData = stringConverter;

	//_clientController.Send(convertedTextData, (int)strlen(convertedTextData));
	_clientController.Send(CT2A(_messageEdit), strlen(CT2A(_messageEdit)));

	UpdateMessageList(_T("Me: ") + _messageEdit);

	return;

}

//Respond to a connect button clicked event from the ui
void CMFCApplication1Dlg::OnConnectClicked()
{
	
	//don't allow double connection
	if (_clientController.IsConnected) {
		UpdateMessageList(_T("Connection already made..."));
		return;
	}

	//
	if (_clientController.Create())
	{
		CString thing = _T("Bruh");
		thing = thing + _T("Bruh");

		UpdateMessageList(_T("Bruh") + _T("Bruh"));

		// Initiate a connection to the device
		m_MySocket.Connect(AddressToConnectTo, PortToConnectTo);

		//keep track of connection
		_clientController.IsConnected = true;

		return;

	}
	else
	{

		UpdateMessageList(_T("Socket creation failed"));

		return;

	}

}

//Respond to a message receive event from the clientsocketcontroller class
LRESULT CMFCApplication1Dlg::OnClientSocketControllerReceive(WPARAM, LPARAM)
{



	return 0;

}

//Respond to a disconnect event from the clientsocketcontroller class
LRESULT CMFCApplication1Dlg::OnClientSocketControllerDisconnect(WPARAM, LPARAM)
{



	return 0;

}

//add a string of text to the 
void CMFCApplication1Dlg::UpdateMessageList(CString textToAdd) {

	//add new text to the list (will go to the bottom)
	_messageListControl.AddString(textToAdd);

	//push the new message up to the top of the list so old messages dissappear progressively
	_messageListControl.SetTopIndex(_messageListControl.GetCount() - 1);

	return;

}

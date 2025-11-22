
// MFCApplication1Dlg.h : header file
//

#pragma once

#include "SocketController.h"

// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
	public:

		// Construction
		CMFCApplication1Dlg(CWnd* pParent = nullptr);	// standard constructor

		//afx messages from UI controls
		afx_msg void OnOpenClicked();
		afx_msg void OnSendClicked();

		//methods
		void UpdateMessageList(CString messageToAdd);

		// Dialog Data
		#ifdef AFX_DESIGN_TIME
			enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
		#endif

	protected:

		HICON m_hIcon;

		virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

		// Generated message map functions
		virtual BOOL OnInitDialog();
		afx_msg void OnPaint();
		afx_msg HCURSOR OnQueryDragIcon();

		//event (message) handlers for the SocketController class to send to
		afx_msg LRESULT OnSocketControllerDisconnect(WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnSocketControllerReceive(WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnSocketControllerAccept(WPARAM wParam, LPARAM lParam);

		DECLARE_MESSAGE_MAP()

	private:

		//UI controls
		CString _messageEdit;
		CString _ip;
		CString _port;
		CListBox _messageListControl;

		//client socket class
		SocketController _clientController;
		SocketController _listenerController;

		

};

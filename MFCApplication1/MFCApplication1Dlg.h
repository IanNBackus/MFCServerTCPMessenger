
// MFCApplication1Dlg.h : header file
//

#pragma once

#include "ClientSocketController.h"

// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
	public:

		// Construction
		CMFCApplication1Dlg(CWnd* pParent = nullptr);	// standard constructor

		//afx messages from UI controls
		afx_msg void OnConnectClicked();
		afx_msg void OnSendClicked();

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

		//event handlers for the clientsocketcontroller class to send to
		afx_msg LRESULT OnSocketControllerConnect(WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnSocketControllerReceive(WPARAM wParam, LPARAM lParam);

		DECLARE_MESSAGE_MAP()

	private:

		//UI controls
		CString _messageEdit;
		CString _ip;
		CString _port;
		CListBox _messageListControl;

		//client socket class
		ClientSocketController _clientController;

};

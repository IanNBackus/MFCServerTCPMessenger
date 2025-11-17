#pragma once
#include <afxsock.h>

//define messages particular to this class so our dialog can hook up to them
#define WM_CLIENTSOCKETCNTROLLER_ONACCEPT	(WM_USER + 1)
#define WM_CLIENTSOCKETCNTROLLER_ONCONNECT	(WM_USER + 2)
#define WM_CLIENTSOCKETCNTROLLER_ONRECEIVE	(WM_USER + 3)
#define WM_CLIENTSOCKETCNTROLLER_ONCLOSE	(WM_USER + 4)

class ClientSocketController : public CAsyncSocket
{

	public:

		//constructor/destructor
		ClientSocketController();
		virtual ~ClientSocketController();

		//variables
		HWND Hwnd;
		bool IsConnected;

		//methods
		virtual void OnAccept(int nErrorCode);
		virtual void OnConnect(int nErrorCode);
		virtual void OnReceive(int nErrorCode);
		virtual void OnClose(int nErrorCode);

};


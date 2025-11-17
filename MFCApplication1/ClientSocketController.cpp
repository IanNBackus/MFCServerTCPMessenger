#include "pch.h"
#include "ClientSocketController.h"


ClientSocketController::ClientSocketController()
{
	TRACE("\nIn parameterless Constructor for ClientSocketController\n");

	//we'll manipulate these in the dialog class
	Hwnd = nullptr;
	IsConnected = false;
}

ClientSocketController::~ClientSocketController()
{
	//worlds emptiest destructor
	TRACE("\nDestructing ClientSocketController\n");
}


void ClientSocketController::OnAccept(int nErrorCode)
{

	//check if the window reference is acceptable
	if (::IsWindow(Hwnd))
	{
		//send message (event) to the window
		::PostMessage(Hwnd, WM_CLIENTSOCKETCNTROLLER_ONACCEPT, (WPARAM)nErrorCode, 0);
	}

	CAsyncSocket::OnAccept(nErrorCode);

}


void ClientSocketController::OnConnect(int nErrorCode)
{

	//check if the window reference is acceptable
	if (::IsWindow(Hwnd))
	{
		//send message (event) to the window
		::PostMessage(Hwnd, WM_CLIENTSOCKETCNTROLLER_ONCONNECT, (WPARAM)nErrorCode, 0);
	}

	CAsyncSocket::OnConnect(nErrorCode);

}


void ClientSocketController::OnReceive(int nErrorCode)
{

	//check if the window reference is acceptable
	if (::IsWindow(Hwnd))
	{
		//send message (event) to the window
		::PostMessage(Hwnd, WM_CLIENTSOCKETCNTROLLER_ONRECEIVE, (WPARAM)nErrorCode, 0);
	}

	CAsyncSocket::OnReceive(nErrorCode);

}


void ClientSocketController::OnClose(int nErrorCode)
{

	//check if the window reference is acceptable
	if (::IsWindow(Hwnd))
	{
		//send message (event) to the window
		::PostMessage(Hwnd, WM_CLIENTSOCKETCNTROLLER_ONCLOSE, (WPARAM)nErrorCode, 0);
	}

	CAsyncSocket::OnClose(nErrorCode);

}




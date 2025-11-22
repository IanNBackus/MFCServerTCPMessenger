#include "pch.h"
#include "SocketController.h"


SocketController::SocketController()
{
	TRACE("\nIn parameterless Constructor for SocketController\n");

	//we'll manipulate these in the dialog class
	Hwnd = nullptr;
	IsConnected = false;
	IsListening = false;
}

SocketController::~SocketController()
{
	//worlds emptiest destructor
	TRACE("\nDestructing SocketController\n");
}


void SocketController::OnAccept(int nErrorCode)
{

	//check if the window reference is acceptable
	if (::IsWindow(Hwnd))
	{
		//send message (event) to the window
		::PostMessage(Hwnd, WM_SOCKETCONTROLLER_ONACCEPT, (WPARAM)nErrorCode, 0);
	}

	CAsyncSocket::OnAccept(nErrorCode);

}


void SocketController::OnConnect(int nErrorCode)
{

	//check if the window reference is acceptable
	if (::IsWindow(Hwnd))
	{
		//send message (event) to the window
		::PostMessage(Hwnd, WM_SOCKETCONTROLLER_ONCONNECT, (WPARAM)nErrorCode, 0);
	}

	CAsyncSocket::OnConnect(nErrorCode);

}


void SocketController::OnReceive(int nErrorCode)
{

	//check if the window reference is acceptable
	if (::IsWindow(Hwnd))
	{
		//send message (event) to the window
		::PostMessage(Hwnd, WM_SOCKETCONTROLLER_ONRECEIVE, (WPARAM)nErrorCode, 0);
	}

	CAsyncSocket::OnReceive(nErrorCode);

}


void SocketController::OnClose(int nErrorCode)
{

	//check if the window reference is acceptable
	if (::IsWindow(Hwnd))
	{
		//send message (event) to the window
		::PostMessage(Hwnd, WM_SOCKETCONTROLLER_ONCLOSE, (WPARAM)nErrorCode, 0);
	}

	CAsyncSocket::OnClose(nErrorCode);

}
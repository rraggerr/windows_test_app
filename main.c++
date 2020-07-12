#include "main.h++"

LRESULT __stdcall wnd_proc( HWND _wnd, UINT _msg, WPARAM _wparam, LPARAM _lparam )
{
	if ( _msg == WM_DESTROY )
	{
		PostQuitMessage( 0 );
		return 0;
	};
	
	return DefWindowProc( _wnd, _msg, _wparam, _lparam );
};

int main( )
{
	WNDCLASSEXA _wndclassex;
	
	_wndclassex.cbSize = sizeof( WNDCLASSEXA );
	_wndclassex.style = CS_CLASSDC;
	_wndclassex.lpfnWndProc = wnd_proc;
	_wndclassex.cbClsExtra = 0;
	_wndclassex.cbWndExtra = 0;
	_wndclassex.hInstance = GetModuleHandleA( nullptr );
	_wndclassex.hIcon = nullptr;
	_wndclassex.hCursor = nullptr;
	_wndclassex.hbrBackground = nullptr;
	_wndclassex.lpszMenuName = "windows app menu name";
	_wndclassex.lpszClassName = "windows app class name";
	_wndclassex.hIconSm = nullptr;
	
	RegisterClassExA( &_wndclassex );
	
	HWND _hwnd = CreateWindowA( _wndclassex.lpszClassName, "windows app", WS_OVERLAPPEDWINDOW, 0, 0, 1280, 720, nullptr, nullptr, _wndclassex
			.hInstance, nullptr );
	
	ShowWindow( _hwnd, SW_SHOWDEFAULT );
	UpdateWindow( _hwnd );
	
	MSG msg;
	memset( &msg, 0, sizeof( MSG ) );
	
	
	while ( msg.message != WM_QUIT )
	{
		if ( PeekMessageA( &msg, nullptr, 0u, 0u, PM_REMOVE ) )
		{
			TranslateMessage( &msg );
			DispatchMessageA( &msg );
			continue;
		};
	};
	
	
	DestroyWindow( _hwnd );
	UnregisterClassA( _wndclassex.lpszClassName, _wndclassex.hInstance );
};

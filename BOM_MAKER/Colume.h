#pragma once
namespace BOM {

	struct Pos
	{
		int posX;
		int posY;
	};

	class Colume
	{
		HWND parentHwnd, hwnd;
		HFONT hFont;

		int id;
		int width;
		bool readonly;
		WNDPROC lpEditWndProc;

		DWORD style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER;


	public:
		static int temp_id;

		explicit Colume(
			HWND parentHwnd,
			int width,
			bool readonly = false,
			HFONT hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Consolas"))
			);

		inline int GetID() { return id; }
		inline int GetID() const { return id; }

		inline int GetWidth() { return width; }
		inline int GetWidth() const { return width; }

		inline HWND GetHwnd() { return hwnd; }
		inline HWND GetHwnd() const { return hwnd; }

		inline bool DrawColume(HINSTANCE hInstance, HWND hwnd, Pos pos, int height) {
			if (this->hwnd = CreateWindowEx(
				0, _T("edit"), _T(""), (this->readonly ? style |= ES_READONLY : style), pos.posX, pos.posY, width, height, hwnd, (HMENU)id, hInstance, 0
			)) {
				SendMessage(this->hwnd, WM_SETFONT, (WPARAM)(this->hFont), TRUE);
				return true;
			}

			return false;
		}

	
		class ColumeBuilder
		{
		public:
			static std::shared_ptr<Colume> makeDefaultColume(HWND parentHwnd, int width);
			static std::shared_ptr<Colume> makeOtherColume(HWND parentHwnd, int width, HFONT hFont);
		};



	};
}


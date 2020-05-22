#include"ProcMem.h"
#include"csgo.hpp"
#include"iostream"



using namespace hazedumper;
using namespace netvars;
using namespace signatures;


ProcMem Pamiec;
ProcMem* wsk = &Pamiec;





void ProcMem::BUNNY()
{
	char NazwaProgramu[11]{ "csgo.exe" };
	char DLL[20]{ "client_panorama.dll" };
	wsk->Process(NazwaProgramu);
	DWORD PamiecModul{ wsk->Module(DLL) };

	while (true)
	{
		if (GetAsyncKeyState(0x20))
		{
			DWORD jednostka1{ wsk->Read<DWORD>(DWORD(PamiecModul) + DWORD(dwLocalPlayer)) };
			DWORD FLAGA{ wsk->Read<DWORD>(jednostka1 + m_fFlags) };

			if (static_cast<int>(FLAGA) == 257)
			{
				wsk->Write(PamiecModul + dwForceJump, 6);
			}
		}
		wsk->RadarHack();
	}
	
	
}
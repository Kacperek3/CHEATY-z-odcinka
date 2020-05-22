#include "ProcMem.h"
#include "csgo.hpp"



ProcMem Pamiec1;
ProcMem* wsk1 = &Pamiec1;



void ProcMem::RadarHack()
{

	char NazwaProgramu[11]{ "csgo.exe" };
	char DLL[20]{ "client_panorama.dll" };

	
	wsk1->Process(NazwaProgramu);
	DWORD PamiecModul{ wsk1->Module(DLL) };


	for (char i = 0; i < 5; i++)
	{
		DWORD jednostka{ wsk1->Read<DWORD>(PamiecModul + hazedumper::signatures::dwEntityList + i * VK_SHIFT) };
		wsk1->Write<DWORD>(jednostka + hazedumper::netvars::m_bSpotted, true);
	}
	

}
/*
Syn's AyyWare Framework 2015
*/

#include "ESP.h"
#include "Interfaces.h"
#include "RenderManager.h"
#include "GlovManager.h"
int fgdgdfgdfgfghtrddgvterdf[512]{ 22315,7796,12712,10228,18428,5217,7094,29789,19378,111778,31171,26062,13481,6366,4915,1631880,3265,290312397,5163,24771,28816,2403,20044,9240,22643,84,6046,19917,31004,24657,11448,5086,2246,29380,4197,10856,1994,28601,24539,25362,29044,2687,32048,30070,11614,21449,13296,19360,28863,31775,6314,9509,9153,2066,29861,19912,20518,3471,20352,18343,31938,19944,31552,27687,5330,26085,23815,16867,2168,26826,14885,7431,4558,12568,28494,26128,3122,22741,30393,1193,19555,19452,23820,31996,18343,1938,28700,180,32286,17052,23104,31289,8249,6195,26190,9099,3902,4360,24739,18296,30400,29196,17191,2037,16889,31650,4951,29351,6338,3732,16790,30544,5845,19158,31555,12485,28891,32323,9344,3391,30151,23635,17347,17883,3722,16362,31948,31129,19144,19395,22226,31528,30768,12096,3560,23126,2260,21783,15106,19460,29754,32115,26609,28554,261,25326,25444,21858,7406,13705,12974,4345,27783,21348,20911,6765,11848,32075,31082,527,32468,6588,10207,19709,14272,18029,32543,26515,15598,8429,10224,7108,17217,22651,6404,30802,29792,21560,17622,11162,23685,10090,23723,5439,6420,17880,3744,9419,23952,29561,11277,2952,23467,14578,19758,23165,21908,6899,14281,14999,25550,31695,6260,31743,3480,5866,19895,5132,14944,22876,9739,23054,14452,19919,9609,22378,15632,4767,13289,29159,14284,23123,2563,18803,29918,7271,16407,2638,2892,16005,8894,22893,7279,2622,18378,24757,3830,24746,1958,554,30752,31379,27242,1075,19821,20990,21266,3547,4969,30147,7533,17140,26377,17889,714,2427,29131,20223,1825,28975,22225,17256,2239,31706,13981,19612,15775,11830,1541,17618,18547,23652,2809,12734,31173,15671,28648,1487,31749,8928,18771,12859,30436,5512,8471,24521,29283,22156,1907,15951,28393,16373,22921,5749,11095,13495,29140,28302,19861,208,5214,9436,2006,20117,11599,16648,14331,13642,19482,17810,6545,27643,21241,25663,10204,9365,19587,29493,23234,22227,23096,26385,9922,18356,21992,2174,730,29826,1639,17678,19298,345,14393,31540,3713,9335,10853,10318,26679,24590,10189,15641,2673,16864,9406,749,27899,30025,28312,1729,26675,32413,5067,30400,9879,11596,32281,16417,30891,9425,15917,17272,12002,1804,31278,6199,13249,22468,21950,869,31279,9268,2814,31411,12037,7454,23711,25824,8950,21242,7041,3472,1513,32676,23769,19652,28045,16760,21660,24884,9820,27202,12193,17254,8672,25684,3638,869,18353,3206,20267,5431,8074,27443,3217,17407,29599,6422,18362,2424,20651,6456,7467,9649,2383,12444,15758,12093,10802,11625,10921,29256,807,29832,23815,4077,29841,18326,22739,19120,3816,22842,7471,5743,975,1610,28164,6836,29459,6362,22820,21622,31164,19235,4233,3364,19735,2544,14870,28994,9925,24311,22834,6727,25051,23777,4624,11008,3628,31906,20332,11272,16450,32009,31375,30575,31751,1723,8673,773,17046,8922,15401,4439,21572,22066,30859,14338,25599,20450,17108,27296,3455,26511,9194,12271,8,744,13459,9964,29752,17155,3207,30319,18796,11547,5171,31921,20626,6424,4379,18012,26637,14097,11947,1003,8910,18394,17921,2985,25685,23052 };

void CEsp::Init()
{
	BombCarrier = nullptr;
}

// Yeah dude we're defo gunna do some sick moves for the esp yeah
void CEsp::Move(CUserCmd *pCmd,bool &bSendPacket) 
{

}

// Main ESP Drawing loop
void CEsp::Draw()
{
	IClientEntity *pLocal = hackManager.pLocal();

	if (Menu::Window.MiscTab.OtherSpectators.GetState())
	{
		SpecList();
	}

	// Loop through all active entitys
	for (int i = 0; i < Interfaces::EntList->GetHighestEntityIndex(); i++)
	{
		// Get the entity
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
		player_info_t pinfo;

		// The entity isn't some laggy peice of shit or something
		if (pEntity &&  pEntity != pLocal && !pEntity->IsDormant())
		{
			


			// Is it a player?!
			if (Menu::Window.VisualsTab.FiltersPlayers.GetState() && Interfaces::Engine->GetPlayerInfo(i, &pinfo) && pEntity->IsAlive())
			{
				DrawPlayer(pEntity, pinfo);
			}

			// ~ Other ESP's here (items and shit) ~ //
			ClientClass* cClass = (ClientClass*)pEntity->GetClientClass();

			// Dropped weapons
			if (Menu::Window.VisualsTab.FiltersWeapons.GetState() && cClass->m_ClassID != (int)CSGOClassID::CBaseWeaponWorldModel && ((strstr(cClass->m_pNetworkName, "Weapon") || cClass->m_ClassID == (int)CSGOClassID::CDEagle || cClass->m_ClassID == (int)CSGOClassID::CAK47)))
			{
				DrawDrop(pEntity, cClass);
			}

			// If entity is the bomb
			if (Menu::Window.VisualsTab.FiltersC4.GetState())
			{
				if (cClass->m_ClassID == (int)CSGOClassID::CPlantedC4)
					DrawBombPlanted(pEntity, cClass);

				if (cClass->m_ClassID == (int)CSGOClassID::CC4)
					DrawBomb(pEntity, cClass);
			}
			CUserCmd* cmdlist = *(CUserCmd**)((DWORD)Interfaces::pInput + 0xEC);
			CUserCmd* pCmd = cmdlist;
			if (Menu::Window.VisualsTab.OptionsLBY.GetState() && Interfaces::Engine->IsInGame());
			{
				DrawLBY(pEntity, pCmd);
			}

			// If entity is a chicken
			if (Menu::Window.VisualsTab.FiltersChickens.GetState())
			{
				if (cClass->m_ClassID == (int)CSGOClassID::CChicken)
					DrawChicken(pEntity, cClass);
			}
			if (Menu::Window.VisualsTab.Grenades.GetState())
				DrawDrop(pEntity, cClass);

		}
	}

	// Anti Flash
	// pAntiFlash
	if (Menu::Window.VisualsTab.OtherNoFlash.GetState())
	{
		DWORD m_flFlashMaxAlpha = NetVar.GetNetVar(0xFE79FB98);
		*(float*)((DWORD)pLocal + m_flFlashMaxAlpha) = 0;
	}

}
void CEsp::DrawLBY(IClientEntity* pEntity, CUserCmd* pCmd)
{
	IClientEntity *pLocal = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());

	if (Menu::Window.VisualsTab.OptionsLBY.GetState())
	{
		int i = 0; i < Interfaces::EntList->GetHighestEntityIndex(); ++i;
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);

		static bool isMoving;
		float PlayerIsMoving = abs(pEntity->GetVelocity().Length());
		if (PlayerIsMoving > 0.1) isMoving = true;
		else if (PlayerIsMoving <= 0.1) isMoving = false;


		//bool isinrange = false;
		//if (pCmd->viewangles.y - pLocal->GetLowerBodyYaw() >= -35 && pCmd->viewangles.y - pLocal->GetLowerBodyYaw() <= 35)
		if (pLocal->GetVelocity().Length() <= 0.1)
		{
			Render::Text(10, 990, Color(0, 255, 0, 255), Render::Fonts::LBY, "LBY");
		}
		else if (pLocal->GetVelocity().Length() > 0.1)
		{
			Render::Text(10, 990, Color(255, 0, 0, 255), Render::Fonts::LBY, "LBY");
		}
		//isinrange = true;

		//if (isinrange)
	}
}
void DrawOutlinedCircleGranade(int x, int y, int r, Color col)
{
	Interfaces::Surface->DrawSetColor(col);
	Interfaces::Surface->DrawOutlinedCircle(x, y, r, 1);
}
void CEsp::HealthBarNew(IClientEntity* pEntity, int x, int y, int height)
{
	{

		float flBoxes = std::ceil(pEntity->GetHealth() / 10.f);
		float flX = x - 7 - height / 4.f; float flY = y - 1;
		float flHeight = height / 10.f;
		float flMultiplier = 12 / 360.f; flMultiplier *= flBoxes - 1;
		Color ColHealth = Color::FromHSB(flMultiplier, 1, 1);

		Render::DrawRect1(flX, flY, 4, height + 2, Color(80, 80, 80, 125));
		Render::DrawOutlinedRect(flX, flY, 4, height + 2, Color::Black());
		Render::DrawRect1(flX + 1, flY, 2, flHeight * flBoxes + 1, ColHealth);

		for (int i = 0; i < 10; i++)
			Render::DrawLine(flX, flY + i * flHeight, flX + 4, flY + i * flHeight, Color::Black());
	}
}
void CEsp::DrawGrenades(IClientEntity* pEntity)
{


	Vector vGrenadePos2D = Vector(0.f, 0.f, 0.f);
	Vector vGrenadePos3D = Vector(0.f, 0.f, 0.f);
	float fGrenadeModelSize = 0.0f;
	Color colGrenadeColor = Color(0, 0, 0, 0);
	const model_t *model = pEntity->GetModel();

	if (pEntity->GetClientClass())
	{
		if (model)
		{
			studiohdr_t* hdr = Interfaces::ModelInfo->GetStudiomodel(model);
			if (hdr)
			{
				std::string hdrName = hdr->name;
				if (hdrName.find("thrown") != std::string::npos)
				{
					vGrenadePos3D = pEntity->GetOrigin();
					fGrenadeModelSize = hdr->hull_max.DistTo(hdr->hull_min);

					if (!Render::WorldToScreen(vGrenadePos3D, vGrenadePos2D))
						return;

					if (hdrName.find("flash") != std::string::npos)
					{
						//Warning color
						colGrenadeColor = Color(0, 0, 200, 255);
					}
					else if (hdrName.find("incendiarygrenade") != std::string::npos || hdrName.find("molotov") != std::string::npos || hdrName.find("fraggrenade") != std::string::npos)
					{
						//Dangerous color
						colGrenadeColor = Color(200, 0, 0, 255);
					}

					else if (hdrName.find("smoke") != std::string::npos || hdrName.find("decoy") != std::string::npos)
					{
						//Peaceful color
						colGrenadeColor = Color(0, 200, 0, 255);
					}
					DrawOutlinedCircleGranade(static_cast<int>(vGrenadePos2D.x), static_cast<int>(vGrenadePos2D.y), static_cast<int>(fGrenadeModelSize), colGrenadeColor);
				}
			}
		}
	}
}
// Spectator List
void CEsp::SpecList()
{
	IClientEntity *pLocal = hackManager.pLocal();

	RECT scrn = Render::GetViewport();
	int ayy = 0;

	// Loop through all active entitys
	for (int i = 0; i < Interfaces::EntList->GetHighestEntityIndex(); i++)
	{
		// Get the entity
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
		player_info_t pinfo;

		// The entity isn't some laggy peice of shit or something
		if (pEntity &&  pEntity != pLocal)
		{
			if (Interfaces::Engine->GetPlayerInfo(i, &pinfo) && !pEntity->IsAlive() && !pEntity->IsDormant())
			{
				HANDLE obs = pEntity->GetObserverTargetHandle();

				if (obs)
				{
					IClientEntity *pTarget = Interfaces::EntList->GetClientEntityFromHandle(obs);
					player_info_t pinfo2;
					if (pTarget)
					{
						if (Interfaces::Engine->GetPlayerInfo(pTarget->GetIndex(), &pinfo2))
						{
							char buf[255]; sprintf_s(buf, "%s => %s", pinfo.name, pinfo2.name);
							RECT TextSize = Render::GetTextSize(Render::Fonts::ESP, buf);
							Render::Clear(scrn.right - 260, (scrn.bottom / 2) + (16 * ayy), 260, 16, Color(0, 0, 0, 140));
							Render::Text(scrn.right - TextSize.right - 4, (scrn.bottom / 2) + (16 * ayy), pTarget->GetIndex() == pLocal->GetIndex() ? Color(240, 70, 80, 255) : Color(255, 255, 255, 255), Render::Fonts::ESP, buf);
							ayy++;
						}
					}
				}
			}
		}
	}

	Render::Outline(scrn.right - 261, (scrn.bottom / 2) - 1, 262, (16 * ayy) + 2, Color(23, 23, 23, 255));
	Render::Outline(scrn.right - 260, (scrn.bottom / 2), 260, (16 * ayy), Color(90, 90, 90, 255));
}

//  Yeah m8
void CEsp::DrawPlayer(IClientEntity* pEntity, player_info_t pinfo)
{
	ESPBox Box;
	Color Color;

	// Show own team false? well gtfo teammate lol
	if (Menu::Window.VisualsTab.FiltersEnemiesOnly.GetState() && (pEntity->GetTeamNum() == hackManager.pLocal()->GetTeamNum()))
		return;

	if (GetBox(pEntity, Box))
	{
		Color = GetPlayerColor(pEntity);

		/*if (Menu::Window.VisualsTab.OptionsGlow.GetState())
		{
			int TeamNum = pEntity->GetTeamNum();

			if (TeamNum == TEAM_CS_T)
			{
				DrawGlow(pEntity, 255, 0, 0, 160);
			}
			else if (TeamNum == TEAM_CS_CT)
			{
				DrawGlow(pEntity, 0, 0, 255, 160);
			}
		}*/

		if (Menu::Window.VisualsTab.OptionsBox.GetState())
			DrawBox(Box, Color);
		if (Menu::Window.VisualsTab.OptionsFillBox.GetState())
			Fill(Box, Color);
		if (Menu::Window.VisualsTab.OptionsName.GetState())
			DrawName(pinfo, Box);
		if (Menu::Window.VisualsTab.Glow.GetState())
			DrawGlow(Color);
	
		if (Menu::Window.VisualsTab.OptionHealthEnable.GetState())
			DrawHealth(pEntity, Box);


		if (Menu::Window.VisualsTab.BulletTrace.GetState())
			BulletTrace(pEntity, Color);

		
		if (Menu::Window.VisualsTab.OptionsInfo.GetState() || Menu::Window.VisualsTab.OptionsWeapon.GetState())
			DrawInfo(pEntity, Box);

		if (Menu::Window.VisualsTab.OptionsAimSpot.GetState())
			DrawCross(pEntity);

		if (Menu::Window.VisualsTab.OptionsSkeleton.GetState())
			DrawSkeleton(pEntity);
	}
}

/* // glow shit
struct Glowobject
{
	IClientEntity* pEntity;
	Vector Color;
	float Alpha;
	byte PAD[16];
	bool RenderWhenOccluded;
	bool RenderWhenUnOccluded;
	bool FullBloomRender;
	byte PAD2[17];
};

// simple sexy glow
void CEsp::DrawGlow(IClientEntity *pEntity, int r, int g, int b, int a)
{
	static uintptr_t Module = (uintptr_t)GetModuleHandle("client.dll");

	Glowobject* GlowManager = *(Glowobject**)(Module + 0x4B71C6C);

	if (GlowManager)
	{
		Glowobject* GlowObject = &GlowManager[pEntity->GetGlowIndex()];

		if (GlowObject)
		{
			GlowObject->RenderWhenOccluded = 1;
			GlowObject->RenderWhenUnOccluded = 0;

			float glowr = (1 / 255.0f)*r;
			float glowg = (1 / 255.0f)*g;
			float glowb = (1 / 255.0f)*b;
			float glowa = (1 / 255.0f)*a;
			GlowObject->Color = Vector((1 / 255.0f)*r, (1 / 255.0f)*g, (1 / 255.0f)*b);
			GlowObject->Alpha = (1 / 255.0f)*a;
		}
	}
} */

// Gets the 2D bounding box for the entity
// Returns false on failure nigga don't fail me













bool CEsp::GetBox(IClientEntity* pEntity, CEsp::ESPBox &result)
{
	// Variables
	Vector  vOrigin, min, max, sMin, sMax, sOrigin,
		flb, brt, blb, frt, frb, brb, blt, flt;
	float left, top, right, bottom;

	// Get the locations
	vOrigin = pEntity->GetOrigin();
	min = pEntity->collisionProperty()->GetMins() + vOrigin;
	max = pEntity->collisionProperty()->GetMaxs() + vOrigin;

	// Points of a 3d bounding box
	Vector points[] = { Vector(min.x, min.y, min.z),
		Vector(min.x, max.y, min.z),
		Vector(max.x, max.y, min.z),
		Vector(max.x, min.y, min.z),
		Vector(max.x, max.y, max.z),
		Vector(min.x, max.y, max.z),
		Vector(min.x, min.y, max.z),
		Vector(max.x, min.y, max.z) };

	// Get screen positions
	if (!Render::WorldToScreen(points[3], flb) || !Render::WorldToScreen(points[5], brt)
		|| !Render::WorldToScreen(points[0], blb) || !Render::WorldToScreen(points[4], frt)
		|| !Render::WorldToScreen(points[2], frb) || !Render::WorldToScreen(points[1], brb)
		|| !Render::WorldToScreen(points[6], blt) || !Render::WorldToScreen(points[7], flt))
		return false;

	// Put them in an array (maybe start them off in one later for speed?)
	Vector arr[] = { flb, brt, blb, frt, frb, brb, blt, flt };

	// Init this shit
	left = flb.x;
	top = flb.y;
	right = flb.x;
	bottom = flb.y;

	// Find the bounding corners for our box
	for (int i = 1; i < 8; i++)
	{
		if (left > arr[i].x)
			left = arr[i].x;
		if (bottom < arr[i].y)
			bottom = arr[i].y;
		if (right < arr[i].x)
			right = arr[i].x;
		if (top > arr[i].y)
			top = arr[i].y;
	}

	// Width / height
	result.x = left;
	result.y = top;
	result.w = right - left;
	result.h = bottom - top;

	return true;
}

// Get an entities color depending on team and vis ect
Color CEsp::GetPlayerColor(IClientEntity* pEntity)
{
	int TeamNum = pEntity->GetTeamNum();
	bool IsVis = GameUtils::IsVisible(hackManager.pLocal(), pEntity, (int)CSGOHitboxID::Head);

	int rctvisesp = Menu::Window.VisualsTab.RBoxCTV.GetValue();
	int gctvisesp = Menu::Window.VisualsTab.GBoxCTV.GetValue();
	int bctvisesp = Menu::Window.VisualsTab.BBoxCTV.GetValue();
	int actvisesp = Menu::Window.VisualsTab.ABoxCTV.GetValue();

	int rctesp = Menu::Window.VisualsTab.RBoxCT.GetValue();
	int gctesp = Menu::Window.VisualsTab.GBoxCT.GetValue();
	int bctesp = Menu::Window.VisualsTab.BBoxCT.GetValue();
	int actesp = Menu::Window.VisualsTab.ABoxCT.GetValue();

	Color color;

	if (TeamNum == TEAM_CS_T)
	{
		if (IsVis)
			color = Color(235, 200, 0, 255);
		else
			color = Color(235, 50, 0, 255);
	}
	else
	{
		if (IsVis)
			color = Color(rctvisesp, gctvisesp, bctvisesp, actvisesp);
		else
			color = Color(rctesp, gctesp, bctesp, actesp);
	}


	return color;
}

// 2D  Esp box
void CEsp::DrawBox(CEsp::ESPBox size, Color color)
{
	//if (PlayerBoxes->GetStringIndex() == 1)
	//{
		// Full Box
	//Render::Clear(size.x, size.y, size.w, size.h, color);
	//Render::Clear(size.x - 1, size.y - 1, size.w + 2, size.h + 2, Color(10, 10, 10, 150)); 
	//Render::Clear(size.x + 1, size.y + 1, size.w - 2, size.h - 2, Color(10, 10, 10, 150));
	//}
	//else
	if (Menu::Window.VisualsTab.BoxDesign.GetIndex() == 0)
	{
		// Corner Box
		int VertLine = (((float)size.w) * (0.20f));
		int HorzLine = (((float)size.h) * (0.20f));

		Render::Clear(size.x, size.y - 1, VertLine, 1, Color(10, 10, 10, 150));
		Render::Clear(size.x + size.w - VertLine, size.y - 1, VertLine, 1, Color(10, 10, 10, 150));
		Render::Clear(size.x, size.y + size.h - 1, VertLine, 1, Color(10, 10, 10, 150));
		Render::Clear(size.x + size.w - VertLine, size.y + size.h - 1, VertLine, 1, Color(10, 10, 10, 150));

		Render::Clear(size.x - 1, size.y, 1, HorzLine, Color(10, 10, 10, 150));
		Render::Clear(size.x - 1, size.y + size.h - HorzLine, 1, HorzLine, Color(10, 10, 10, 150));
		Render::Clear(size.x + size.w - 1, size.y, 1, HorzLine, Color(10, 10, 10, 150));
		Render::Clear(size.x + size.w - 1, size.y + size.h - HorzLine, 1, HorzLine, Color(10, 10, 10, 150));

		Render::Clear(size.x, size.y, VertLine, 1, color);
		Render::Clear(size.x + size.w - VertLine, size.y, VertLine, 1, color);
		Render::Clear(size.x, size.y + size.h, VertLine, 1, color);
		Render::Clear(size.x + size.w - VertLine, size.y + size.h, VertLine, 1, color);

		Render::Clear(size.x, size.y, 1, HorzLine, color);
		Render::Clear(size.x, size.y + size.h - HorzLine, 1, HorzLine, color);
		Render::Clear(size.x + size.w, size.y, 1, HorzLine, color);
		Render::Clear(size.x + size.w, size.y + size.h - HorzLine, 1, HorzLine, color);
	}
	else if (Menu::Window.VisualsTab.BoxDesign.GetIndex() == 1)
	{
		// Full Box
		Render::Outline(size.x, size.y, size.w, size.h, color);
		Render::Outline(size.x - 1, size.y - 1, size.w + 2, size.h + 2, Color(10, 10, 10, 150));
		Render::Outline(size.x + 1, size.y + 1, size.w - 2, size.h - 2, Color(10, 10, 10, 150));
	}
}


// Unicode Conversions
static wchar_t* CharToWideChar(const char* text)
{
	size_t size = strlen(text) + 1;
	wchar_t* wa = new wchar_t[size];
	mbstowcs_s(NULL, wa, size/4, text, size);
	return wa;
}

// Player name
void CEsp::DrawName(player_info_t pinfo, CEsp::ESPBox size)
{
	RECT nameSize = Render::GetTextSize(Render::Fonts::ESP, pinfo.name);
	Render::Text(size.x + (size.w / 2) - (nameSize.right / 2), size.y - 16, Color(255, 255, 255, 255), Render::Fonts::ESP, pinfo.name);
}

// Draw a health bar. For Tf2 when a bar is bigger than max health a second bar is displayed
void CEsp::DrawHealth(IClientEntity* pEntity, CEsp::ESPBox size)
{
	
	if (Menu::Window.VisualsTab.OptionsHealth.GetIndex() == 0)
	{
		ESPBox HealthBar = size;
		HealthBar.y += (HealthBar.h + 6);
		HealthBar.h = 4;

		float HealthValue = pEntity->GetHealth();
		float HealthPerc = HealthValue / 100.f;
		float Width = (size.w * HealthPerc);
		HealthBar.w = Width;

		// --  Main Bar -- //

		Vertex_t Verts[4];
		Verts[0].Init(Vector2D(HealthBar.x, HealthBar.y));
		Verts[1].Init(Vector2D(HealthBar.x + size.w + 5, HealthBar.y));
		Verts[2].Init(Vector2D(HealthBar.x + size.w, HealthBar.y + 5));
		Verts[3].Init(Vector2D(HealthBar.x - 5, HealthBar.y + 5));

		Render::PolygonOutline(4, Verts, Color(10, 10, 10, 255), Color(255, 255, 255, 170));

		Vertex_t Verts2[4];
		Verts2[0].Init(Vector2D(HealthBar.x + 1, HealthBar.y + 1));
		Verts2[1].Init(Vector2D(HealthBar.x + HealthBar.w + 4, HealthBar.y + 1));
		Verts2[2].Init(Vector2D(HealthBar.x + HealthBar.w, HealthBar.y + 5));
		Verts2[3].Init(Vector2D(HealthBar.x - 4, HealthBar.y + 5));

		Color c = GetPlayerColor(pEntity);
		Render::Polygon(4, Verts2, c);

		Verts2[0].Init(Vector2D(HealthBar.x + 1, HealthBar.y + 1));
		Verts2[1].Init(Vector2D(HealthBar.x + HealthBar.w + 2, HealthBar.y + 1));
		Verts2[2].Init(Vector2D(HealthBar.x + HealthBar.w, HealthBar.y + 2));
		Verts2[3].Init(Vector2D(HealthBar.x - 2, HealthBar.y + 2));

		Render::Polygon(4, Verts2, Color(255, 255, 255, 40));
	}
	if (Menu::Window.VisualsTab.OptionsHealth.GetIndex() == 1)
	{
		ESPBox HealthBar = size;
		HealthBar.y += (HealthBar.h + 6);
		HealthBar.h = 4;

		float HealthValue = pEntity->GetHealth();
		float HealthPerc = HealthValue / 100.f;
		float Width = (size.w * HealthPerc);
		HealthBar.w = Width;

		int health = pEntity->GetHealth();

		if (health > 100)
			health = 100;

		int r = 255 - health * 2.55;
		int g = health * 2.55;

		int healthBar = size.h / 100 * health;
		int healthBarDelta = size.h - healthBar;

		//int iClampedHealth = pEntity->GetHealth();
		//	if (iClampedHealth >= 100)
		//	iClampedHealth = 100;

		Render::Outline(size.x - 4, size.y + 1, 1, size.h * 0.01 * health, Color(r, g, 0, 255));
		Render::Outline(size.x - 5, size.y - 1, 3, size.h + 2, Color(0, 0, 0, 150));
	}

	
	if (Menu::Window.VisualsTab.OptionsHealth.GetIndex() == 2)
	{


		ESPBox HealthBar = size;
		HealthBar.y += (HealthBar.h + 6);
		HealthBar.h = 4;

		float HealthValue = pEntity->GetHealth();
		float HealthPerc = HealthValue / 100.f;
		float Width = (size.w * HealthPerc);
		HealthBar.w = Width;

		int health = pEntity->GetHealth();

		if (health > 100)
			health = 100;



		int healthBar = size.h / 100 * health;
		int healthBarDelta = size.h - healthBar;


		HealthBarNew(pEntity, size.x + 55, size.y + 1, size.h);

	}

}

// Cleans the internal class name up to something human readable and nice
std::string CleanItemName(std::string name)
{
	std::string Name = name;
	// Tidy up the weapon Name
	if (Name[0] == 'C')
		Name.erase(Name.begin());

	// Remove the word Weapon
	auto startOfWeap = Name.find("Weapon");
	if (startOfWeap != std::string::npos)
		Name.erase(Name.begin() + startOfWeap, Name.begin() + startOfWeap + 6);

	return Name;
}
void CEsp::Fill(CEsp::ESPBox size, Color color)
{
	if (Menu::Window.VisualsTab.OptionsFillBox.GetState())
	{
		int red = Menu::Window.GUITab.FillBoxRed.GetValue();
		int green = Menu::Window.GUITab.FillBoxGreen.GetValue();
		int blue = Menu::Window.GUITab.FillBoxBlue.GetValue();
		int alpha = Menu::Window.GUITab.FillBoxAlpha.GetValue();

		Render::Clear(size.x, size.y, size.w, size.h, Color(red, green, blue, alpha));

	}
	else
	{

	}
}//+
// Anything else: weapons, class state? idk
void CEsp::DrawInfo(IClientEntity* pEntity, CEsp::ESPBox size)
{
	std::vector<std::string> Info;

	// Player Weapon ESP
	IClientEntity* pWeapon = Interfaces::EntList->GetClientEntityFromHandle((HANDLE)pEntity->GetActiveWeaponHandle());
	if (Menu::Window.VisualsTab.OptionsWeapon.GetState() && pWeapon)
	{
		ClientClass* cClass = (ClientClass*)pWeapon->GetClientClass();
		if (cClass)
		{
			// Draw it
			Info.push_back(CleanItemName(cClass->m_pNetworkName));
		}
	}

	// Bomb Carrier
	if (Menu::Window.VisualsTab.OptionsInfo.GetState() && pEntity == BombCarrier)
	{
		Info.push_back("Bomb Carrier");
	}

	// Is Scoped
	if (Menu::Window.VisualsTab.IsScoped.GetState() && pEntity->IsScoped())
	{
		Info.push_back("Is Scoped");
	}
	// Has Defuser
	if (Menu::Window.VisualsTab.HasDefuser.GetState() && pEntity->HasDefuser())
	{
		Info.push_back("Has Defuser");
	}
	// Defusing
	if (Menu::Window.VisualsTab.IsDefusing.GetState() && pEntity->IsDefusing())
	{
		Info.push_back("Is Defusing");
	}

	static RECT Size = Render::GetTextSize(Render::Fonts::Default, "Hi");
	int i = 0;
	for (auto Text : Info)
	{
		// Render both Weapon and Bomb Carrier
		Render::Text(size.x + size.w + 3, size.y + (i*(Size.bottom + 2)), Color(255, 255, 255, 255), Render::Fonts::ESP, Text.c_str());
		i++;
	}
}

// Little cross on their heads
void CEsp::DrawCross(IClientEntity* pEntity)
{
	Vector cross = pEntity->GetHeadPos(), screen;
	static int Scale = 2;
	if (Render::WorldToScreen(cross, screen))
	{
		Render::Clear(screen.x - Scale, screen.y - (Scale * 2), (Scale * 2), (Scale * 4), Color(20, 20, 20, 160));
		Render::Clear(screen.x - (Scale * 2), screen.y - Scale, (Scale * 4), (Scale * 2), Color(20, 20, 20, 160));
		Render::Clear(screen.x - Scale - 1, screen.y - (Scale * 2) - 1, (Scale * 2) - 2, (Scale * 4) - 2, Color(250, 250, 250, 160));
		Render::Clear(screen.x - (Scale * 2) - 1, screen.y - Scale - 1, (Scale * 4) - 2, (Scale * 2) - 2, Color(250, 250, 250, 160));
	}
}

// Draws a dropped CS:GO Item
void CEsp::DrawDrop(IClientEntity* pEntity, ClientClass* cClass)
{
	Vector Box;
	CBaseCombatWeapon* Weapon = (CBaseCombatWeapon*)pEntity;
	IClientEntity* plr = Interfaces::EntList->GetClientEntityFromHandle((HANDLE)Weapon->GetOwnerHandle());
	if (!plr && Render::WorldToScreen(Weapon->GetOrigin(), Box))
	{
		if (Menu::Window.VisualsTab.OptionsBox.GetState())
		{
			Render::Outline(Box.x - 2, Box.y - 2, 4, 4, Color(255, 255, 255, 255));
			Render::Outline(Box.x - 3, Box.y - 3, 6, 6, Color(10, 10, 10, 150));
		}

		if (Menu::Window.VisualsTab.OptionsInfo.GetState())
		{
			std::string ItemName = CleanItemName(cClass->m_pNetworkName);
			RECT TextSize = Render::GetTextSize(Render::Fonts::ESP, ItemName.c_str());
			Render::Text(Box.x - (TextSize.right / 2), Box.y - 16, Color(255, 255, 255, 255), Render::Fonts::ESP, ItemName.c_str());
		}
	}
}

// Draws a chicken
void CEsp::DrawChicken(IClientEntity* pEntity, ClientClass* cClass)
{
	ESPBox Box;

	if (GetBox(pEntity, Box))
	{
		player_info_t pinfo; strcpy_s(pinfo.name, "Chicken");
		if (Menu::Window.VisualsTab.OptionsBox.GetState())
			DrawBox(Box, Color(255,255,255,255));

		if (Menu::Window.VisualsTab.OptionsName.GetState())
			DrawName(pinfo, Box);
	}
}

// Draw the planted bomb and timer
void CEsp::DrawBombPlanted(IClientEntity* pEntity, ClientClass* cClass) 
{
	// Null it out incase bomb has been dropped or planted
	BombCarrier = nullptr;

	Vector vOrig; Vector vScreen;
	vOrig = pEntity->GetOrigin();
	CCSBomb* Bomb = (CCSBomb*)pEntity;

	if (Render::WorldToScreen(vOrig, vScreen))
	{
		float flBlow = Bomb->GetC4BlowTime();
		float TimeRemaining = flBlow - (Interfaces::Globals->interval_per_tick * hackManager.pLocal()->GetTickBase());
		char buffer[64];
		sprintf_s(buffer, "Bomb Defuse In %.1f", TimeRemaining);
		Render::Text(vScreen.x, vScreen.y, Color(255, 255, 255, 255), Render::Fonts::ESP, buffer);
	}
}

// Draw the bomb if it's dropped, or store the player who's carrying 
void CEsp::DrawBomb(IClientEntity* pEntity, ClientClass* cClass)
{
	// Null it out incase bomb has been dropped or planted
	BombCarrier = nullptr;
	CBaseCombatWeapon *BombWeapon = (CBaseCombatWeapon *)pEntity;
	Vector vOrig; Vector vScreen;
	vOrig = pEntity->GetOrigin();
	bool adopted = true;
	HANDLE parent = BombWeapon->GetOwnerHandle();
	if (parent || (vOrig.x == 0 && vOrig.y == 0 && vOrig.z == 0))
	{
		IClientEntity* pParentEnt = (Interfaces::EntList->GetClientEntityFromHandle(parent));
		if (pParentEnt && pParentEnt->IsAlive())
		{
			BombCarrier = pParentEnt;
			adopted = false;
		}
	}

	if (adopted)
	{
		if (Render::WorldToScreen(vOrig, vScreen))
		{
			Render::Text(vScreen.x, vScreen.y, Color(112, 230, 20, 255), Render::Fonts::ESP, "Bomb");
		}
	}
}

void DrawBoneArray(int* boneNumbers, int amount, IClientEntity* pEntity, Color color)
{
	Vector LastBoneScreen;
	for (int i = 0; i < amount; i++)
	{
		Vector Bone = pEntity->GetBonePos(boneNumbers[i]);
		Vector BoneScreen;

		if (Render::WorldToScreen(Bone, BoneScreen))
		{
			if (i>0)
			{
				Render::Line(LastBoneScreen.x, LastBoneScreen.y, BoneScreen.x, BoneScreen.y, color);
			}
		}
		LastBoneScreen = BoneScreen;
	}
}

void DrawBoneTest(IClientEntity *pEntity)
{
	for (int i = 0; i < 127; i++)
	{
		Vector BoneLoc = pEntity->GetBonePos(i);
		Vector BoneScreen;
		if (Render::WorldToScreen(BoneLoc, BoneScreen))
		{
			char buf[10];
			_itoa_s(i, buf, 10);
			Render::Text(BoneScreen.x, BoneScreen.y, Color(255, 255, 255, 180), Render::Fonts::ESP, buf);
		}
	}
}

void CEsp::DrawSkeleton(IClientEntity* pEntity)
{
	int rskele = Menu::Window.VisualsTab.RSkele.GetValue();
	int gskele = Menu::Window.VisualsTab.GSkele.GetValue();
	int bskele = Menu::Window.VisualsTab.BSkele.GetValue();
	int askele = Menu::Window.VisualsTab.ASkele.GetValue();

	studiohdr_t* pStudioHdr = Interfaces::ModelInfo->GetStudiomodel(pEntity->GetModel());

	if (!pStudioHdr)
		return;

	Vector vParent, vChild, sParent, sChild;

	for (int j = 0; j < pStudioHdr->numbones; j++)
	{
		mstudiobone_t* pBone = pStudioHdr->GetBone(j);

		if (pBone && (pBone->flags & BONE_USED_BY_HITBOX) && (pBone->parent != -1))
		{
			vChild = pEntity->GetBonePos(j);
			vParent = pEntity->GetBonePos(pBone->parent);

			if (Render::WorldToScreen(vParent, sParent) && Render::WorldToScreen(vChild, sChild))
			{
				Render::Line(sParent[0], sParent[1], sChild[0], sChild[1], Color(rskele, gskele, bskele, askele));
			}
		}
	}
}
DWORD GlowManager = *(DWORD*)(Utilities::Memory::FindPatternV2("client.dll", "0F 11 05 ?? ?? ?? ?? 83 C8 01 C7 05 ?? ?? ?? ?? 00 00 00 00") + 3);

void CEsp::DrawGlow(Color color)
{
	int GlowA = Menu::Window.VisualsTab.GlowAlpha.GetValue();

	CGlowObjectManager* GlowObjectManager = (CGlowObjectManager*)GlowManager;

	for (int i = 0; i < GlowObjectManager->size; ++i)
	{
		CGlowObjectManager::GlowObjectDefinition_t* glowEntity = &GlowObjectManager->m_GlowObjectDefinitions[i];
		IClientEntity* Entity = glowEntity->getEntity();

		if (glowEntity->IsEmpty() || !Entity)
			continue;

		switch (Entity->GetClientClass()->m_ClassID)
		{

		case 35:
			if (Menu::Window.VisualsTab.Glow.GetState() && Entity->GetClientClass()->m_ClassID == (int)CSGOClassID::CCSPlayer)
			{
				if (Menu::Window.VisualsTab.FiltersPlayers.GetState())
					glowEntity->set(Color(color));
			}
		}
	}
}



void CEsp::BulletTrace(IClientEntity* pEntity, Color color)
{
	Vector src3D, dst3D, forward, src, dst;
	trace_t tr;
	Ray_t ray;
	CTraceFilter filter;

	AngleVectors(pEntity->GetEyeAngles(), &forward);
	filter.pSkip = pEntity;
	src3D = pEntity->GetBonePos(6) - Vector(0, 0, 0);
	dst3D = src3D + (forward * Menu::Window.VisualsTab.BulletTraceLength.GetValue());

	ray.Init(src3D, dst3D);

	Interfaces::Trace->TraceRay(ray, MASK_SHOT, &filter, &tr);

	if (!Render::WorldToScreen(src3D, src) || !Render::WorldToScreen(tr.endpos, dst))
		return;


	int red = Menu::Window.GUITab.RBT.GetValue();
	int green = Menu::Window.GUITab.GBT.GetValue();
	int blue = Menu::Window.GUITab.BBT.GetValue();
	

	Render::DrawLine(src.x, src.y, dst.x, dst.y, Color(red , green, blue, 225));
	Render::DrawRect(dst.x - 3, dst.y - 3, 6, 6, Color(red, green, blue, 255));
};
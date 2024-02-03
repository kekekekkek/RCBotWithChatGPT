#include "Include.h"

CFile g_File;
CUtils g_Utils;
COpenAI g_OpenAI;

int main()
{
	bool bShow = true;

	string strAnswer = "";
	string strReadFile = "";
	string strFileName = "..\\store\\Prompt.txt";

	cout << "The program is running!\n[F5] - To hide/show window.\n";
	cout << "------------------------\n";

	if (!g_File.ReadFile("OpenAI.txt").empty())
	{
		g_OpenAI.SetModel("gpt-3.5-turbo");
		g_OpenAI.SetEndPoint("/v1/chat/completions");
		g_OpenAI.SetOpenAIKey(g_File.ReadFile("OpenAI.txt"));

		while (true)
		{
			strReadFile = g_File.ReadFile(strFileName);

			if (GetAsyncKeyState(VK_F5) & 1)
			{
				if (GetForegroundWindow() == GetConsoleWindow())
				{
					bShow = !bShow;
					ShowWindow(GetConsoleWindow(), bShow);
				}
				else
				{
					if (!IsWindowVisible(GetConsoleWindow()))
					{
						bShow = true;
						ShowWindow(GetConsoleWindow(), bShow);
					}
				}
			}

			if (g_Utils.IndexOf(strReadFile, " - {Prompt}") != -1)
			{
				cout << "The request was received...\n";

				strReadFile.erase(g_Utils.IndexOf(strReadFile, " - {Prompt}"), 11);
				strAnswer = g_OpenAI.ReceiveMessage(g_OpenAI.SendRequest(strReadFile, 0.7f));

				g_File.WriteFile(strFileName, (strAnswer + " - {Answer}"));
				cout << "The response was successfully written to a file!\n";
			}

			Sleep(25);
		}
	}
	else
		cout << "Failed to get an OpenAI token!\n";

	system("pause");
	return 0;
}
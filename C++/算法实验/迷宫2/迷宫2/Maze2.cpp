#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

#define WIN_WIDTH 1200                      // ������
#define WIN_HEIGHT 680                      // ����߶�
#define MAZE_WIDTH 15*34                    // �Թ����
#define MAZE_HEIGHT 15*17                   // �Թ��߶�
#define B_WIDTH 10                          // ���ӿ��
#define X 51                                // �Թ����� 
#define Y 26                                // �Թ����� 
#define N X*2+1                             // �Թ��������� 
#define M Y*2+1                             // �Թ��������� 
#define L (N-1)*(M-1)                       // �Թ�·������
#define LX 80                               // �������X
#define LY 50                               // �������Y
#define C_BLOCK RGB(153,102,85)             // ǽ����ɫ
#define C_GRAY RGB(123,72,55)               // ��Ӱ��ɫ
#define C_GROUND RGB(50,50,50)              // ������ɫ
#define C_ROOT RGB(170,170,210)             // ·����ɫ
#define C_LINE YELLOW           // ·������ɫ

float GetFPS();                             // ���㻭��FPS(ÿ��֡��)
void Delay(DWORD ms);                       // ������ʱ
bool IsInRect(int x, int y, RECT r);          // �Ƿ��ھ�����
void InitMaze();                            // ��ʼ���Թ�����
void OutputMaze();                          // ����Թ�
void CopyScreenBuffer();                    // ������Ļ������
void DrawScreenBuffer();                    // ���ƻ��浽��Ļ
void OutPutPath();                          // ���·������
void DrawFPS();                             // ���֡��
int Move(int d, int x, int y);                // ��ָ�������ƶ�,�����Ƿ�ɹ��ƶ�
void DFS_CreateMaze(int x, int y);           // ������������Թ�
void FindPath(int i, int j);                 // ������������Թ�·��
void CreateMaze();                          // �����Թ�
void DrawMenuItems();                       // ���Ʋ˵���ť

DWORD* p_Screen;                                // �Դ�ָ��
DWORD buff_Screen[WIN_WIDTH*WIN_HEIGHT];        // ��ʾ����
int isShowFPS = 1;                                // �Ƿ���ʾ֡��
int isShowMazePath = 0;                           // ��ʾ�Թ�·��
int Maze[M][N];                                 // �Թ�����   0 ��ͨͨ· 1 ǽ 2 ·���� 3 ��� 4 �յ�
int path_x[1000][L], path_y[1000][L];            // ·������
int length[L];                                  // ·����������
int lengtha, count;                              // ��������
int mouseX;                                     // ���λ������X
int mouseY;                                     // ���λ������Y
bool isMouseDown;                               // ��갴��
int start_x, start_y, end_x, end_y;                // ������� �յ�����
int temp_d;                                     // ��һ���ߵķ���
int Move_flag;                                  // �ƶ����

// ���㻭��FPS(ÿ��֡��)
float GetFPS()
{
#define FPS_COUNT 8
	static int i = 0;
	static DWORD oldTime = GetTickCount();
	static float fps;
	if (i > FPS_COUNT)
	{
		i = 0;
		int newTime = GetTickCount();
		int elapsedTime = newTime - oldTime;
		fps = FPS_COUNT / (elapsedTime / 1000.0f);
		oldTime = newTime;
	}
	i++;
	return fps;
}
// ������ʱ
void Delay(DWORD ms)
{
	static DWORD oldTime = GetTickCount();
	while (GetTickCount() - oldTime < ms)
		Sleep(1);
	oldTime = GetTickCount();
}
// �Ƿ��ھ�����
bool IsInRect(int x, int y, RECT r)
{
	if ((x >= r.left && x <= r.right) && (y >= r.top && y <= r.bottom)) return true;
	else return false;
}
// ��ʼ���Թ����� 
void InitMaze() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			Maze[i][j] = 1;
		}
	}
	// ���������յ�
	Maze[1][0] = 3;
	Maze[M - 2][N - 1] = 4;
}
// ����Թ� 
void OutputMaze() {
	// ����
	setcolor(RGB(255, 255, 255));
	setfillcolor(RGB(255, 255, 255));
	fillrectangle(0, 0, WIN_WIDTH, WIN_HEIGHT);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int xx = LX + j * B_WIDTH;
			int yy = LY + i * B_WIDTH;
			switch (Maze[i][j]) {
			case 0:
				setcolor(C_GROUND);
				setfillcolor(C_GROUND);
				fillrectangle(xx, yy, xx + B_WIDTH, yy + B_WIDTH);
				break;
			case 1:
				setcolor(C_BLOCK);
				setfillcolor(C_BLOCK);
				fillrectangle(xx, yy, xx + B_WIDTH, yy + B_WIDTH);
				if (Maze[i][j] == 1 && (i == M - 1 || Maze[i + 1][j] != 1))
				{
					setcolor(C_GRAY);
					setfillcolor(C_GRAY);
					fillrectangle(xx, yy + B_WIDTH / 2, xx + B_WIDTH, yy + B_WIDTH);
				}
				break;
			case 2:
				setcolor(C_GROUND);
				setfillcolor(C_GROUND);
				fillrectangle(xx, yy, xx + B_WIDTH, yy + B_WIDTH);
				/*
				setcolor(C_ROOT);
				setfillcolor(C_ROOT);
				fillellipse(xx+B_WIDTH/2-1,yy+B_WIDTH/2-1,xx+B_WIDTH/2+1,yy+B_WIDTH/2+1);
				*/
				break;
			case 3:
				setcolor(C_GROUND);
				setfillcolor(C_GROUND);
				fillrectangle(xx, yy, xx + B_WIDTH, yy + B_WIDTH);
				break;
			case 4:
				setcolor(C_GROUND);
				setfillcolor(C_GROUND);
				fillrectangle(xx, yy, xx + B_WIDTH, yy + B_WIDTH);
				break;
			}
		}
	}


}
// ������Ļ������
void CopyScreenBuffer()
{
	for (int i = 0; i < WIN_WIDTH*WIN_HEIGHT; i++)
	{
		buff_Screen[i] = p_Screen[i];
	}
}
// ���ƻ��浽��Ļ
void DrawScreenBuffer()
{
	for (int i = 0; i < WIN_WIDTH*WIN_HEIGHT; i++)
	{
		p_Screen[i] = buff_Screen[i];
	}
}
// ���·������
void OutPutPath()
{
	if (isShowMazePath)
	{
		for (int i = 0; i < length[0] - 1; i++)
		{
			setcolor(C_LINE);
			int x1 = path_x[0][i] * B_WIDTH + B_WIDTH / 2 + LX;
			int x2 = path_x[0][i + 1] * B_WIDTH + B_WIDTH / 2 + LX;
			int y1 = path_y[0][i] * B_WIDTH + B_WIDTH / 2 + LY;
			int y2 = path_y[0][i + 1] * B_WIDTH + B_WIDTH / 2 + LY;
			line(x1, y1, x2, y2);
		}
	}
}
// ���֡��
void DrawFPS()
{
	//���֡��
	if (isShowFPS)
	{
		setcolor(RED);
		settextstyle(14, 0, _T("����"));
		TCHAR  s[5];
#if _MSC_VER > 1200
		_stprintf_s(s, _T("%.1f"), GetFPS());
#else
		_stprintf(s, _T("%.1f"), GetFPS());
#endif
		outtextxy(4, 2, _T("FPS:"));
		outtextxy(34, 2, s);
	}
}
// ��ָ�������ƶ�,�����Ƿ�ɹ��ƶ�
int Move(int d, int x, int y)
{
	switch (d)
	{
		// ����
	case 0: {
		if (Maze[y - 3][x] > 0 && Maze[y - 2][x - 1] > 0 && Maze[y - 2][x + 1] > 0 && y - 2 > 0)
		{
			Maze[y - 2][x] = 0;
			Maze[y - 1][x] = 0;
			Move_flag = 1;
			temp_d = 0;
			DFS_CreateMaze(x, y - 2);
		}
		break;
	}
			// ����
	case 1: {
		if (Maze[y + 3][x] > 0 && Maze[y + 2][x - 1] > 0 && Maze[y + 2][x + 1] > 0 && y + 2 < M)
		{
			Maze[y + 2][x] = 0;
			Maze[y + 1][x] = 0;
			Move_flag = 1;
			temp_d = 1;
			DFS_CreateMaze(x, y + 2);
		}
		break;
	}
			// ����
	case 2: {
		if (Maze[y][x - 3] > 0 && Maze[y - 1][x - 2] > 0 && Maze[y + 1][x - 2] > 0 && x - 2 > 0)
		{
			Maze[y][x - 1] = 0;
			Maze[y][x - 2] = 0;
			Move_flag = 1;
			temp_d = 2;
			DFS_CreateMaze(x - 2, y);
		}
		break;
	}
			// ����
	case 3: {
		if (Maze[y][x + 3] > 0 && Maze[y - 1][x + 2] > 0 && Maze[y + 1][x + 2] > 0 && x + 2 < N)
		{
			Maze[y][x + 1] = 0;
			Maze[y][x + 2] = 0;
			Move_flag = 1;
			temp_d = 3;
			DFS_CreateMaze(x + 2, y);
		}
		break;
	}
	}
	return Move_flag;
}// ������������Թ�
// ������������Թ�
void DFS_CreateMaze(int x, int y)
{
	//��ͨ·
	Maze[y][x] = 0;
	//�������
	int d = rand() % 4;
	int direct = temp_d;
	int t[4] = { 0,0,0,0 };// ���߷�����
	Move_flag = 0;// �����ƶ����
	// ��֤����Ե�ͬʱ������ͼ
	while (t[0] != 1 || t[1] != 1 || t[2] != 1 || t[3] != 1)
	{
		int i = rand() % 4;
		if (t[i] != 1)
		{
			t[i] = 1;
			Move(i, x, y);
		}
	}
}
// ������������Թ�·��
void FindPath(int x, int y)
{
	// ��·��
	Maze[y][x] = 2;
	path_x[count][lengtha] = x;
	path_y[count][lengtha] = y;
	lengtha++;
	// ������Ŀ�ĵ�
	if (x == end_x && y == end_y)
	{
		//success=1;
		length[count] = lengtha;
		count++;
		if (count > 0)
		{
			// ������һ�ε�·������һ�δ�����·����
			for (int i = 0; i < length[count - 1]; i++)
			{
				path_x[count][i] = path_x[count - 1][i];
				path_y[count][i] = path_y[count - 1][i];
			}
		}
	}
	else
	{
		// ����������
		if (Maze[y][x + 1] == 0) { FindPath(x + 1, y); Maze[y][x + 1] = 0; lengtha--; }
		if (Maze[y + 1][x] == 0) { FindPath(x, y + 1); Maze[y + 1][x] = 0; lengtha--; }
		if (Maze[y][x - 1] == 0) { FindPath(x - 1, y); Maze[y][x - 1] = 0; lengtha--; }
		if (Maze[y - 1][x] == 0) { FindPath(x, y - 1); Maze[y - 1][x] = 0; lengtha--; }
	}
	//if(success!=1)
	//return success;
}
// �����Թ�
void CreateMaze()
{
	// ��ʼ���Թ�����
	InitMaze();
	isShowMazePath = 0;
	// ���յ㿪ʼ���������Թ�
	start_x = 1;
	start_y = 1;
	end_x = N - 2;
	end_y = M - 2;
	DFS_CreateMaze(end_x, end_y);
	// ����·��
	lengtha = 0;
	count = 0;
	FindPath(start_x, start_y);
	// ���·�����Ƶ���ͼ
	for (int i = 0; i < length[0]; i++)
	{
		Maze[path_y[0][i]][path_x[0][i]] = 2;
	}
}
// ���Ʋ˵���ť
void DrawMenuItems()
{
	RECT r;
	r.left = 860;
	r.top = 610;
	r.right = r.left + 90;
	r.bottom = r.top + 38;
	setcolor(RGB(50, 50, 50));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(220, 220, 220));
		// �����Թ�������Ӧ
		if (isMouseDown)
		{
			// �����Թ�
			CreateMaze();
			// ����һ�ε���Ļ�����Ƶ�����
			OutputMaze();
			CopyScreenBuffer();
			isMouseDown = 0;
		}
	}
	else setfillcolor(RGB(240, 240, 240));
	fillrectangle(r.left, r.top, r.right, r.bottom);
	settextstyle(25, 9, _T("Verdana"));
	setcolor(RGB(60, 60, 60));
	outtextxy(r.left + 5, r.top + 5, _T(" �����Թ�"));
	r.left = 1020;
	r.top = 610;
	r.right = r.left + 90;
	r.bottom = r.top + 38;
	setcolor(RGB(50, 50, 50));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(220, 220, 220));
		// ��ʾ/����·��
		if (isMouseDown)
		{
			isShowMazePath = !isShowMazePath;
			isMouseDown = 0;
		}
	}
	else setfillcolor(RGB(240, 240, 240));
	fillrectangle(r.left, r.top, r.right, r.bottom);
	settextstyle(25, 9, _T("Verdana"));
	setcolor(RGB(60, 60, 60));
	if (isShowMazePath) outtextxy(r.left + 5, r.top + 5, _T(" ����·��"));
	else outtextxy(r.left + 5, r.top + 5, _T(" ��ʾ·��"));
}
// ������
void main() {
	// ����������� 
	srand(unsigned(time(NULL)));
	// ��ʼ���豸������ͼƬ
	initgraph(WIN_WIDTH, WIN_HEIGHT);
	// ���ô��ڱ���
	SetWindowText(GetHWnd(), _T("Maze v0.9 By:ls9512"));
	cleardevice();
	// ���ú�ɫ����
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	// ����˫����,��ֹ����
	BeginBatchDraw();
	// �����Ϣ����
	MOUSEMSG mmsg;
	// ��ȡ�Դ�ָ��
	p_Screen = GetImageBuffer();
	// �����Թ�
	CreateMaze();
	// ����һ�ε���Ļ�����Ƶ�����
	OutputMaze();
	CopyScreenBuffer();
	// ��ѭ��
	while (true)
	{
		//���������Ϣ
		while (MouseHit())
		{
			mmsg = GetMouseMsg();
			switch (mmsg.uMsg)
			{
			case WM_MOUSEMOVE:  mouseX = mmsg.x; mouseY = mmsg.y; break;
			case WM_LBUTTONDOWN: isMouseDown = true; break;
			case WM_LBUTTONUP: isMouseDown = false; break;
			}
		}
		// ���ƣ����������ݸ��Ƶ���Ļ����
		DrawScreenBuffer();
		OutPutPath();
		DrawMenuItems();
		DrawFPS();
		// ��ʾ����Ļ�������
		FlushBatchDraw();
		// �ӳ�,֡������
		Delay(13);
	}
	// �ر�
	EndBatchDraw();
	closegraph();
}

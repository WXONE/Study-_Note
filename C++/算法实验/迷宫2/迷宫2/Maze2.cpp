#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

#define WIN_WIDTH 1200                      // 窗体宽度
#define WIN_HEIGHT 680                      // 窗体高度
#define MAZE_WIDTH 15*34                    // 迷宫宽度
#define MAZE_HEIGHT 15*17                   // 迷宫高度
#define B_WIDTH 10                          // 格子宽度
#define X 51                                // 迷宫列数 
#define Y 26                                // 迷宫行数 
#define N X*2+1                             // 迷宫数组列数 
#define M Y*2+1                             // 迷宫数组行数 
#define L (N-1)*(M-1)                       // 迷宫路径长度
#define LX 80                               // 起点坐标X
#define LY 50                               // 起点坐标Y
#define C_BLOCK RGB(153,102,85)             // 墙壁颜色
#define C_GRAY RGB(123,72,55)               // 阴影颜色
#define C_GROUND RGB(50,50,50)              // 地面颜色
#define C_ROOT RGB(170,170,210)             // 路径颜色
#define C_LINE YELLOW           // 路径线颜色

float GetFPS();                             // 计算画面FPS(每秒帧数)
void Delay(DWORD ms);                       // 绝对延时
bool IsInRect(int x, int y, RECT r);          // 是否在矩形内
void InitMaze();                            // 初始化迷宫数组
void OutputMaze();                          // 输出迷宫
void CopyScreenBuffer();                    // 复制屏幕到缓存
void DrawScreenBuffer();                    // 绘制缓存到屏幕
void OutPutPath();                          // 输出路径连线
void DrawFPS();                             // 输出帧数
int Move(int d, int x, int y);                // 向指定方向移动,返回是否成功移动
void DFS_CreateMaze(int x, int y);           // 深度优先生成迷宫
void FindPath(int i, int j);                 // 深度优先搜索迷宫路径
void CreateMaze();                          // 创建迷宫
void DrawMenuItems();                       // 绘制菜单按钮

DWORD* p_Screen;                                // 显存指针
DWORD buff_Screen[WIN_WIDTH*WIN_HEIGHT];        // 显示缓存
int isShowFPS = 1;                                // 是否显示帧数
int isShowMazePath = 0;                           // 显示迷宫路径
int Maze[M][N];                                 // 迷宫数组   0 普通通路 1 墙 2 路径点 3 起点 4 终点
int path_x[1000][L], path_y[1000][L];            // 路径坐标
int length[L];                                  // 路径搜索长度
int lengtha, count;                              // 搜索计数
int mouseX;                                     // 鼠标位置坐标X
int mouseY;                                     // 鼠标位置坐标Y
bool isMouseDown;                               // 鼠标按下
int start_x, start_y, end_x, end_y;                // 起点坐标 终点坐标
int temp_d;                                     // 上一步走的方向
int Move_flag;                                  // 移动标记

// 计算画面FPS(每秒帧数)
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
// 绝对延时
void Delay(DWORD ms)
{
	static DWORD oldTime = GetTickCount();
	while (GetTickCount() - oldTime < ms)
		Sleep(1);
	oldTime = GetTickCount();
}
// 是否在矩形内
bool IsInRect(int x, int y, RECT r)
{
	if ((x >= r.left && x <= r.right) && (y >= r.top && y <= r.bottom)) return true;
	else return false;
}
// 初始化迷宫数组 
void InitMaze() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			Maze[i][j] = 1;
		}
	}
	// 设置起点和终点
	Maze[1][0] = 3;
	Maze[M - 2][N - 1] = 4;
}
// 输出迷宫 
void OutputMaze() {
	// 清屏
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
// 复制屏幕到缓存
void CopyScreenBuffer()
{
	for (int i = 0; i < WIN_WIDTH*WIN_HEIGHT; i++)
	{
		buff_Screen[i] = p_Screen[i];
	}
}
// 绘制缓存到屏幕
void DrawScreenBuffer()
{
	for (int i = 0; i < WIN_WIDTH*WIN_HEIGHT; i++)
	{
		p_Screen[i] = buff_Screen[i];
	}
}
// 输出路径连线
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
// 输出帧数
void DrawFPS()
{
	//输出帧数
	if (isShowFPS)
	{
		setcolor(RED);
		settextstyle(14, 0, _T("宋体"));
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
// 向指定方向移动,返回是否成功移动
int Move(int d, int x, int y)
{
	switch (d)
	{
		// 向上
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
			// 向下
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
			// 向左
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
			// 向右
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
}// 深度优先生成迷宫
// 深度优先生成迷宫
void DFS_CreateMaze(int x, int y)
{
	//置通路
	Maze[y][x] = 0;
	//随机方向
	int d = rand() % 4;
	int direct = temp_d;
	int t[4] = { 0,0,0,0 };// 已走方向标记
	Move_flag = 0;// 重置移动标记
	// 保证随机性的同时走满地图
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
// 深度优先搜索迷宫路径
void FindPath(int x, int y)
{
	// 置路径
	Maze[y][x] = 2;
	path_x[count][lengtha] = x;
	path_y[count][lengtha] = y;
	lengtha++;
	// 搜索到目的地
	if (x == end_x && y == end_y)
	{
		//success=1;
		length[count] = lengtha;
		count++;
		if (count > 0)
		{
			// 复制上一次的路径到下一次待搜索路径中
			for (int i = 0; i < length[count - 1]; i++)
			{
				path_x[count][i] = path_x[count - 1][i];
				path_y[count][i] = path_y[count - 1][i];
			}
		}
	}
	else
	{
		// 搜索并回溯
		if (Maze[y][x + 1] == 0) { FindPath(x + 1, y); Maze[y][x + 1] = 0; lengtha--; }
		if (Maze[y + 1][x] == 0) { FindPath(x, y + 1); Maze[y + 1][x] = 0; lengtha--; }
		if (Maze[y][x - 1] == 0) { FindPath(x - 1, y); Maze[y][x - 1] = 0; lengtha--; }
		if (Maze[y - 1][x] == 0) { FindPath(x, y - 1); Maze[y - 1][x] = 0; lengtha--; }
	}
	//if(success!=1)
	//return success;
}
// 创建迷宫
void CreateMaze()
{
	// 初始化迷宫数组
	InitMaze();
	isShowMazePath = 0;
	// 从终点开始逆向生成迷宫
	start_x = 1;
	start_y = 1;
	end_x = N - 2;
	end_y = M - 2;
	DFS_CreateMaze(end_x, end_y);
	// 搜索路径
	lengtha = 0;
	count = 0;
	FindPath(start_x, start_y);
	// 结果路径复制到地图
	for (int i = 0; i < length[0]; i++)
	{
		Maze[path_y[0][i]][path_x[0][i]] = 2;
	}
}
// 绘制菜单按钮
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
		// 生成迷宫按键响应
		if (isMouseDown)
		{
			// 创建迷宫
			CreateMaze();
			// 绘制一次到屏幕并复制到缓存
			OutputMaze();
			CopyScreenBuffer();
			isMouseDown = 0;
		}
	}
	else setfillcolor(RGB(240, 240, 240));
	fillrectangle(r.left, r.top, r.right, r.bottom);
	settextstyle(25, 9, _T("Verdana"));
	setcolor(RGB(60, 60, 60));
	outtextxy(r.left + 5, r.top + 5, _T(" 生成迷宫"));
	r.left = 1020;
	r.top = 610;
	r.right = r.left + 90;
	r.bottom = r.top + 38;
	setcolor(RGB(50, 50, 50));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(220, 220, 220));
		// 显示/隐藏路径
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
	if (isShowMazePath) outtextxy(r.left + 5, r.top + 5, _T(" 隐藏路径"));
	else outtextxy(r.left + 5, r.top + 5, _T(" 显示路径"));
}
// 主函数
void main() {
	// 置随机数种子 
	srand(unsigned(time(NULL)));
	// 初始化设备，加载图片
	initgraph(WIN_WIDTH, WIN_HEIGHT);
	// 设置窗口标题
	SetWindowText(GetHWnd(), _T("Maze v0.9 By:ls9512"));
	cleardevice();
	// 设置黑色背景
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	// 开启双缓冲,防止闪屏
	BeginBatchDraw();
	// 鼠标消息变量
	MOUSEMSG mmsg;
	// 获取显存指针
	p_Screen = GetImageBuffer();
	// 创建迷宫
	CreateMaze();
	// 绘制一次到屏幕并复制到缓存
	OutputMaze();
	CopyScreenBuffer();
	// 主循环
	while (true)
	{
		//处理鼠标消息
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
		// 绘制，将缓存数据复制到屏幕提速
		DrawScreenBuffer();
		OutPutPath();
		DrawMenuItems();
		DrawFPS();
		// 显示缓存的绘制内容
		FlushBatchDraw();
		// 延迟,帧数控制
		Delay(13);
	}
	// 关闭
	EndBatchDraw();
	closegraph();
}

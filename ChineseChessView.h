// ChineseChessView.h : CChineseChessView 类的接口
//


#pragma once

#define MAX_PLY 4
#define VERSION "1.0"

#define SIZE_X 9
#define SIZE_Y 10
#define BOARD_SIZE SIZE_X*SIZE_Y

#define MOVE_STACK 4096
#define HIST_STACK 50

#define EMPTY 7
#define DARK 0
#define LIGHT 1

#define PAWN 0
#define BISHOP 1
#define ELEPHANT 2
#define KNIGHT 3
#define CANNON 4
#define ROOK 5
#define KING 6

#define INFINITY 20000
#define NORMAL 0
#define SELECT 1


typedef struct
{
	int from, dest;
} move;

typedef struct
{
	move m;
} gen_rec;

typedef struct
{
	move m;
	int capture;
} hist_rec;



class CChineseChessView : public CView
{
protected: // 仅从序列化创建
	CChineseChessView();
	DECLARE_DYNCREATE(CChineseChessView)

// 属性
public:
	CChineseChessDoc* GetDocument() const;
	
	CDC* pDCBoard;//board image
	CDC* pDCBack;//buffer
	CBitmap bmpBoard;
	CBitmap bmpBack;
	HICON hIcons[2][7];

	const static int lattice_len=34;
	const static int icon_len_half=16;
	const static int icon_len=32;
	const CPoint org;
	const CPoint boardButtomDown;
	

	bool isMouseDown;
	CPoint lastMousePoint;
	CPoint selectedPoint;
	CPoint pieceDragPoint;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CChineseChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	void UpdateDisplay(CRect&);
	CPoint NumToLogicPoint(int);
	CPoint LogicToPhysicPoint(CPoint);
	CPoint PhysicalToLogicPoint(CPoint );
	int LogicPointToNum(CPoint& p);
	void NewGame(bool);
	afx_msg void OnNewGame();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
};

#ifndef _DEBUG  // ChineseChessView.cpp 中的调试版本
inline CChineseChessDoc* CChineseChessView::GetDocument() const
   { return reinterpret_cast<CChineseChessDoc*>(m_pDocument); }
#endif


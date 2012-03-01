// ChineseChessDoc.cpp : CChineseChessDoc 类的实现
//

#include "stdafx.h"
#include "ChineseChess.h"

#include "ChineseChessDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChineseChessDoc

IMPLEMENT_DYNCREATE(CChineseChessDoc, CDocument)

BEGIN_MESSAGE_MAP(CChineseChessDoc, CDocument)
END_MESSAGE_MAP()


// CChineseChessDoc 构造/析构

CChineseChessDoc::CChineseChessDoc()
{
	// TODO: 在此添加一次性构造代码

}

CChineseChessDoc::~CChineseChessDoc()
{
}

BOOL CChineseChessDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CChineseChessDoc 序列化

void CChineseChessDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CChineseChessDoc 诊断

#ifdef _DEBUG
void CChineseChessDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CChineseChessDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CChineseChessDoc 命令

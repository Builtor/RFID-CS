// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问 
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// labView.cpp : ClabView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "lab.h"
#endif

#include "labDoc.h"
#include "labView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ClabView

IMPLEMENT_DYNCREATE(ClabView, CFormView)

BEGIN_MESSAGE_MAP(ClabView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ClabView 构造/析构

ClabView::ClabView()
	: CFormView(IDD_LAB_FORM)
{
	// TODO: 在此处添加构造代码

}

ClabView::~ClabView()
{
}

void ClabView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL ClabView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void ClabView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void ClabView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void ClabView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ClabView 诊断

#ifdef _DEBUG
void ClabView::AssertValid() const
{
	CFormView::AssertValid();
}

void ClabView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

ClabDoc* ClabView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ClabDoc)));
	return (ClabDoc*)m_pDocument;
}
#endif //_DEBUG


// ClabView 消息处理程序

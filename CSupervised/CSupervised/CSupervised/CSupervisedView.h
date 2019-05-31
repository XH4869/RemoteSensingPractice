
// CSupervisedView.h : CCSupervisedView 类的接口
//
#include <vector>
using namespace std;
#pragma once
typedef struct types {
	double b3, b4, b5;
}types;

class CCSupervisedView : public CView
{
protected: // 仅从序列化创建
	CCSupervisedView();
	DECLARE_DYNCREATE(CCSupervisedView)

// 特性
public:
	CCSupervisedDoc* GetDocument() const;

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
	virtual ~CCSupervisedView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_type;
	types type[5];
	vector<CPoint> pts;
	afx_msg void OnWater();
	afx_msg void OnPlant();
	afx_msg void OnCity();
	afx_msg void OnRoad();
	afx_msg void OnGround();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnCalculate();
	afx_msg void OnSupervised();
	int CountDist(int x, int y);
};

#ifndef _DEBUG  // CSupervisedView.cpp 中的调试版本
inline CCSupervisedDoc* CCSupervisedView::GetDocument() const
   { return reinterpret_cast<CCSupervisedDoc*>(m_pDocument); }
#endif


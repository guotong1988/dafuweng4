//Download by http://www.NewXing.com
// ToolManager.h: interface for the CToolManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLMANAGER_H__B272398F_79A2_4448_870C_E9EE2CB79954__INCLUDED_)
#define AFX_TOOLMANAGER_H__B272398F_79A2_4448_870C_E9EE2CB79954__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolManager  
{
public:
	CToolManager();
	virtual ~CToolManager();

	void DispatchMsg( CDC * pDC, UINT message, CPoint point = 0 );
	void Draw( CDC * pDC );
	bool IsOnMe( CPoint point );
	void SetActiveTool( CDC * pDC, const int ToolType, CEntity * pEntity);
	int ToolName( CPoint point );

private:
	CTool * m_pTool;
};

#endif // !defined(AFX_TOOLMANAGER_H__B272398F_79A2_4448_870C_E9EE2CB79954__INCLUDED_)

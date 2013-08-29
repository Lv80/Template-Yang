#pragma once

#include <list>

using namespace std;

//µã×ø±ê
struct Point3d
{
	double x;
	double y;
	double z;
};

//¾ØÐÎ
typedef struct _Rectangle
{
	double topLeft;
	double topRight;
	double bottomLeft;
	double bottomRight;
} Rect;

class CCircle
{
private:
	double m_dCenter;
	double m_dRadius;

public:
	CCircle( const double& rCenter, const double& rRadius ):
	  m_dCenter(rCenter),
		  m_dRadius(rRadius)
	  {}

	  ~CCircle(){}
};

typedef list<Point3d*> PointList;

class CCoornidateData
{
private:

	PointList *m_pCoordinateList;
	Rect m_Rect;
	CCircle m_Circle;

public:

	CCoornidateData():
	m_pCoordinateList( new list<Point3d*>() )
	{}

	size_t InsertCoornidate( const Point3d* newPoint );
	const PointList* GetCoornidateList() const { return m_pCoordinateList; }
};

class CTemplateData
{
public:

	enum DRAW_MODE {
		DRAW_SINGLE = 0,
		DRAW_MULTI
	};

	typedef enum _DRAW_TYPE {
		DRAW_NONE = 0,
		DRAW_LINE = 1,
		DRAW_RECT = 2,
		DRAW_CIRCLE = 4
	} DRAW_TYPE;

private:

	//Control Data
	DRAW_MODE m_EDrawMode;
	DRAW_TYPE m_EDrawType;

public:

	CTemplateData(void):
	  m_EDrawMode(DRAW_SINGLE),
	  m_EDrawType(DRAW_NONE)
	  {}

	~CTemplateData(void);
};


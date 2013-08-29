#pragma once

#include <list>
#include <fstream>

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
	CCircle() :
	  m_dCenter(0.0),
		  m_dRadius(0.0)
	  {}

	CCircle( const double& rCenter, const double& rRadius ):
	  m_dCenter(rCenter),
		  m_dRadius(rRadius)
	  {}

	  ~CCircle(){}

	  const double& GetCenter() const { return m_dCenter; }
	  const double& GetRadius() const { return m_dCenter; }

	  void SetCenter( const double& center ) { m_dCenter = center; }
	  void SetRadius( const double& radius ) { m_dRadius = radius; }
};

typedef list<Point3d*> PointList;
typedef PointList::iterator PointIter;

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

	~CCoornidateData()
	{
		for( PointIter iter =  m_pCoordinateList->begin(); 
			iter != m_pCoordinateList->end();
			iter++)
		{
			delete *iter;
		}

		m_pCoordinateList->clear();
		delete m_pCoordinateList;
		m_pCoordinateList = NULL;
	}

	size_t InsertCoornidate( const Point3d* newPoint );
	const PointList* GetCoornidateList() const { return m_pCoordinateList; }

	friend ifstream& operator>>( ifstream& stream, CCoornidateData& coornidateData);
	friend ofstream& operator<<( ofstream& stream, CCoornidateData& coornidateData);
};

class CTemplateData
{
public:

	enum DRAW_MODE {
		DRAW_SINGLE = 0,
		DRAW_MULTI = 1
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
	int m_EDrawType;
	CCoornidateData *m_pCoordinateData;

	static CTemplateData *instance;

private:

	CTemplateData(void):
	  m_EDrawMode(DRAW_SINGLE),
	  m_EDrawType(DRAW_NONE),
	  m_pCoordinateData( new CCoornidateData() )
	  {}

	~CTemplateData(void);

public:

	static CTemplateData* GetInstance();

	DRAW_MODE GetDrawMode() const { return m_EDrawMode; }
	int GetDrawType() const { return m_EDrawType; }
	CCoornidateData* GetCoornidate() const { return m_pCoordinateData; }

	void SetDrawMode( DRAW_MODE mode ) { m_EDrawMode = mode; }
	void SetDrawType( int type ) { m_EDrawType = type; }

	void Initialize( CString& prjPath );
	void Persistent( CString& file );
	void Persistent();

	friend ifstream& operator>>( ifstream& stream, CTemplateData& templateData);
	friend ofstream& operator<<( ofstream& stream, CTemplateData& templateData);

	CTemplateData& operator+(int offset);
	CTemplateData& operator-(int offset);
};

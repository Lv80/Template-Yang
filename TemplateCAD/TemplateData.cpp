#include "StdAfx.h"
#include "TemplateData.h"
#include <fstream>
#include <iostream>
#include "TemplateCAD.h"

using namespace std;

extern CTemplateCADApp theApp;

ifstream& operator>>( ifstream& stream, CCoornidateData& coornidateData)
{
	// coornidate line size
	size_t listSize = 0;
	stream >> listSize;

	for( int i = 0; i < (int)listSize; i++ )
	{
		Point3d *point = new Point3d();
		stream >> point->x >> point->y >> point->z;
		coornidateData.m_pCoordinateList->push_back( point );
	}

	// rectangle
	stream >> coornidateData.m_Rect.topLeft >> coornidateData.m_Rect.topRight
		>> coornidateData.m_Rect.bottomLeft >> coornidateData.m_Rect.bottomRight;

	double center(0.0), radius(0.0);

	stream >> center >> radius;

	coornidateData.m_Circle.SetCenter(center);
	coornidateData.m_Circle.SetRadius(radius);

	return stream;
}

ofstream& operator<<( ofstream& stream, CCoornidateData& coornidateData)
{
	// coornidate line size
	size_t listSize = coornidateData.m_pCoordinateList->size();
	stream << listSize << endl;

	for( PointIter iter =  coornidateData.m_pCoordinateList->begin(); 
			iter != coornidateData.m_pCoordinateList->end();
			iter++)
	{
		stream << (*iter)->x << (*iter)->y << (*iter)->z;
	}

	// rectangle
	stream << coornidateData.m_Rect.topLeft << coornidateData.m_Rect.topRight
		<< coornidateData.m_Rect.bottomLeft << coornidateData.m_Rect.bottomRight;

	stream << coornidateData.m_Circle.GetCenter()
		<< coornidateData.m_Circle.GetRadius();

	return stream;
}

CTemplateData* CTemplateData::instance = NULL;

CTemplateData::~CTemplateData(void)
{
	if( m_pCoordinateData )
		delete m_pCoordinateData;
}

void CTemplateData::Initialize( CString& prjPath )
{
	try
	{
		ifstream projectFile(prjPath.GetBuffer());
		projectFile >> (*this);
		projectFile.close();
	}
	catch(...)
	{
		cerr << "There is something wrong when initialized from the project file!" << endl;
	}
}

void CTemplateData::Persistent( CString& file )
{
	try
	{
		ofstream projectFile(file.GetBuffer());
		projectFile << (*this);
		projectFile.close();
	}
	catch(...)
	{
		cerr << "There is something wrong when initialized from the project file!" << endl;
	}
}

void CTemplateData::Persistent()
{
	Persistent( theApp.GetWorkingPrjFile() );
}

CTemplateData* CTemplateData::GetInstance()
{
	if( instance == NULL )
	{
		instance = new CTemplateData();
	}

	return instance;
}

ifstream& operator>>(ifstream& stream, CTemplateData& templateData)
{
	int mode = 0;
	stream >> mode;
	templateData.m_EDrawMode = (CTemplateData::DRAW_MODE)mode;

	stream >> templateData.m_EDrawType;

	stream >> (*templateData.m_pCoordinateData);

	return stream;
}

ofstream& operator<<( ofstream& stream, CTemplateData& templateData)
{
	stream << (int)templateData.m_EDrawMode;
	stream << templateData.m_EDrawType;
	stream << (*templateData.m_pCoordinateData);

	return stream;
}

CTemplateData& CTemplateData::operator+(int offset)
{
	return *this;
}

CTemplateData& CTemplateData::operator-(int offset)
{
	return *this;
}

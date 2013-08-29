#include "StdAfx.h"
#include "TemplateData.h"
#include <fstream>

using namespace std;

CTemplateData* CTemplateData::instance = NULL;

CTemplateData::~CTemplateData(void)
{
	if( m_pCoordinateData )
		delete m_pCoordinateData;
}

void CTemplateData::Initialize( CString& prjPath )
{
	ifstream projectFile(prjPath.GetBuffer());
	projectFile >> (*this);
}

void CTemplateData::Persistent( const CString& file )
{

}

void CTemplateData::Persistent()
{

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

	int type = 0;
	stream >> type;
	templateData.m_EDrawType = (CTemplateData::DRAW_TYPE)type;

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

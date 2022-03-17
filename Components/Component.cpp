#include "Component.h"

Component::Component(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	m_Label = "NoName";
	select = false; //by default
}

void Component::setID(int i)
{
	ID = i;
}

bool Component::getSelect()
{

	return select;
}

bool Component::InsideArea(int& x, int& y)
{
	if (x > m_GfxInfo.x1 && x<m_GfxInfo.x2 && y>m_GfxInfo.y1 && y < m_GfxInfo.y2)
		return true;
	else
		return false;
}

bool Component::InsideAreaConnection(int& x, int& y)
{
	if (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2)
		return true;
	else if (((x > m_GfxInfo.x1 && x < (m_GfxInfo.x1 + 1) || (x < m_GfxInfo.x1 && x >(m_GfxInfo.x1 + 1))) && y == m_GfxInfo.y1) || (x == (m_GfxInfo.x1 + 1) && (((y > m_GfxInfo.y1 && y < m_GfxInfo.y2)) || ((y < m_GfxInfo.y1 && y > m_GfxInfo.y2))) || (y == m_GfxInfo.y2 && ((x > (m_GfxInfo.x1 + 1) && x < m_GfxInfo.x2) || (x < (m_GfxInfo.x1 + 1) && x > m_GfxInfo.x2)))))
		return true;
	else if ((x == m_GfxInfo.x1 && ((y > m_GfxInfo.y1 && y < (m_GfxInfo.y1 + 1))) || (y < m_GfxInfo.y1 && y >(m_GfxInfo.y1 + 1))) || (y == (m_GfxInfo.y1 + 1) && ((x > m_GfxInfo.x1 && x < m_GfxInfo.x2)) || (x < m_GfxInfo.x1 && x > m_GfxInfo.x2)) || (x == m_GfxInfo.x2 && ((y < (m_GfxInfo.y1 + 1) && y > m_GfxInfo.y2) || (y > (m_GfxInfo.y1 + 1) && y < m_GfxInfo.y2))))
		return true;
	else
		return false;
}

void Component::setgraphicsinfo(GraphicsInfo&g1)
{
	m_GfxInfo = g1;
}

GraphicsInfo& Component::GetInfo()
{
	return m_GfxInfo;
}

int Component::GetID()
{
	return ID;
}

bool Component::IsmyID(int i)
{
	if (i == ID)
		return true;
	else
		return false;
}

int Component::getInPutCount()
{
	return InPutCount;
}

void Component::changeselect()
{
	if (select == true)
	{
		select = false;
	}
	else
		select = true;

}

void Component::setSelect(bool s)
{
	select = s;
}

void Component::setInPutCount(int c)
{
	InPutCount = c;
}

string Component::getLabel()
{
	return m_Label;
}

void Component::setLabel(string name)
{
	m_Label = name;
}


Component::Component()
{}

Component::~Component()
{}
int Component::counter = 0;


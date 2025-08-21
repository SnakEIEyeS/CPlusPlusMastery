#include "OctreeNode.h"

static const unsigned int maxPointsInOctreeNode = 10;

OctreeNode::OctreeNode()
{
}

OctreeNode::~OctreeNode()
{
}

OctreeNode::OctreeNode(const std::vector<Object*>& objectPtrArray)
{
	CalculateBoundingBox(objectPtrArray);
	LayoutOctreeNode(objectPtrArray);
}

OctreeNode::OctreeNode(const AABB& aabbArg) : m_aabb(aabbArg)
{
}

OctreeNode::OctreeNode(const Math::Vector3& minPos, const Math::Vector3& maxPos) : m_aabb(minPos, maxPos)
{
}

void OctreeNode::CalculateBoundingBox(const std::vector<Object*>& objectPtrArray)
{
	float minX = 999999.f;
	float minY = 999999.f;
	float minZ = 999999.f;
	float maxX = -999999.f;
	float maxY = -999999.f;
	float maxZ = -999999.f;

	for (auto it = objectPtrArray.begin(); it != objectPtrArray.end(); ++it)
	{
		Math::Vector3 objPosition = (*it)->GetPosition();
		if (objPosition.m_x < minX)
		{
			minX = objPosition.m_x;
		}
		else if (objPosition.m_x > maxX)
		{
			maxX = objPosition.m_x;
		}

		if (objPosition.m_y < minY)
		{
			minY = objPosition.m_y;
		}
		else if (objPosition.m_y > maxY)
		{
			maxY = objPosition.m_y;
		}

		if (objPosition.m_z < minZ)
		{
			minZ = objPosition.m_z;
		}
		else if (objPosition.m_z > maxZ)
		{
			maxZ = objPosition.m_z;
		}
	}

	m_aabb = AABB(Math::Vector3(minX, minY, minZ), Math::Vector3(maxX, maxY, maxZ));
}

void OctreeNode::LayoutOctreeNode(const std::vector<Object*>& objectPtrArray)
{
	if (objectPtrArray.size() <= maxPointsInOctreeNode)
	{
		m_objectPtrs.assign(objectPtrArray.begin(), objectPtrArray.end());
		return;
	}

	float minX = m_aabb.m_minPos.m_x;
	float minY = m_aabb.m_minPos.m_y;
	float minZ = m_aabb.m_minPos.m_z;
	float maxX = m_aabb.m_maxPos.m_x;
	float maxY = m_aabb.m_maxPos.m_y;
	float maxZ = m_aabb.m_maxPos.m_z;
	float halfMaxX = (m_aabb.m_minPos.m_x + m_aabb.m_maxPos.m_x) / 2.f;
	float halfMaxY = (m_aabb.m_minPos.m_y + m_aabb.m_maxPos.m_y) / 2.f;
	float halfMaxZ = (m_aabb.m_minPos.m_z + m_aabb.m_maxPos.m_z) / 2.f;

	m_backBottomLeft = new OctreeNode(m_aabb.m_minPos, Math::Vector3(halfMaxX, halfMaxY, halfMaxZ));
	m_backBottomRight = new OctreeNode(Math::Vector3(halfMaxX, minY, minZ), Math::Vector3(maxX, halfMaxY, halfMaxZ)); 

	m_backTopLeft = new OctreeNode(Math::Vector3(minX, halfMaxY, minZ), Math::Vector3(halfMaxX, maxY, halfMaxZ));
	m_backTopRight = new OctreeNode(Math::Vector3(halfMaxX , halfMaxY, minZ), Math::Vector3(maxX, maxY, halfMaxZ));

	m_frontBottomLeft = new OctreeNode(Math::Vector3(minX, minY, halfMaxZ), Math::Vector3(halfMaxX, halfMaxY, maxZ));
	m_frontBottomRight = new OctreeNode(Math::Vector3(halfMaxX, minY, halfMaxZ), Math::Vector3(maxX, halfMaxY, maxZ));

	m_frontTopLeft = new OctreeNode(Math::Vector3(minX, halfMaxY, halfMaxZ), Math::Vector3(halfMaxX, maxY, maxZ));
	m_frontTopRight = new OctreeNode(Math::Vector3(halfMaxX, halfMaxY, halfMaxZ), Math::Vector3(maxX, maxY, maxZ));
	
	std::vector<Object*> backbottomLeftObjs;
	std::vector<Object*> backbottomRightObjs;
	std::vector<Object*> backTopLeftObjs;
	std::vector<Object*> backTopRightObjs;
	std::vector<Object*> frontbottomLeftObjs;
	std::vector<Object*> frontbottomRightObjs;
	std::vector<Object*> frontTopLeftObjs;
	std::vector<Object*> frontTopRightObjs;
	for (auto it = objectPtrArray.begin(); it != objectPtrArray.end(); ++it)
	{
		Math::Vector3 objPosition = (*it)->GetPosition();
		if (m_backBottomLeft->m_aabb.ContainsPoint(objPosition))
		{
			backbottomLeftObjs.push_back(*it);
		}
		else if (m_backBottomRight->m_aabb.ContainsPoint(objPosition))
		{
			backbottomRightObjs.push_back(*it);
		}
		else if (m_backTopLeft->m_aabb.ContainsPoint(objPosition))
		{
			backTopLeftObjs.push_back(*it);
		}
		else if (m_backTopRight->m_aabb.ContainsPoint(objPosition))
		{
			backTopRightObjs.push_back(*it);
		}
		else if (m_frontBottomLeft->m_aabb.ContainsPoint(objPosition))
		{
			frontbottomLeftObjs.push_back(*it);
		}
		else if (m_frontBottomRight->m_aabb.ContainsPoint(objPosition))
		{
			frontbottomRightObjs.push_back(*it);
		}
		else if (m_frontTopLeft->m_aabb.ContainsPoint(objPosition))
		{
			frontTopLeftObjs.push_back(*it);
		}
		else if (m_frontTopRight->m_aabb.ContainsPoint(objPosition))
		{
			frontTopRightObjs.push_back(*it);
		}
	}

	m_backBottomLeft->LayoutOctreeNode(backbottomLeftObjs);
	m_backBottomRight->LayoutOctreeNode(backbottomRightObjs);
	m_backTopLeft->LayoutOctreeNode(backTopLeftObjs);
	m_backTopRight->LayoutOctreeNode(backTopRightObjs);

	m_frontBottomLeft->LayoutOctreeNode(frontbottomLeftObjs);
	m_frontBottomRight->LayoutOctreeNode(frontbottomRightObjs);
	m_frontTopLeft->LayoutOctreeNode(frontTopLeftObjs);
	m_frontTopRight->LayoutOctreeNode(frontTopRightObjs);
	
}

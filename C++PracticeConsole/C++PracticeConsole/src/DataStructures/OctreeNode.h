#pragma once

#include <vector>

#include "../DataStructures/Object.h"
#include "../BoundingVolumes/AABB.h"

class OctreeNode
{
public:
	OctreeNode();
	~OctreeNode();

	OctreeNode(const std::vector<Object*>& objectPtrArray);
	OctreeNode(const AABB& aabbArg);
	OctreeNode(const Math::Vector3& minPos, const Math::Vector3& maxPos);
	

private:
	void CalculateBoundingBox(const std::vector<Object*>& objectPtrArray);
	void LayoutOctreeNode(const std::vector<Object*>& objectPtrArray);

	AABB m_aabb;
	std::vector<Object*> m_objectPtrs;
	OctreeNode* m_backBottomLeft = nullptr;
	OctreeNode* m_backBottomRight = nullptr;
	OctreeNode* m_backTopLeft = nullptr;
	OctreeNode* m_backTopRight = nullptr;
	OctreeNode* m_frontBottomLeft = nullptr;
	OctreeNode* m_frontBottomRight = nullptr;
	OctreeNode* m_frontTopLeft = nullptr;
	OctreeNode* m_frontTopRight = nullptr;
};

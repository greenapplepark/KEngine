/*******************************
*
*	KEngine
*	KCore
*	KMemory.h
*	Created by Keke Xiang
*	2008/06/16
*
********************************/

#ifndef _KENGINE_KMEMORY_H_
#define _KENGINE_KMEMORY_H_

#include "KPlatform.h"

BEGIN_NAMESPACE_KCORE

class KMemory
{
public:
	typedef void* (*KAllocateFunc)(const KUINT size);
	typedef void* (*KDeallocateFunc)(void* p);
	typedef void* (*KReallocateFunc)(void* p, const KUINT size);
	typedef void* (*KAlignedAllocateFunc)(const KUINT size, const KUINT align);
	typedef void* (*KAlignedDeallocateFunc)(void* p);
	typedef void* (*KAlignedReallocateFunc)(void* p, const KUINT size, const KUINT alignn);

public:
	static void	SetAllocateFunc(const KAllocateFunc allocator);
	static void SetDeallocateFunc(const KDeallocateFunc dellocator);
	static void SetReallocateFunc(const KReallocateFunc rellocator);
	static void SetAlignedAllocateFunc(const KAlignedAllocateFunc allocator);
	static void SetAlignedDeallocateFunc(const KAlignedDeallocateFunc dellocator);
	static void SetAlignedReallocateFunc(const KAlignedReallocateFunc rellocator);

public:
	static void* Allocate(const KUINT size);
	static void Deallocate(void* p);
	static void* Reallocate(void* p, const KUINT size);
	static void* AlignedAllocate(const KUINT size, const KUINT align = 16);
	static void AlignedDeallocate(void* p);
	static void* AlignedReallocate(void* p, const KUINT size, const KUINT align = 16);

protected:
	static KAllocateFunc m_allocateFunc;
	static KDeallocateFunc m_deallocateFunc;
	static KReallocateFunc m_reallocateFunc;
	static KAlignedAllocateFunc m_alignedAllocateFunc;
	static KAlignedDeallocateFunc m_alignedDeallocateFunc;
	static KAlignedReallocateFunc m_alignedReallocateFunc;

private:
	KMemory();
};

template<typename T>
inline T* KAllocate(const KUINT n)
{
	return reinterpret_cast<T*>(KMemory::Allocate(n * sizeof(T)));
}

END_NAMESPACE_KCORE

#endif //_KENGINE_KMEMORY_H_
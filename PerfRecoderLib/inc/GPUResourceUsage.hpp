#pragma once
#include <vector>
#include <memory>

struct GPUsage
{
	std::string name;
	float gpuUsage;
	uint64_t totalMemory;
	uint64_t usedMemory;
};

class GPUResourceUsageBase
{
public:
	virtual std::vector<std::shared_ptr<GPUsage>> getUsages() = 0;
};

class GPUResourceUsage
{
	GPUResourceUsage();
public:
	~GPUResourceUsage();
	static GPUResourceUsage &getInstance();
	std::vector<std::shared_ptr<GPUsage>> getUsages();

private:
	std::vector<std::shared_ptr<GPUResourceUsageBase>> m_vendors;
};

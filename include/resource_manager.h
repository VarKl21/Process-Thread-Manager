#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
void track_resources_demo();
#include <map>
#include <string>

// Class to manage resource allocation tracking
class ResourceManager {
public:
	// Add a resource to the tracking system
	void allocateResource(const std::string& resourceName, int quantity);

	// Deallocate a resource
	void releaseResource(const std::string& resourceName, int quantity);
	void logResourceUsage();
	void track_resources_demo();   
	// Check the availability of a resource
	int checkResourceAvailability(const std::string& resourceName);

private:
	// Store the allocated resources with their quantities
	std::map<std::string, int> resources;
};

#endif // RESOURCE_MANAGER_H




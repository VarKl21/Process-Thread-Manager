#include "resource_manager.h"
#include <iostream>

// Allocate a resource by increasing its quantity
void ResourceManager::allocateResource(const std::string& resourceName, int quantity) {
    resources[resourceName] += quantity;
    std::cout << "Allocated " << quantity << " of " << resourceName << ".\n";
}

// Release a resource by decreasing its quantity
void ResourceManager::releaseResource(const std::string& resourceName, int quantity) {
    if (resources[resourceName] >= quantity) {
        resources[resourceName] -= quantity;
        std::cout << "Released " << quantity << " of " << resourceName << ".\n";
    } else {
        std::cout << "Not enough " << resourceName << " to release.\n";
    }
}

// Check how much of a specific resource is available
int ResourceManager::checkResourceAvailability(const std::string& resourceName) {
    return resources[resourceName];
}


#include "../include/resource_manager.h"
#include <iostream>
#include <map>
#include <string>
 
std::map<std::string, int> resources;
 
void ResourceManager::allocateResource(const std::string& resource, int quantity) {
  resources[resource] += quantity;
  std::cout << "Allocated " << quantity << " of " << resource << "." << std::endl;
}
 
void ResourceManager::releaseResource(const std::string& resource, int quantity) {
  if (resources.find(resource) != resources.end() && resources[resource] >= quantity) {
      resources[resource] -= quantity;
      std::cout << "Released " << quantity << " of " << resource << "." << std::endl;
  } else {
      std::cout << "Cannot release " << quantity << " of " << resource << ": Insufficient resource
s." << std::endl;
  }
}
 
void ResourceManager::logResourceUsage() {
  std::cout << "Current resource allocations:\n";
  for (const auto& [resource, quantity] : resources) {
      std::cout << resource << ": " << quantity << std::endl;
  }
}
void track_resources_demo() {
  std::cout << "Tracking resource allocations..." << std::endl;
  ResourceManager rm;
  rm.allocateResource("CPU", 5);
  rm.releaseResource("CPU", 2);
  rm.logResourceUsage();
}

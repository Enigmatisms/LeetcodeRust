#include <map>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

struct CompareFunctor {
    bool operator() (const std::string& s1, const std::string& s2) {
        return s1 < s2;
    }
};


int main() {
    int num_record = 0, num_services = 0;
    std::cin >> num_record;
    std::cin.get();
    std::map<std::string, std::unordered_map<std::string, int>, CompareFunctor> records;
    std::unordered_map<long long, std::unordered_map<std::string, std::unordered_set<std::string>>> accessed;
    for (int i = 0; i < num_record; i++) {
        std::string line, name, service;
        std::getline(std::cin, line);
        std::stringstream ss(line);

        std::getline(ss, line, ',');        // time_stamp
        long long time_stamp = atoll(line.c_str());
        std::getline(ss, name, ',');        
        std::getline(ss, service, ',');        
        std::getline(ss, line, ',');        // length
        int length = atoi(line.c_str());     
        
        if (length < 0 || length > 100) length = 0;
        if (accessed[time_stamp][name].count(service)) continue;
        accessed[time_stamp][name].emplace(service);
        records[name][service] += length;
    }
    std::cin >> num_services;
    std::cin.get();
    std::unordered_map<std::string, int> service_map;
    for (int i = 0; i < num_services; i++) {
        std::string service, line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::getline(ss, service, ',');        // service
        std::getline(ss, line, ',');           // service
        int cost = atoi(line.c_str());
        service_map[service] = cost;
    }
    for (auto it = records.begin(); it != records.end(); it++) {
        int total_fee = 0;
        for (auto key_val = it->second.begin(); key_val != it->second.end(); key_val ++) {
            int cost = 0;
            auto cost_it = service_map.find(key_val->first);
            if (cost_it != service_map.end())
                cost = cost_it->second;
            total_fee += cost * key_val->second;
        }
        std::cout << it->first << "," << total_fee << std::endl;
    }
    return 0;
}

 
#include <iostream> 
#include <vector> 
#include <sstream> 
#include <bitset> 
using namespace std; 
vector<int> parseIP(const string& ip) { 
vector<int> parts; 
stringstream ss(ip); 
string segment; 
while (getline(ss, segment, '.')) { 
parts.push_back(stoi(segment)); 
} 
return parts; 
} 
vector<int> calculateNetworkAddress(const vector<int>& ip, const vector<int>& mask) { 
vector<int> network(4); 
for (int i = 0; i < 4; i++) { 
network[i] = ip[i] & mask[i]; 
} 
return network; 
} 
vector<int> calculateBroadcastAddress(const vector<int>& network, const vector<int>& mask) 
{ 
vector<int> broadcast(4); 
for (int i = 0; i < 4; i++) { 
broadcast[i] = network[i] | (~mask[i] & 0xFF); 
} 
return broadcast; 
} 
void displayAddress(const string& label, const vector<int>& address) { 
cout << label << ": "; 
for (int i = 0; i < 4; i++) { 
cout << address[i]; 
if (i < 3) cout << "."; 
} 
cout << endl; 
} 
int main() { 
string ipAddress, subnetMask; 
cout << "Enter IP Address (e.g., 192.168.1.1): "; 
cin >> ipAddress; 
cout << "Enter Subnet Mask (e.g., 255.255.255.0): "; 
cin >> subnetMask; 
vector<int> ip = parseIP(ipAddress); 
vector<int> mask = parseIP(subnetMask); 
vector<int> networkAddress = calculateNetworkAddress(ip, mask); 
vector<int> broadcastAddress = calculateBroadcastAddress(networkAddress, mask); 
displayAddress("Network Address", networkAddress); 
displayAddress("Broadcast Address", broadcastAddress); 
cout << "Usable IP Range: "; 
for (int i = 0; i < 3; i++) cout << networkAddress[i] << "."; 
cout << networkAddress[3] + 1 << " - "; 
for (int i = 0; i < 3; i++) cout << broadcastAddress[i] << "."; 
cout << broadcastAddress[3] - 1 << endl; 
return 0; 
}   




// Example Run:
// Enter IP Address (e.g., 192.168.1.1): 192.168.1.1
// Enter Subnet Mask (e.g., 255.255.255.0): 255.255.255.0
// Network Address: 192.168.1.0
// Broadcast Address: 192.168.1.255
// Usable IP Range: 192.168.1.1 - 192.168.1.254
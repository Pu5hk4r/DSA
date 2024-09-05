#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int binaryToDecimal(const string& s) {
    // Validate the input binary string
    for (char c : s) {
        if (c != '0' && c != '1') {
            cerr << "Invalid binary string: " << s << endl;
            return -1; // Return an error code or handle as needed
        }
    }

    // Use a bitset with a size large enough to handle the input string
    std::bitset<64> number(s);
    
    return number.to_ulong();
}

int main() {
    string binaryStr = "1101"; // Example binary string
    int decimalValue = binaryToDecimal(binaryStr);
    if (decimalValue != -1) {
        cout << "Binary string " << binaryStr << " is " << decimalValue << " in decimal." << endl;
    }

    return 0;
}

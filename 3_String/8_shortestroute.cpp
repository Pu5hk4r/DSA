#include <iostream>
using namespace std;

int main() {
    char route[1000];
    cin.getline(route, 1000);

    int x = 0, y = 0;

    // Process the route and update coordinates
    for (int i = 0; route[i] != '\0'; ++i) {
        switch (route[i]) {
            case 'N': ++y; break;
            case 'S': --y; break;
            case 'E': ++x; break;
            case 'W': --x; break;
        }
    }

    // Output final coordinates
    cout << "Final x and y is " << x << "," << y << "." << endl;

    // Generate the shortest path back to origin
    if (x > 0) {
        while (x--) cout << "W";
    } else {
        while (x++) cout << "E";
    }

    if (y > 0) {
        while (y--) cout << "S";
    } else {
        while (y++) cout << "N";
    }

    return 0;
}

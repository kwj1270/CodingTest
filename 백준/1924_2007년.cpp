#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int m, d;
    cin >> m >> d;
    
    for (int i=0; i < m; i++) {
        d += month[i];
    }
    
    cout << day[d%7] << "\n";
    
    return 0;
}


